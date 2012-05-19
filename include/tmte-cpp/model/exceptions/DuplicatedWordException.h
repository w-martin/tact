/**
 * @file DuplicatedWordException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef DUPLICATEDWORDEXCEPTION_H
#define	DUPLICATEDWORDEXCEPTION_H

#define DUPLICATED_WORD_MESSAGE "Error. Word already present in alphabet."

#include "tmte-cpp/util/exceptions/Exception.h"

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
    DuplicatedWordException() : Exception(
    string(DUPLICATED_WORD_MESSAGE)) {
    }

    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    DuplicatedWordException(string const word, bool const isMessage)
    : Exception(isMessage ? word : createErrorMessage(word)) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    DuplicatedWordException(string const message)
    : Exception(message) {
    }
private:

    string const createErrorMessage(string word) const {
        return string(DUPLICATED_WORD_MESSAGE)
                + string(" \nDuplicated word: ")
                + word
                + string(".");
    }
};

#endif	/* DUPLICATEDWORDEXCEPTION_H */

