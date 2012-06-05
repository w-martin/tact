/**
 * @file PunctuationFilter.cpp
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

#include "mewt/input/corpus/feature/FeatureCorpus.h"
#include "mewt/input/pipe/PunctuationFilter.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/regex.hpp>

#include <iostream>

PunctuationFilter::PunctuationFilter() : Pipe(DOCUMENT_TYPE_FEATURE) {
}

PunctuationFilter::~PunctuationFilter() {
}

auto_ptr< Corpus > PunctuationFilter::process(auto_ptr<Corpus> corpus) const {
    FeatureCorpus * const featureCorpus = (FeatureCorpus*) corpus.get();
    Alphabet * const alphabet = featureCorpus->getAlphabet();
    vector< string > const terms(*alphabet->getTerms());
    for (vector< string >::const_iterator iter = terms.begin();
            terms.end() != iter; iter++) {
        string const term = (*iter);
        if (containsPunctuation(term)) {
            vector< string > const transformed = removePunctuation(term);
            featureCorpus->replaceTerm(term, transformed);
        }
    }
    return corpus;
}

bool const PunctuationFilter::containsPunctuation(string const & term) {
    boost::regex test(".*\\W+.*", boost::regex::perl);
    return boost::regex_match(term.begin(), term.end(), test);
}

vector< string > const PunctuationFilter::removePunctuation(
        string const & term) {
    vector< string > terms;
    boost::split(terms, term, boost::is_any_of("'"));
    string fusedTerm = "";
    for (vector< string >::const_iterator iter = terms.begin();
            terms.end() != iter; iter++) {
        fusedTerm.append(*iter);
    }
    terms.clear();
    boost::regex re("\\W");
    boost::algorithm::split_regex(terms, fusedTerm, re);

    vector< string >::iterator iter = terms.begin();
    while (terms.end() != iter) {
        if (0 == (*iter).size()) {
            iter = terms.erase(iter);
        } else {
            iter++;
        }
    }
    return terms;
}
