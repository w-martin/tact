/**
 * @file OutOfBoundsException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef OUTOFBOUNDSEXCEPTION_H
#define	OUTOFBOUNDSEXCEPTION_H

#define OUT_OF_BOUNDS_MESSAGE "Error. Out of bounds."

#include "teflon/util/exceptions/Exception.h"

/**
 * Exception class which indicates that an array was accessed
 * out of bounds.
 * 
 */
class OutOfBoundsException : public Exception {
public:
    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    OutOfBoundsException();
    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    OutOfBoundsException(int const & index, int const & bounds);
    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    OutOfBoundsException(string const & message);
    /**
     * Default destructor.
     * 
     */
    virtual ~OutOfBoundsException() throw ();
private:
    /**
     * Creates an error message with the given index and bounds.
     * 
     * @param index the index that was out of bounds.
     * @param bounds the bounds that the index did not meet.
     * @return an error message with the given index and bounds.
     * 
     */
    static string const createErrorMessage(
            int const & index, int const & bounds);
};

#endif	/* OUTOFBOUNDSEXCEPTION_H */
