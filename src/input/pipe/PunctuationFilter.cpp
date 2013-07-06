/**
 * @file PunctuationFilter.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "tact/input/corpus/feature/FeatureCorpus.h"
#include "tact/input/pipe/PunctuationFilter.h"
#include "tact/util/Strings.h"
#include <map>

using tact::util::strings::containsPunctuation;
using tact::util::strings::split;
using std::map;

typedef map< string, vector< string > > mapType;

PunctuationFilter::PunctuationFilter() : Pipe(DOCUMENT_TYPE_FEATURE) {
}

PunctuationFilter::~PunctuationFilter() {
}

auto_ptr< Corpus > PunctuationFilter::process(auto_ptr<Corpus> corpus) const {
  FeatureCorpus * const featureCorpus = (FeatureCorpus*) corpus.get();
  Alphabet * const alphabet = featureCorpus->getAlphabet();
  mapType termsToReplace;
  for (AlphabetIterator iter = alphabet->begin();
       alphabet->end() != iter; iter++) {
    string const term = iter.getTerm();
    if (containsPunctuation(term)) {
      vector< string > const transformed = removePunctuation(term);
      termsToReplace.insert(std::make_pair(term, transformed));
    }
  }
  for (mapType::const_iterator iter = termsToReplace.begin();
       termsToReplace.end() != iter; iter++) {
    featureCorpus->replaceTerm((*iter).first, (*iter).second);
  }
  return corpus;
}

vector< string > const PunctuationFilter::removePunctuation(
  string const & term) {
  auto_ptr< vector< string > > terms = split(term, "'");
  string fusedTerm = "";
  for (vector< string >::const_iterator iter = terms->begin();
       terms->end() != iter; iter++) {
    fusedTerm.append(*iter);
  }
  terms = split(fusedTerm, "\\W");
  return *terms.release();
}
