/**
 * @file ElementNotPresentException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ELEMENTNOTPRESENTEXCEPTION_H
#define	ELEMENTNOTPRESENTEXCEPTION_H

#define ELEMENT_NOT_PRESENT_MESSAGE "Error. Element is not present."

#include "tmte-cpp/util/exceptions/Exception.h"

/**
 * Exception class which indicates that the Alphabet was already set.
 * 
 */
class ElementNotPresentException : public Exception {
public:

    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    ElementNotPresentException() : Exception(
    ELEMENT_NOT_PRESENT_MESSAGE) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    ElementNotPresentException(string const message)
    : Exception(message) {
    }
};

#endif	/* ELEMENTNOTPRESENTEXCEPTION_H */

