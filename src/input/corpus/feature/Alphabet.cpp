/**
 * @file Alphabet.cpp
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

#include "mewt/input/corpus/feature/Alphabet.h"
#include <sstream>

using std::stringstream;

Alphabet::Alphabet() {
    terms = new vector<string > ();
    indices = new vector<int>();
    nextIndex = 0;
}

Alphabet::Alphabet(Alphabet const & orig) {
    terms = new vector<string>(*orig.getTerms());
    indices = new vector<int>(*orig.getIndices());
    nextIndex = orig.getNextIndex();
}

Alphabet::~Alphabet() {
    delete terms;
    delete indices;
}
int const Alphabet::addTerm(string term)
throw (DuplicatedTermException) {
    if (hasTerm(term)) {
        throw DuplicatedTermException(term);
    } else {
        terms->push_back(term);
        int index = nextIndex++;
        indices->push_back(index);
        return index;
    }
}

int const Alphabet::getIndex(const string term) const
throw (TermNotPresentException) {
    for (vector<string>::size_type i = 0; i < terms->size(); i++) {
        if (0 == terms->at(i).compare(term)) {
            return indices->at(i);
        }
    }
    throw TermNotPresentException(term);
}

vector<int> const * const Alphabet::getIndices() const {
    return indices;
}

int const Alphabet::getNextIndex() const {
    return nextIndex;
}

int const Alphabet::getSize() const {
    return terms->size();
}

string const Alphabet::getTerm(const int index) const
throw (TermNotPresentException) {
    for (vector<string>::size_type i = 0; i < indices->size(); i++) {
        if (index == indices->at(i)) {
            return terms->at(i);
        }
    }
    stringstream stream;
    stream << "has index " << index;
    throw TermNotPresentException(stream.str());
}

vector<string> const * const Alphabet::getTerms() const {
    return terms;
}

bool const Alphabet::hasTerm(const string term) const {
    try {
        getIndex(term);
        return true;
    } catch (TermNotPresentException) {
        return false;
    }
}

string const Alphabet::removeTerm(const int index)
throw (TermNotPresentException) {
    string const term = getTerm(index);
    deleteTerm(term);
    deleteIndex(index);
    return term;
}

int const Alphabet::removeTerm(const string term)
throw (TermNotPresentException) {
    int const index = getIndex(term);
    deleteTerm(term);
    deleteIndex(index);
    return index;
}

void Alphabet::deleteIndex(const int index) {
    for (vector<string>::size_type i = 0; i < indices->size(); i++) {
        if (index == indices->at(i)) {
            indices->erase(indices->begin() + i);
            return;
        }
    }
}

void Alphabet::deleteTerm(const string term) {
    for (vector<string>::size_type i = 0; i < terms->size(); i++) {
        if (0 == terms->at(i).compare(term)) {
            terms->erase(terms->begin() + i);
            return;
        }
    }
}
