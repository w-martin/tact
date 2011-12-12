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
    /**
     * Gets the name of this Identifier.
     * 
     * @return the name of this Identifier.
     * 
     */
    string const getName() const;
    /**
     * Checks if this Identifier is equal to the given Identifier.
     * 
     * @param other the Identifier to compare to.
     * @return true if this Identifier is equal to the given Identifier,
     * false otherwise.
     * 
     */
    bool const equals(Identifier const & other) const;
private:
    string name;
};

#endif	/* IDENTIFIER_H */
