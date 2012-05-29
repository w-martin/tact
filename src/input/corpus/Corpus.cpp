/**
 * @file Corpus.cpp
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

#include "mewt/input/corpus/Corpus.h"

Corpus::Corpus(const string location) {
    Corpus::location = location;
    documents = new vector< Document * >();
}

Corpus::Corpus(const Corpus& orig) {
    location = orig.getLocation();
    documents = new vector< Document * >();

    vector< Document * > const * const originalDocuments = orig.getDocuments();
    for (int i = 0; i < originalDocuments->size(); i++) {
        Document * d = new Document(*originalDocuments->at(i));
        documents->push_back(d);
    }
}

Corpus::~Corpus() {
    delete documents;
}

string const Corpus::getLocation() const {
    return location;
}

int const Corpus::getSize() const {
    return documents->size();
}

vector< Document * > const * const Corpus::getDocuments() const {
    return documents;
}

bool const Corpus::addDocument(auto_ptr<Document> document) {
    for (int i = 0; i < getSize(); i++) {
        Document * d = documents->at(i);
        if (0 == strcmp(d->getName().c_str(), document->getName().c_str())) {
            return false;
        }
    }
    documents->push_back(document.release());
    return true;
}
