/**
 * @file Document.cpp
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

#include "tmte-cpp/main/model/Document.h"

Document::Document(
        auto_ptr<int> words,
        auto_ptr<int> counts,
        int const length,
        int const total)
throw (IllegalArgumentException) {
    if (NULL == words.get()
            || NULL == counts.get()) {
        throw IllegalArgumentException();
    }
    Document::words = words;
    Document::counts = counts;
    Document::length = length;
    Document::total = total;
}

Document::~Document() {
}

int const * const Document::getWords() const {
    return Document::words.get();
}

int const * const Document::getCounts() const {
    return Document::counts.get();
}

int const Document::getLength() const {
    return Document::length;
}

int const Document::getTotal() const {
    return total;
}
