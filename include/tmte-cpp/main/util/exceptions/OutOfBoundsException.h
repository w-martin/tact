/**
 * @file OutOfBoundsException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef OUTOFBOUNDSEXCEPTION_H
#define	OUTOFBOUNDSEXCEPTION_H

#define OUT_OF_BOUNDS_MESSAGE "Error. Out of bounds."

#include "tmte-cpp/main/util/exceptions/Exception.h"
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

