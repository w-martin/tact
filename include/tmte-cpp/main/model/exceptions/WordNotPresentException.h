/**
 * @file WordNotPresentException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef WORDNOTPRESENTEXCEPTION_H
#define	WORDNOTPRESENTEXCEPTION_H

#define WORD_NOT_PRESENT_MESSAGE "Error. Word not present in alphabet."

#include "tmte-cpp/main/util/exceptions/Exception.h"
#include <sstream>

using std::stringstream;

/**
 * Exception class which indicates that a word was already
 * present in an alphabet.
 * 
 */
class WordNotPresentException : public Exception {
public:

    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    WordNotPresentException() : Exception(
    WORD_NOT_PRESENT_MESSAGE) {
    }

    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    WordNotPresentException(string const word, bool const isMessage)
    : Exception(isMessage ? word : createErrorMessage(word)) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    WordNotPresentException(string const message)
    : Exception(message) {
    }
private:

    string const createErrorMessage(string word) const {
        stringstream stream;
        stream << WORD_NOT_PRESENT_MESSAGE << " \nWord: "
                << word << ".";
        return stream.str();
    }
};

#endif	/* DUPLICATEDWORDEXCEPTION_H */

