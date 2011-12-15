/**
 * @file IllegalArgumentException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H
#define	ILLEGALARGUMENTEXCEPTION_H

#define ILLEGAL_ARGUMENT_MESSAGE "Error. Illegal argument(s)."

#include "tmte-cpp/util/exceptions/Exception.h"

/**
 * Exception class which indicates that a method was called with 
 * one or more illegal arguments.
 * 
 */
class IllegalArgumentException : public Exception {
public:

    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    IllegalArgumentException() : Exception(
    string(ILLEGAL_ARGUMENT_MESSAGE)) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    IllegalArgumentException(string const message)
    : Exception(message) {
    }
};

#endif	/* ILLEGALARGUMENTEXCEPTION_H */

