/**
 * @file AlphabetSetException.h
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

#ifndef ALPHABETSETEXCEPTION_H
#define	ALPHABETSETEXCEPTION_H

#define ALPHABET_SET_MESSAGE "Error. Alphabet is already set."

#include "tmte-cpp/util/exceptions/Exception.h"

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

