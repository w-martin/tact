/**
 * @file WordNotPresentException.h
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

#ifndef WORDNOTPRESENTEXCEPTION_H
#define	WORDNOTPRESENTEXCEPTION_H

#define WORD_NOT_PRESENT_MESSAGE "Error. Word not present in alphabet."

#include "tmte-cpp/util/exceptions/Exception.h"
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

#endif	/* WORDNOTPRESENTEXCEPTION_H */

