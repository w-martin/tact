/**
 * @file Assignment.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
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