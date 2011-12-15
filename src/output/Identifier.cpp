/**
 * @file Identifier.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/output/Identifier.h"

Identifier::Identifier(const string name) {
    Identifier::name = name;
}

Identifier::Identifier(Identifier const & orig) {
    Identifier::name = orig.getName();
}

Identifier::~Identifier() {
}

bool const Identifier::operator<(const Identifier& rhs) const {
    return name < rhs.getName();
}

bool const Identifier::operator !=(const Identifier& rhs) const {
    return !equals(rhs);
}

bool const Identifier::operator ==(const Identifier& rhs) const {
    return equals(rhs);
}

string const Identifier::getName() const {
    return name;
}

bool const Identifier::equals(Identifier const & other) const {
    return (0 == name.compare(other.getName()));
}
