/**
 * @file DuplicatedWordException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef DUPLICATEDWORDEXCEPTION_H
#define	DUPLICATEDWORDEXCEPTION_H

#define DUPLICATED_WORD_MESSAGE "Error. Word already present in alphabet."

#include "tmte-cpp/main/util/exceptions/Exception.h"
#include <string>

/**
 * Exception class which indicates that a word was already
 * present in an alphabet.
 * 
 */
class DuplicatedWordException : public Exception {
public:

    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    DuplicatedWordException() : Exception(DUPLICATED_WORD_MESSAGE) {
    }

    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    DuplicatedWordException(char const * const word, bool const isMessage)
    : Exception(isMessage ? word : createErrorMessage(word)) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    DuplicatedWordException(const char * const message)
    : Exception(message) {
    }
private:

    char const * createErrorMessage(char const * const word) const {
        char const * const format = "%s \nDuplicated word: %s.";
        char * result = (char*) malloc(sizeof (char) * (strlen(format)
                + strlen(DUPLICATED_WORD_MESSAGE) + strlen(word) - 4));
        sprintf(result, format,
                DUPLICATED_WORD_MESSAGE, word);
        return result;
    }
};

#endif	/* DUPLICATEDWORDEXCEPTION_H */

