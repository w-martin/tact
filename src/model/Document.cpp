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

Document::Document(int const length) {
    Document::total = 0;
    words = new vector <char const *>();
    counts = new vector<int>;
    Document::length = length;
}

Document::~Document() {
    delete words;
    delete counts;
}

vector<char const *> const * const Document::getWords() const {
    return words;
}

void Document::addWord(auto_ptr<const char> word, const int count) {
    words->push_back(word.release());
    counts->push_back(count);
    total += count;
}

vector<int> const * const Document::getCounts() const {
    return counts;
}

int const Document::getLength() const {
    return length;
}

int const Document::getTotal() const {
    return total;
}
