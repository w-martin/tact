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

#include "tmte-cpp/main/output/Identifier.h"

Identifier::Identifier(const string name) {
    Identifier::name = name;
}

Identifier::Identifier(Identifier const & orig) {
    Identifier::name = orig.getName();
}

Identifier::~Identifier() {
}

string const Identifier::getName() const {
    return name;
}
