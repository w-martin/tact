/**
 * @file OutOfBoundsException.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
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
#include <string>

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
    OutOfBoundsException() : Exception(OUT_OF_BOUNDS_MESSAGE) {
    }

    /**
     * Default constructor. Uses the default message for this
     * Exception.
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
    OutOfBoundsException(const char * const message)
    : Exception(message) {
    }
private:

    char const * createErrorMessage(int const & index,
            int const & bounds) const {
        char * result;
        char const * const format = "%s \nIndex: %d Bounds: %d";
        sprintf(result, format,
                OUT_OF_BOUNDS_MESSAGE, index, bounds);
        return result;
    }
};

#endif	/* OUTOFBOUNDSEXCEPTION_H */

