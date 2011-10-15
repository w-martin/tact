/**
 * @file Exception.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 *
 * @section DESCRIPTION
 *
 * Custom <code>Exception</code> class.
 * 
 * @param message the message that will be printed as the cause for this
 * <code>Exception</code>.
 * 
 */

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <exception>

class Exception : public std::exception {
public:

    Exception(const char *message) {
        Exception::message = message;
    }

    virtual ~Exception() throw () {
    }

    virtual const char * what() const throw () {
        return message;
    }
private:
    /**
     * The string which is the reason why this <code>Exception</code> was
     * thrown.
     * 
     */
    const char *message;
};

#endif	/* EXCEPTION_H */

