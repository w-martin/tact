/**
 * @file Identifier.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef IDENTIFIER_H
#define	IDENTIFIER_H

#include <string>

using std::string;

/**
 * Represents an Identifier for some element.
 * 
 */
class Identifier{
public:
    Identifier(string const name);
    Identifier(Identifier const & orig);
    virtual ~Identifier();
    string const getName() const;
private:
    string name;
};

#endif	/* IDENTIFIER_H */
