/**
 * @file Alphabet.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/main/model/Alphabet.h"

Alphabet::Alphabet() {
    words = new vector<string > ();
    indices = new vector<int>();
    nextIndex = 0;
    noWords = 0;
}

Alphabet::~Alphabet() {
    delete words;
    delete indices;
}

vector<string> const * const Alphabet::getWords() const {
    return words;
}

int const Alphabet::addWord(string word)
throw (DuplicatedWordException) {
    if (hasWord(word)) {
        throw DuplicatedWordException(word);
    } else {
        words->push_back(word);
        int index = nextIndex++;
        indices->push_back(index);
        return index;
    }
}

bool const Alphabet::hasWord(const string word) const {
    try {
        getIndex(word);
        return true;
    } catch (DuplicatedWordException) {
        return false;
    }
}

int const Alphabet::getIndex(const string word) const
throw (WordNotPresentException) {
    for (vector<string>::size_type i = 0; i < words->size(); i++) {
        if (0 == words->at(i).compare(word)) {
            return indices->at(i);
        }
    }
    throw DuplicatedWordException(word);
}

vector<int> const * const Alphabet::getIndices() const {
    return indices;
}
