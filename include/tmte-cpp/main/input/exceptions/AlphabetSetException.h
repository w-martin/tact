/**
 * @file AlphabetSetException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ALPHABETSETEXCEPTION_H
#define	ALPHABETSETEXCEPTION_H

#define ALPHABET_SET_MESSAGE "Error. Alphabet is already set."

#include "tmte-cpp/main/util/exceptions/Exception.h"

/**
 * Exception class which indicates that the Alphabet was already set.
 * 
 */
class AlphabetSetException : public Exception {
public:

    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    AlphabetSetException() : Exception(
    ALPHABET_SET_MESSAGE) {
    }
    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    AlphabetSetException(string const message)
    : Exception(message) {
    }
};

#endif	/* ALPHABETSETEXCEPTION_H */

