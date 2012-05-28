/**
 * @file Document.cpp
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

#include "mewt/model/Document.h"

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
