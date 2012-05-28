/**
 * @file Corpus.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.0
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

#include <stddef.h>
#include <memory>

#include "mewt/model/Corpus.h"

Corpus::Corpus() {
    noTerms = 0;
    documents = new vector<Document const *>();
}

Corpus::~Corpus() {
    delete documents;
}

vector<Document const *> const * const Corpus::getDocuments() const {
    return documents;
}

void Corpus::addDocument(auto_ptr<Document> document) {
    documents->push_back(document.release());
}

int const Corpus::getNoTerms() const {
    return noTerms;
}

void Corpus::setNoTerms(const int noTerms) {
    Corpus::noTerms = noTerms;
}
