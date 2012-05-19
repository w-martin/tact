/**
 * @file Assignment.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "tmte-cpp/output/Assignment.h"

Assignment::Assignment() {
}

Assignment::Assignment(Assignment const & orig)
: map<Identifier, double>(orig) {
}

Assignment::~Assignment() {
}

bool const Assignment::add(const Identifier key, const double value) {
    if (contains(key)) {
        return false;
    }
    std::pair<Identifier, double> pair =
            std::make_pair<Identifier, double>(key, value);
    insert(pair);
    return true;
}

bool const Assignment::contains(const Identifier & key) const {
    return (end() != find(key));
}

double const Assignment::get(Identifier const & key) const
throw (ElementNotPresentException) {
    const_iterator iter = find(key);
    if (end() != iter) {
        return iter->second;
    } else {
        throw ElementNotPresentException(
                "Pair with Identifier " + key.getName() + " not present.");
    }
}

Identifier const Assignment::getKey(int const & position) const
throw (OutOfBoundsException) {
    if (position < size()) {
        int n = 0;
        for (map<Identifier, double>::const_iterator iter = begin();
                iter != end(); iter++) {
            if (position == n) {
                return iter->first;
            } else {
                n++;
            }
        }
    }
    throw OutOfBoundsException(position, size());
}

int const Assignment::getSize() const {
    return size();
}

double const Assignment::remove(const Identifier & key)
throw (ElementNotPresentException) {
    iterator iter = find(key);
    if (end() == iter) {
        throw ElementNotPresentException(
                "Pair with Identifier " + key.getName() + " not present.");
    } else {
        double value = iter->second;
        erase(iter);
        return value;
    }
}
