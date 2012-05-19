/**
 * @file Assignment.h
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

#ifndef ASSIGNMENT_H
#define	ASSIGNMENT_H

#include "tmte-cpp/output/exceptions/ElementNotPresentException.h"
#include "tmte-cpp/output/Identifier.h"
#include "tmte-cpp/util/exceptions/OutOfBoundsException.h"
#include <map>

using std::map;

/**
 * Represents an assignment some elements with corresponding counts.
 * 
 */
class Assignment : private map<Identifier, double> {
public:
    Assignment();
    Assignment(Assignment const & orig);
    virtual ~Assignment();

    /**
     * Adds the given key and value pair to this Assignment.
     * 
     * @param key the key of the pair.
     * @param value the value of the pair.
     * @return true if the pair was added successfully, false otherwise.
     * 
     */
    bool const add(Identifier const key, double const value);
    /**
     * Checks if this Assignment contains the given key.
     * 
     * @param key the key to check for.
     * @return true if this Assignment contains the given key, false otherwise.
     * 
     */
    bool const contains(Identifier const & key) const;
    /**
     * Gets the value with the given key.
     * @param key the key to get the value for.
     * @return the value with the given key.
     * @throw ElementNotPresentException if the key could not be found 
     * in this Assignment.
     * 
     */
    double const get(Identifier const & key) const
    throw (ElementNotPresentException);
    /**
     * Gets the key at the given position.
     * @param position the position of the key to get.
     * @return the key at the given position.
     * @throw ElementNotPresentException if the key could not be found 
     * in this Assignment.
     * 
     */
    Identifier const getKey(int const & position) const
    throw (OutOfBoundsException);
    /**
     * Gets the size of this set of Assignments.
     * 
     * @return the size of this set of Assignments.
     * 
     */
    int const getSize() const;
    /**
     * Removes the pair identified by the given key.
     * 
     * @param key the key of the pair to remove.
     * @return the value associated with the given key.
     * @throw ElementNotPresentException if the key could not be found 
     * in this Assignment.
     * 
     */
    double const remove(Identifier const & key)
    throw (ElementNotPresentException);
};

#endif	/* ASSIGNMENT_H */
