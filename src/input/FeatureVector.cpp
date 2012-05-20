/**
 * @file FeatureVector.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#include "mewt/input/FeatureVector.h"

FeatureVector::FeatureVector(auto_ptr<Alphabet> alphabet,
        auto_ptr<vector<int> > features) {
    FeatureVector::alphabet = alphabet;
    FeatureVector::features = features;
}

FeatureVector::FeatureVector(const FeatureVector& orig) {
    FeatureVector::alphabet = auto_ptr<Alphabet > (
            new Alphabet(*orig.getAlphabet()));
    FeatureVector::features = auto_ptr<vector<int> >(
            new vector<int>(*orig.getFeatures()));
}

FeatureVector::~FeatureVector() {
}

Alphabet const * const FeatureVector::getAlphabet() const {
    return alphabet.get();
}

vector<int> const * const FeatureVector::getFeatures() const {
    return features.get();
}

int const FeatureVector::getSize() const {
    return features->size();
}
