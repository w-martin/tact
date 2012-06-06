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

Corpus::Corpus(const string location, const int documentsType) {
    Corpus::documents = new vector< Document * > ();
    Corpus::documentsType = documentsType;
    Corpus::location = location;
}

Corpus::Corpus(const Corpus& orig) {
    documents = new vector< Document * > ();
    vector< Document * > const * const originalDocuments = orig.getDocuments();
    for (int i = 0; i < orig.getSize(); i++) {
        documents->push_back(new Document(*originalDocuments->at(i)));
    }

    documentsType = orig.getDocumentsType();
    location = orig.getLocation();
}

Corpus::~Corpus() {
    delete documents;
}

bool const Corpus::addDocument(auto_ptr<Document> document)
throw (IncompatibleCorpusException) {
    if (document->getType() != documentsType) {
        throw IncompatibleCorpusException(
                getDocumentsType(), document->getType());
    }
    if (!contains(document.get())) {
        documents->push_back(document.release());
        return true;
    } else {
        return false;
    }
}

bool const Corpus::contains(Document const * const document) const {
    if (document->getType() != documentsType) {
        return false;
    }
    for (int i = 0; i < getSize(); i++) {
        Document const * const other = documents->at(i);
        if (document->equals(other)) {
            return true;
        }
    }
    return false;
}

vector< Document * > const * const Corpus::getDocuments() const {
    return documents;
}

int const Corpus::getDocumentsType() const {
    return documentsType;
}

string const Corpus::getLocation() const {
    return location;
}

int const Corpus::getSize() const {
    return documents->size();
}

bool const Corpus::removeDocument(Document const * const document) {
    if (document->getType() != getDocumentsType()) {
        return false;
    } else {
        for (vector< Document * >::iterator iter = documents->begin();
                documents->end() != iter; iter++) {
            if (document->equals(*iter)) {
                documents->erase(iter);
                return true;
            }
        }
    }
    return false;
}
