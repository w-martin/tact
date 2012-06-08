/**
 * @file AlphabetIterator.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/corpus/feature/AlphabetIterator.h"

AlphabetIterator::AlphabetIterator(bmType::left_const_iterator const iter) {
    AlphabetIterator::iter = iter;
}

AlphabetIterator::AlphabetIterator(AlphabetIterator const & orig) {
    iter = orig.getIterator();
}

AlphabetIterator::~AlphabetIterator() {
}

AlphabetIterator AlphabetIterator::operator ++() {
    iter++;
    return *this;
}

AlphabetIterator AlphabetIterator::operator ++(int) {
    AlphabetIterator dummy(iter);
    ++(*this);
    return dummy;
}

bool const AlphabetIterator::operator ==(
        AlphabetIterator const & other) const {
    return equals(other);
}

bool const AlphabetIterator::operator !=(
        AlphabetIterator const & other) const {
    return !equals(other);
}

bool const AlphabetIterator::equals(AlphabetIterator const & other) const {
    return (iter == other.getIterator());
}

int const AlphabetIterator::getIndex() const {
    return iter->second;
}

string const AlphabetIterator::getTerm() const {
    return iter->first;
}

bmType::left_const_iterator const AlphabetIterator::getIterator() const {
    return iter;
}
