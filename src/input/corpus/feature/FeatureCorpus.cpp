/**
 * @file FeatureCorpus.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#include "mewt/input/corpus/feature/FeatureCorpus.h"

FeatureCorpus::FeatureCorpus(const string location,
        auto_ptr<Alphabet> alphabet)
: Corpus(location, DOCUMENT_TYPE_FEATURE) {
    FeatureCorpus::alphabet = alphabet;
}

FeatureCorpus::FeatureCorpus(const FeatureCorpus& orig)
: Corpus(orig) {
    alphabet = auto_ptr< Alphabet > (new Alphabet(*orig.getAlphabet()));
}

FeatureCorpus::~FeatureCorpus() {
}

Alphabet const * const FeatureCorpus::getAlphabet() const {
    return alphabet.get();
}
