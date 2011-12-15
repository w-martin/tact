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

#include "tmte-cpp/output/Identifier.h"
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
    bool const contains(Identifier const key) const;
};

#endif	/* ASSIGNMENT_H */
