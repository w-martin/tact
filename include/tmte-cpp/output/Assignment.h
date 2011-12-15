/**
 * @file Assignment.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
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
     * Gets the value with the given key.
     * @param key the key to get the value for.
     * @return the value with the given key.
     * @throw ElementNotPresentException if the key could not be found 
     * in this Assignment.
     * 
     */
    double const get(int const & position) const
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
