/**
 * @file FeatureMapPipe.cpp
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

#include "mewt/input/pipe/FeatureMapPipe.h"
#include "mewt/input/corpus/text/TextDocument.h"
#include "mewt/input/corpus/feature/FeatureCorpus.h"
#include <boost/static_assert.hpp>
#include <boost/algorithm/string.hpp>

FeatureMapPipe::FeatureMapPipe() {
}

FeatureMapPipe::~FeatureMapPipe() {
}

auto_ptr< Corpus > FeatureMapPipe::process(
        auto_ptr<Corpus> const corpus) const {
    assert(DOCUMENT_TYPE_TEXT == corpus->getDocumentsType());

    auto_ptr< FeatureCorpus > featureCorpus = auto_ptr< FeatureCorpus > (
            new FeatureCorpus(
            corpus->getLocation(),
            auto_ptr< Alphabet > (new Alphabet())));
    Alphabet * const alphabet = featureCorpus->getAlphabet();

    vector< Document * > const * const documents = corpus->getDocuments();
    for (vector< Document * >::const_iterator iter = documents->begin();
            iter != documents->end(); iter++) {
        string const * const text = ((TextDocument *) (*iter))->getText();
        auto_ptr< FeatureMap > featureMap =
                auto_ptr< FeatureMap > (new FeatureMap());

        auto_ptr< vector< string > > split = splitString(text);
        for (vector< string >::const_iterator iter = split->begin();
                iter != split->end(); iter++) {
            int index;
            try {
                index = alphabet->addTerm(*iter);
            } catch (DuplicatedTermException) {
                index = alphabet->getIndex(*iter);
            }
            featureMap->incrementFeature(index);
        }
        auto_ptr< FeatureDocument > document =
                auto_ptr< FeatureDocument > (
                new FeatureDocument((*iter)->getName(), featureMap));
        featureCorpus->addDocument((auto_ptr< Document >) document);
    }

    return (auto_ptr< Corpus >) featureCorpus;
}

auto_ptr< vector< string > > FeatureMapPipe::splitString(
        string const * const text) {
    auto_ptr< vector< string > > strings =
            auto_ptr< vector< string > >(new vector< string > ());
    boost::split(*strings.get(), (*text), boost::is_any_of("\n\t "));
    return strings;
}
