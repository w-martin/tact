/**
 * @file OutOfBoundsException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef OUTOFBOUNDSEXCEPTION_H
#define	OUTOFBOUNDSEXCEPTION_H

#define OUT_OF_BOUNDS_MESSAGE "Error. Out of bounds."

#include "mewt/util/exceptions/Exception.h"
#include <sstream>

using std::stringstream;

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
    OutOfBoundsException() : Exception(string(OUT_OF_BOUNDS_MESSAGE)) {
    }

    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    OutOfBoundsException(int const index, int const bounds)
    : Exception(createErrorMessage(index, bounds)) {
    }

    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    OutOfBoundsException(string const message)
    : Exception(message) {
    }
private:

    string const createErrorMessage(int const & index,
            int const & bounds) const {
        stringstream stream;
        stream << OUT_OF_BOUNDS_MESSAGE << " \nIndex: "
                << index << " Bounds: " << bounds;
        return stream.str();
    }
};

#endif	/* OUTOFBOUNDSEXCEPTION_H */

