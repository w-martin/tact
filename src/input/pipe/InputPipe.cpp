/**
 * @file InputPipe.cpp
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

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#define SEPARATOR "/"

#include "mewt/input/corpus/text/TextCorpus.h"
#include "mewt/input/pipe/InputPipe.h"

#include <memory>
#include <fstream>
#include <streambuf>

using std::ifstream;
using std::ios;
using std::istreambuf_iterator;

InputPipe::InputPipe() {
}

InputPipe::~InputPipe() {
}

auto_ptr< Corpus > InputPipe::process(
        auto_ptr<Corpus> originalCorpus) const {

    string const location = originalCorpus->getLocation();
    vector< Document * > const * const originalDocuments =
            originalCorpus->getDocuments();
    auto_ptr< TextCorpus > corpus =
            auto_ptr< TextCorpus > (new TextCorpus(location));

    for (vector< Document * >::const_iterator iter = originalDocuments->begin();
            originalDocuments->end() != iter; iter++) {

        string const name = (*iter)->getName();
        string filename = computeFileName(originalCorpus->getLocation(),
                name);
        auto_ptr< string > text = readFileIntoString(filename);

        auto_ptr< Document > doc = auto_ptr< Document > (
                new TextDocument(name, text));
        corpus->addDocument(doc);

    }
    return (auto_ptr< Corpus >) corpus;
}

string const InputPipe::computeFileName(const string & location,
        const string & name) {
    return string(location).append(SEPARATOR). append(name);
}

auto_ptr< string > InputPipe::readFileIntoString(const string & location) {
    ifstream t(location.c_str());
    auto_ptr< string > text = auto_ptr< string > (new string());

    t.seekg(0, ios::end);
    int const length = t.tellg();
    t.seekg(0, ios::beg);

    text->reserve(length);
    text->assign(istreambuf_iterator< char >(t), istreambuf_iterator< char >());

    return text;
}
