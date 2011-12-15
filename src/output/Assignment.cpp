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

bool const Assignment::contains(const Identifier key) const {
    return (end() != find(key));
}
