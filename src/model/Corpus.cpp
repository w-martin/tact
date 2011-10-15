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

#include "tmte-cpp/main/model/Corpus.h"

Corpus::Corpus() {
    noDocuments = 0;
    noTerms = 0;
    documents = (auto_ptr<Document>*) malloc(
            sizeof (auto_ptr<Document>) * noDocuments);
}

Corpus::~Corpus() {
}

Document const * const * const Corpus::getDocuments() const {
    Document const ** documentsArray =
            (Document const **) malloc(sizeof (Document*) * noDocuments);
    for (int i = 0; i < noDocuments; i++) {
        documentsArray[i] = documents[i].get();
    }
    return documentsArray;
}

void Corpus::addDocument(auto_ptr<Document> document) {
    noDocuments++;
    documents = (auto_ptr<Document> *) realloc(
            documents, sizeof (auto_ptr<Document>) * noDocuments);
    documents[noDocuments - 1] = document;
}

int const Corpus::getNoDocuments() const {
    return noDocuments;
}

void Corpus::setNoDocuments(const int noDocuments) {
    Corpus::noDocuments = noDocuments;
}

int const Corpus::getNoTerms() const {
    return noTerms;
}

void Corpus::setNoTerms(const int noTerms) {
    Corpus::noTerms = noTerms;
}
