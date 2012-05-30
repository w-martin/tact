/**
 * @file MockCorpus.h
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

#include "gmock/gmock.h"
#include "mewt/input/corpus/Corpus.h"

/**
 * Mock Corpus class.
 * 
 */
class MockCorpus : public Corpus {
public:

    MockCorpus(string const location) : Corpus(location) {
    }

    MockCorpus(MockCorpus const & orig) : Corpus(orig) {
    }

    virtual ~MockCorpus() {
    }

    vector< Document * > const * const getDocuments() const {
        return Corpus::getDocuments();
    }

    bool const addDocument(auto_ptr< Document > document) {
        return Corpus::addDocument(document);
    }
};
