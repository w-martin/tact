/**
 * @file LengthFilter.cpp
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

#include "mewt/input/pipe/LengthFilter.h"
#include "mewt/input/corpus/feature/FeatureCorpus.h"

using namespace mewt::input::pipe;

LengthFilter::LengthFilter(const int minimumLength)
: Pipe(DOCUMENT_TYPE_FEATURE) {
  LengthFilter::minimumLength = minimumLength;
}

LengthFilter::~LengthFilter() {
}

auto_ptr< Corpus > LengthFilter::process(auto_ptr<Corpus> corpus) const {
  FeatureCorpus * const featureCorpus = (FeatureCorpus*) corpus.get();
  Alphabet * const alphabet = featureCorpus->getAlphabet();
  vector< string > termsToReplace;
  for (AlphabetIterator iter = alphabet->begin();
          alphabet->end() != iter; iter++) {
    string const term = iter.getTerm();
    if (minimumLength > term.size()) {
      termsToReplace.push_back(term);
    }
  }
  for (vector< string >::const_iterator iter = termsToReplace.begin();
          termsToReplace.end() != iter; iter++) {
    featureCorpus->replaceTerm(*iter, vector< string > ());
  }
  return corpus;
}

int const LengthFilter::getMinimumLength() const {
  return minimumLength;
}
