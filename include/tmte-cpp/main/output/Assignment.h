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

#include "tmte-cpp/main/output/Identifier.h"
#include <map>

using std::map;

/**
 * Represents an assignment some elements with corresponding counts.
 * 
 */
class Assignment : map<Identifier, double> {
public:

    Assignment() {
    }

    Assignment(Assignment const & orig)
    : map<Identifier, double >(orig) {
    }
    virtual ~Assignment();
};

#endif	/* ASSIGNMENT_H */
