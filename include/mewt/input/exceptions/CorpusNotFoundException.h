/**
 * @file CorpusNotFoundException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef CORPUSNOTFOUNDEXCEPTION_H
#define CORPUSNOTFOUNDEXCEPTION_H

#define CORPUS_NOT_FOUND_MESSAGE "Error. Corpus was not found."

#include "teflon/util/exceptions/Exception.h"

class CorpusNotFoundException : public Exception {
public:
    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    CorpusNotFoundException();
    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     */
    CorpusNotFoundException(string const location, bool const & isMessage);
    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    CorpusNotFoundException(string const message);
private:
    /**
     * Creates an error message using the given location.
     * 
     * @param location the location to create an error message with.
     * @return an error message using the given location.
     * 
     */
    string const createErrorMessage(string const & location) const;
};

#endif /* CORPUSNOTFOUNDEXCEPTION_H */
