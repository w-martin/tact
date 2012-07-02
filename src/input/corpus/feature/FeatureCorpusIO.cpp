/**
 * @file FeatureCorpusIO.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/corpus/feature/FeatureCorpusIO.h"
#include "mewt/util/Files.h"
#include "mewt/util/Strings.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
namespace files = mewt::util::files;
namespace strings = mewt::util::strings;

using std::endl;
using std::max;
using std::ofstream;
using std::stringstream;
using namespace FeatureCorpusIO;
using namespace FeatureCorpusIO::util;

void FeatureCorpusIO::clearCache() {
    fs::remove_all(IO_CACHE);
}

void FeatureCorpusIO::deleteCorpus(string const & location)
throw (CorpusNotFoundException) {
    string const savedLocation = findSavedCorpus(location);
    fs::remove_all(savedLocation);
}

auto_ptr< FeatureCorpus > FeatureCorpusIO::load(string const & location)
throw (CorpusNotFoundException) {
    string const directory = findSavedCorpus(location);
    try {
        auto_ptr< Alphabet > alphabet = loadAlphabet(directory);
        auto_ptr< FeatureCorpus > corpus(new FeatureCorpus(location, alphabet));
        loadDocuments(directory, corpus->getAlphabet(), corpus.get());
        return corpus;
    } catch (FileNotFoundException const &) {
        throw CorpusNotFoundException();
    }
}

void FeatureCorpusIO::save(FeatureCorpus const * const corpus) {
    try {
        deleteCorpus(corpus->getLocation());
    } catch (CorpusNotFoundException const &) {
    }
    string const directory = findNextFreeDirectory();
    fs::create_directories(directory);
    saveInfoFile(directory, corpus);
    saveAlphabet(directory, corpus->getAlphabet());
    saveDocuments(directory, corpus->getDocuments());
}

string const FeatureCorpusIO::util::createDirectory(
        string const & directory, int const & directoryNumber) {
    stringstream dirName;
    dirName << directory << "/" << (1 > (directoryNumber / 10) ? "0" : "")
            << directoryNumber << "/";
    fs::create_directories(dirName.str());
    return dirName.str();
}

string const FeatureCorpusIO::util::findNextFreeDirectory() {
    if (fs::exists(IO_CACHE)) {
        int nextDirectory = 0;
        for (fs::directory_iterator end, dir(IO_CACHE);
                dir != end; ++dir) {
            string location = (* dir).path().generic_string();
            location = strings::replace(location, IO_CACHE, "");
            try {
                nextDirectory = max(strings::toInteger(location) + 1,
                        nextDirectory);
            } catch (BadCastException const &) {
            }
        }
        stringstream result;
        result << string(IO_CACHE);
        if (1 > (nextDirectory / 10)) {
            result << "0";
        }
        result << nextDirectory << "/";
        return result.str();
    } else {
        return string(IO_CACHE) + "00/";
    }
}

string const FeatureCorpusIO::util::findSavedCorpus(string const & location)
throw (CorpusNotFoundException) {
    if (fs::is_directory(IO_CACHE)) {
        for (fs::directory_iterator end, dir(IO_CACHE);
                dir != end; ++dir) {
            string const dirName = (* dir).path().generic_string();
            try {
                if (loadName(dirName) == location) {
                    return dirName;
                }
            } catch (FileNotFoundException const &) {
            }
        }
    }
    throw CorpusNotFoundException(location, false);
}

auto_ptr< Alphabet > FeatureCorpusIO::util::loadAlphabet(
        string const & directory)
throw (FileNotFoundException, DuplicateException) {
    string const alphabetLocation = directory + "/" + IO_CORPUS_ALPHABET;
    if (fs::is_regular_file(alphabetLocation)) {
        auto_ptr< Alphabet > alphabet(new Alphabet());
        auto_ptr< string > text = files::readFile(alphabetLocation);
        auto_ptr< vector< string > > lines, tokens;
        lines = strings::splitLines(*text.get());
        delete text.release();
        for (vector< string >::const_iterator iter = lines->begin();
                lines->end() != iter; iter++) {
            tokens = strings::split(*iter, "=");
            if (2 == tokens->size()) {
                try {
                    alphabet->addTerm(
                            tokens->at(0), strings::toInteger(tokens->at(1)));
                } catch (BadCastException const &) {
                }
            }
        }
        return alphabet;
    } else {
        throw FileNotFoundException(alphabetLocation, false);
    }
}

auto_ptr< FeatureDocument > FeatureCorpusIO::util::loadDocument(
        string const & fileName, Alphabet const * const alphabet)
throw (FileNotFoundException, TermNotPresentException) {
    if (!fs::is_regular_file(fileName)) {
        throw (FileNotFoundException(fileName, false));
    }
    auto_ptr< string > text = files::readFile(fileName);
    auto_ptr< vector< string > > lines, tokens;
    lines = strings::splitLines(*text.get());
    delete text.release();
    string name;
    auto_ptr< FeatureMap > featureMap =
            auto_ptr< FeatureMap > (new FeatureMap());
    int feature, count;

    for (vector< string >::const_iterator iter = lines->begin();
            lines->end() != iter; iter++) {
        tokens = strings::split(*iter, "=");
        if (2 == tokens->size()) {

            try {
                feature = strings::toInteger(tokens->at(0));
                if (!alphabet->hasIndex(feature)) {
                    throw TermNotPresentException();
                }
                count = strings::toInteger(tokens->at(1));
                featureMap->setFeature(feature, count);

            } catch (BadCastException const &) {
                if (strings::matches(tokens->at(0), "^name")) {
                    name = tokens->at(1);
                }
            }
        }
    }

    auto_ptr< FeatureDocument > document = auto_ptr< FeatureDocument > (
            new FeatureDocument(name, featureMap));
    return document;
}

void FeatureCorpusIO::util::loadDocuments(string const & directory,
        Alphabet const * const alphabet, FeatureCorpus * const corpus)
throw (TermNotPresentException) {
    string const location = directory + "/" + IO_CORPUS_DOCUMENTS;
    if (fs::is_directory(location)) {
        loadDocumentsFromDirectory(location, alphabet, corpus);
    }
}

void FeatureCorpusIO::util::loadDocumentsFromDirectory(
        string const & directory, Alphabet const * const alphabet,
        FeatureCorpus * const corpus)
throw (TermNotPresentException) {
    auto_ptr< vector< auto_ptr< FeatureDocument > > > documents(
            new vector< auto_ptr< FeatureDocument > >());
    string location;
    for (fs::directory_iterator end, iter(directory);
            iter != end; ++iter) {
        location = (*iter).path().generic_string();
        if (fs::is_directory(location)) {
            loadDocumentsFromDirectory(location, alphabet, corpus);
        } else {
            auto_ptr< FeatureDocument > document =
                    loadDocument(location, alphabet);
            corpus->addDocument((auto_ptr< Document >) document);
        }
    }
}

string const FeatureCorpusIO::util::loadName(string const & directory)
throw (FileNotFoundException) {
    string const infoFileLocation = directory + "/" + IO_CORPUS_INFO;
    if (fs::is_regular_file(infoFileLocation)) {
        auto_ptr< string > text = files::readFile(infoFileLocation);
        auto_ptr< vector< string > > lines = strings::splitLines(*text);
        string line;
        for (vector< string >::const_iterator iter = lines->begin();
                lines->end() != iter; iter++) {
            line = *iter;
            if (strings::matches(line, "^name=.*")) {
                return strings::replace(line, "name=", "");
            }
        }
        return "";
    } else {
        throw FileNotFoundException(infoFileLocation, false);
    }
}

void FeatureCorpusIO::util::saveAlphabet(string const & directory,
        Alphabet const * const alphabet) {
    string const alphabetLocation = directory + "/" + IO_CORPUS_ALPHABET;
    ofstream alphabetFile(alphabetLocation.c_str());
    for (AlphabetIterator iter = alphabet->begin();
            alphabet->end() != iter; iter++) {
        alphabetFile << iter.getTerm() << "=" << iter.getIndex() << endl;
    }
    alphabetFile.close();
}

void FeatureCorpusIO::util::saveDocument(
        string const & directory, int const & n,
        FeatureDocument const * const document) {
    stringstream sstream;
    sstream << directory << "/" << (1 > (n / 10) ? "0" : "") << n;
    ofstream file(sstream.str().c_str());
    file << "name=" << document->getName() << endl;

    FeatureMap const * const featureMap = document->getFeatureMap();
    for (FeatureMapIterator iter = featureMap->begin();
            featureMap->end() != iter; iter++) {
        file << iter.getFeature() << "=" << iter.getCount() << endl;
    }
    file.close();
}

void FeatureCorpusIO::util::saveDocuments(
        string const & directory, vector< Document * > const * const documents)
throw (IncompatibleCorpusException) {
    int n = 0, d = 0;
    string const documentsLocation = directory + "/" + IO_CORPUS_DOCUMENTS;
    string dirName = createDirectory(documentsLocation, d);
    for (vector< Document * >::const_iterator iter = documents->begin();
            documents->end() != iter; iter++) {
        if (DOCUMENT_TYPE_FEATURE != (*iter)->getType()) {
            throw IncompatibleCorpusException((*iter)->getType(),
                    DOCUMENT_TYPE_FEATURE);
        }
        saveDocument(dirName, n, (FeatureDocument *) * iter);
        if (99 == ++n) {
            n = 0;
            dirName = createDirectory(documentsLocation, ++d);
        }
    }
}

void FeatureCorpusIO::util::saveInfoFile(
        string const & directory, FeatureCorpus const * corpus) {
    string const infoFileLocation = directory + "/" + IO_CORPUS_INFO;
    ofstream infoFile(infoFileLocation.c_str());
    infoFile << "name=" << corpus->getLocation() << endl;
    infoFile.close();
}
