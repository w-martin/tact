/**
 * @file IllegalArgumentException.h
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
 * Exception class which indicates that a method was called with 
 * one or more illegal arguments.
 * 
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H
#define	ILLEGALARGUMENTEXCEPTION_H

#define ILLEGAL_ARGUMENT_MESSAGE "Error. Illegal argument(s)."

#include "tmte-cpp/main/util/exceptions/Exception.h"

class IllegalArgumentException : public Exception {
public:

    IllegalArgumentException() : Exception(ILLEGAL_ARGUMENT_MESSAGE) {
    }

    IllegalArgumentException(const char * const message) 
    : Exception(message) {
    }
};

#endif	/* ILLEGALARGUMENTEXCEPTION_H */

