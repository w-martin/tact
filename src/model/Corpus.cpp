/**
 * @file Corpus.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include <stddef.h>
#include <memory>

#include "tmte-cpp/model/Corpus.h"

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
