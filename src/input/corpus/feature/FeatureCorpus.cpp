/**
 * @file FeatureCorpus.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "teflon/input/corpus/feature/FeatureCorpus.h"

FeatureCorpus::FeatureCorpus(const string location,
        auto_ptr<Alphabet> alphabet)
: Corpus(location, DOCUMENT_TYPE_FEATURE) {
    FeatureCorpus::alphabet = alphabet.release();
}

FeatureCorpus::~FeatureCorpus() {
    delete alphabet;
}

Alphabet * const FeatureCorpus::getAlphabet() const {
    return alphabet;
}

void FeatureCorpus::replaceTerm(string const & originalTerm,
        vector<string> const & terms) throw (TermNotPresentException) {
    int const originalIndex = alphabet->removeTerm(originalTerm);
    vector< int > replacementIndices;
    for (vector< string >::const_iterator iter = terms.begin();
            terms.end() != iter; iter++) {
        replacementIndices.push_back(alphabet->addTerm(*iter));
    }
    for (vector< Document * >::const_iterator iter = getDocuments()->begin();
            getDocuments()->end() != iter; iter++) {
        FeatureMap * const featureMap =
                ((FeatureDocument *) (* iter))->getFeatureMap();
        int const count = featureMap->getFeature(originalIndex);
        if (0 < count) {
            featureMap->removeFeature(originalIndex);
            for (vector< int >::const_iterator indexIter =
                    replacementIndices.begin();
                    replacementIndices.end() != indexIter; indexIter++) {
                featureMap->incrementFeature(*indexIter, count);
            }
        }
    }
}

void FeatureCorpus::squash() {
    map< int, int > replacements = alphabet->squash();
    for (vector< Document * >::const_iterator iter = getDocuments()->begin();
            getDocuments()->end() != iter; iter++) {
        FeatureMap * const featureMap =
                ((FeatureDocument *) (* iter))->getFeatureMap();
        for (map< int, int >::const_iterator riter = replacements.begin();
                replacements.end() != riter; riter++) {
            int const originalIndex = riter->first;
            int const replacementIndex = riter->second;

            int const count = featureMap->getFeature(originalIndex);
            if (0 < count) {
                featureMap->removeFeature(originalIndex);
                featureMap->setFeature(replacementIndex, count);
            }
        }
    }
}

auto_ptr< FeatureCorpus > FeatureCorpus::createInstance(
        const string & location) {
    return auto_ptr< FeatureCorpus > (new FeatureCorpus(
            location, auto_ptr< Alphabet > (new Alphabet())));
}
