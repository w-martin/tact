/**
 * @file Exception.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <exception>
#include <string>

using std::string;

/**
 * Custom <code>Exception</code> class.
 * 
 * @param message the message that will be printed as the cause for this
 * <code>Exception</code>.
 * 
 */
class Exception : public std::exception {
public:

    /**
     * Default constructor.
     * 
     * @param message the message that will be printed as the cause for this
     * <code>Exception</code>.
     * 
     */
    Exception(string message) {
        Exception::message = message;
    }

    virtual ~Exception() throw () {
    }

    virtual const char * what() const throw () {
        return message.c_str();
    }
private:
    string message;
};

#endif	/* EXCEPTION_H */

