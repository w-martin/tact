/**
 * @file TermNotPresentException.h
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

#ifndef TERMNOTPRESENTEXCEPTION_H
#define	TERMNOTPRESENTEXCEPTION_H

#define TERM_NOT_PRESENT_MESSAGE "Error. Term not present in alphabet."

#include "teflon/util/exceptions/Exception.h"

/**
 * Exception class which indicates that a term was not
 * present in an alphabet.
 * 
 */
class TermNotPresentException : public Exception {
public:
    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    TermNotPresentException();
    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    TermNotPresentException(string const term, bool const & isMessage);
    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    TermNotPresentException(string const message);
private:
    /**
     * Creates an error message using the given term.
     * 
     * @param term the term to create an error message with.
     * @return an error message using the given term.
     * 
     */
    string const createErrorMessage(string const & term) const;
};

#endif	/* TERMNOTPRESENTEXCEPTION_H */

