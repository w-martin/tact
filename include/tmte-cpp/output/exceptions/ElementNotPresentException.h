/**
 * @file ElementNotPresentException.h
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

