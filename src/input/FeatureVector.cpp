/**
 * @file FeatureVector.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/input/FeatureVector.h"

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

int * const FeatureVector::getFeatures() const {
    return features;
}

int const FeatureVector::getSize() const {
    return features->size();
}
