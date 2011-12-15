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

#include "tmte-cpp/model/Alphabet.h"
#include <sstream>

using std::stringstream;

Alphabet::Alphabet() {
    words = new vector<string > ();
    indices = new vector<int>();
    nextIndex = 0;
}

Alphabet::Alphabet(Alphabet const & orig) {
    words = new vector<string>(*orig.getWords());
    indices = new vector<int>(*orig.getIndices());
    nextIndex = orig.getNextIndex();
}

Alphabet::~Alphabet() {
    delete words;
    delete indices;
}

int const Alphabet::getSize() const {
    return words->size();
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

string const Alphabet::removeWord(const int index)
throw (WordNotPresentException) {
    string const word = getWord(index);
    deleteWord(word);
    deleteIndex(index);
    return word;
}

int const Alphabet::removeWord(const string word)
throw (WordNotPresentException) {
    int const index = getIndex(word);
    deleteWord(word);
    deleteIndex(index);
    return index;
}

bool const Alphabet::hasWord(const string word) const {
    try {
        getIndex(word);
        return true;
    } catch (WordNotPresentException) {
        return false;
    }
}

vector<int> const * const Alphabet::getIndices() const {
    return indices;
}

int const Alphabet::getIndex(const string word) const
throw (WordNotPresentException) {
    for (vector<string>::size_type i = 0; i < words->size(); i++) {
        if (0 == words->at(i).compare(word)) {
            return indices->at(i);
        }
    }
    throw WordNotPresentException(word);
}

string const Alphabet::getWord(const int index) const
throw (WordNotPresentException) {
    for (vector<string>::size_type i = 0; i < indices->size(); i++) {
        if (index == indices->at(i)) {
            return words->at(i);
        }
    }
    stringstream stream;
    stream << "has index " << index;
    throw WordNotPresentException(stream.str());
}

void Alphabet::deleteWord(const string word) {
    for (vector<string>::size_type i = 0; i < words->size(); i++) {
        if (0 == words->at(i).compare(word)) {
            words->erase(words->begin() + i);
            return;
        }
    }
}

void Alphabet::deleteIndex(const int index) {
    for (vector<string>::size_type i = 0; i < indices->size(); i++) {
        if (index == indices->at(i)) {
            indices->erase(indices->begin() + i);
            return;
        }
    }
}

int const Alphabet::getNextIndex() const {
    return nextIndex;
}
