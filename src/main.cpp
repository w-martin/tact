/**
 * @file main.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.0
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
 * @section DESCRIPTION
 *
 * This is the main entry point at runtime.
 * 
 */

#include "mewt/input/pipe/bundle/CompleteFilteredBundle.h"
#include "mewt/input/corpus/feature/FeatureCorpusIO.h"
#include "mewt/util/Strings.h"
#include "mewt/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include <iostream>

namespace strings = mewt::util::strings;

using std::cout;
using std::endl;

namespace {

    /**
     * Enumeration of possible operation modes.
     * 
     */
    enum OperationMode {
        CLEAR,
        INVALID,
        MODELLING,
        PREPROCESSING
    };

    /**
     * Clears the cache of any saved corpora.
     * 
     */
    void clear() {
        FeatureCorpusIO::clearCache();
    }

    /**
     * Parses the given string to get the operation mode.
     * 
     * @param mode the string to parse.
     * @return the operation mode.
     * 
     */
    OperationMode getOperationMode(string const & mode) {
        if (strings::matches(mode, "-c")) {
            return CLEAR;
        } else if (strings::matches(mode, "-m")) {
            return MODELLING;
        } else if (strings::matches(mode, "-p")) {
            return PREPROCESSING;
        } else {
            return INVALID;
        }
    }

    /**
     * Pre-processes the corpus with given location.
     * 
     * @param corpusLocation the location of the corpus.
     * 
     */
    void preprocess(string const & corpusLocation) {
        auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                new Corpus(corpusLocation, DOCUMENT_TYPE_BASIC));
        corpus = ScanInputOptimiseBundle().pipe(corpus);
        FeatureCorpusIO::save((FeatureCorpus *) corpus.get());
    }

    /**
     * Pre-processes the corpus with given location.
     * 
     * @param corpusLocation the location of the corpus.
     * @param stopwordsFile the location of the stop-words file, or NULL if
     * none is to be used.
     * 
     */
    void preprocess(string const & corpusLocation,
            string const & stopwordsFile) {
        auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                new Corpus(corpusLocation, DOCUMENT_TYPE_BASIC));
        corpus = CompleteFilteredBundle(stopwordsFile). pipe(corpus);
        FeatureCorpusIO::save((FeatureCorpus *) corpus.get());
    }

    /**
     * Prints the usage instructions.
     * 
     */
    void printUsage() {
        cout << "Usage: mewt <mode> <arguments>"
                << endl;
        cout << "  Modes:" << endl;
        cout << "    -c" << endl;
        cout << "        Clears any saved corpora." << endl;
        cout << "    -p <corpus directory> <optional stopwords file>" << endl;
        cout << "        Pre process corpus and save it for later." << endl;
        cout << "    -m <output directory> <input mode> <input arguments>"
                << endl;
        cout << "        Model the corpus and save results to the given " <<
                "directory." << endl;
        cout << "  Input modes:" << endl;
        cout << "    -l <corpus directory>" << endl;
        cout << "        Loads a pre-processed corpus that had the given " <<
                "location at the time it was processed." << endl;
        cout << "    -i <corpus directory> <optional stopwords file>" << endl;
        cout << "        Processes the given corpus and uses it as input."
                << endl;
        cout << "Examples:" << endl;
        cout << "  mewt -p myCorpus/" << "; mewt -m output/ -l myCorpus/"
                << endl;
        cout << "  mewt -m output -i myCorpus" << endl;
    }
}

/**
 * Main entry point for the program.
 * 
 * @param argc number of arguments.
 * @param argv string arguments from <code>stdin</code>.
 * 
 */
int main(int argc, char** argv) {
    if (2 > argc) {
        printUsage();
        return 1;
    } else {
        OperationMode mode = getOperationMode(argv[1]);
        cout << "Operation mode: ";
        switch (mode) {
            case CLEAR:
                clear();
                break;
            case INVALID:
                cout << "Invalid. Exiting." << endl;
                return 1;
            case MODELLING:
                cout << "Modelling." << endl;
                break;
            case PREPROCESSING:
                cout << "Preprocessing." << endl;
                if (3 > argc) {
                    cout << "Error. Insufficient arguments." << endl;
                    return 1;
                }
                if (4 <= argc) {
                    preprocess(argv[2], argv[3]);
                } else {
                    preprocess(argv[2]);
                }
                break;
        }
        return 0;
    }
}
