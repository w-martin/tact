/**
 * @file Identifier.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "teflon/output/Identifier.h"

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
