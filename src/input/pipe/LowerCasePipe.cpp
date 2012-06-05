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
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

LowerCasePipe::LowerCasePipe() : Pipe(DOCUMENT_TYPE_FEATURE) {
}

LowerCasePipe::~LowerCasePipe() {
}

auto_ptr< Corpus > LowerCasePipe::process(
        auto_ptr< Corpus > corpus) const {
    FeatureCorpus * const featureCorpus = (FeatureCorpus*) corpus.get();
    Alphabet * const alphabet = featureCorpus->getAlphabet();
    vector< string > const * const terms = alphabet->getTerms();
    for (int i = 0; i < terms->size(); i++) {
        string const term = terms->at(i);
        if (containsUpperCase(term)) {
            vector< string > transformed;
            transformed.push_back(toLowerCase(term));
            featureCorpus->replaceTerm(term, transformed);
        }
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

