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
    data = new bmType();
    nextIndex = 0;
}

Alphabet::Alphabet(Alphabet const & orig) {
    data = new bmType(*orig.getData());
    nextIndex = orig.getNextIndex();
}

Alphabet::~Alphabet() {
    delete data;
}

int const Alphabet::addTerm(string const term) {
    try {
        return getIndex(term);
    } catch (TermNotPresentException) {
        int const index = nextIndex++;
        data->insert(bmType::value_type(term, index));
        return index;
    }
}

AlphabetIterator const Alphabet::begin() const {
    return AlphabetIterator(data->left.begin());
}

AlphabetIterator const Alphabet::end() const {
    return AlphabetIterator(data->left.end());
}

bool const Alphabet::equals(Alphabet const * const other) const {
    if (getSize() == other->getSize()) {
        AlphabetIterator iter2 = other->begin();
        AlphabetIterator iter1 = begin();
        while (end() != iter1
                && other->end() != iter2) {
            if (iter1.getIndex() != iter2.getIndex()
                    || 0 != strcmp(iter1.getTerm().c_str(),
                    iter2.getTerm().c_str())) {
                return false;
            }
            iter1++;
            iter2++;
        }
    } else {
        return false;
    }
    return true;
}

int const Alphabet::getIndex(const string & term) const
throw (TermNotPresentException) {
    bmType::left_const_iterator result = data->left.find(term);
    if (data->left.end() != result) {
        return result->second;
    } else {

        throw TermNotPresentException(term, false);
    }
}

int const Alphabet::getNextIndex() const {

    return nextIndex;
}

int const Alphabet::getSize() const {

    return data->size();
}

string const Alphabet::getTerm(const int & index) const
throw (TermNotPresentException) {
    if (index < nextIndex) {
        bmType::right_const_iterator result = data->right.find(index);
        if (data->right.end() != result) {

            return result->second;
        }
    }
    throw createExceptionWithIndex(index);
}

bool const Alphabet::hasTerm(const string & term) const {
    try {
        getIndex(term);
        return true;
    } catch (TermNotPresentException) {

        return false;
    }
}

string const Alphabet::removeTerm(const int & index)
throw (TermNotPresentException) {
    string const term = getTerm(index);
    data->right.erase(index);

    return term;
}

int const Alphabet::removeTerm(const string & term)
throw (TermNotPresentException) {
    int const index = getIndex(term);
    data->left.erase(term);

    return index;
}

bmType const * const Alphabet::getData() const {
    return data;
}

TermNotPresentException const Alphabet::createExceptionWithIndex(
        const int index) const {
    stringstream stream;
    stream << "has index " << index;
    return TermNotPresentException(stream.str(), false);
}
