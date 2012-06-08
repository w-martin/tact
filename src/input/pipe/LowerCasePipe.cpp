/**
 * @file LowerCasePipe.cpp
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

#include "mewt/input/pipe/LowerCasePipe.h"
#include "mewt/input/corpus/feature/Alphabet.h"
#include "mewt/input/corpus/feature/FeatureCorpus.h"
#include "mewt/input/corpus/text/TextDocument.h"
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

using std::map;

typedef map< string, vector< string > > mapType;

LowerCasePipe::LowerCasePipe() : Pipe(DOCUMENT_TYPE_FEATURE) {
}

LowerCasePipe::~LowerCasePipe() {
}

auto_ptr< Corpus > LowerCasePipe::process(
        auto_ptr< Corpus > corpus) const {
    FeatureCorpus * const featureCorpus = (FeatureCorpus*) corpus.get();
    Alphabet * const alphabet = featureCorpus->getAlphabet();
    mapType termsToReplace;
    for (AlphabetIterator iter = alphabet->begin();
            alphabet->end() != iter; iter++) {
        string const term = iter.getTerm();
        if (containsUpperCase(term)) {
            vector< string > transformed;
            transformed.push_back(toLowerCase(term));
            termsToReplace.insert(std::make_pair(term, transformed));
        }
    }
    for (mapType::const_iterator iter = termsToReplace.begin();
            termsToReplace.end() != iter; iter++) {
        featureCorpus->replaceTerm((*iter).first, (*iter).second);
    }
    return corpus;
}

bool const LowerCasePipe::containsUpperCase(string const & term) {
    boost::regex test(".*[A-Z]+.*", boost::regex::perl);
    return boost::regex_match(term.begin(), term.end(), test);
}

string const LowerCasePipe::toLowerCase(string const & originalTerm) {
    string transformed = originalTerm;
    boost::algorithm::to_lower(transformed);
    return transformed;
}

