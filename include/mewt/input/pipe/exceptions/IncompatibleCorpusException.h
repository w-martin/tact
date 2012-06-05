/**
 * @file IncompatibleCorpusException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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

#ifndef INCOMPATIBLECORPUSEXCEPTION_H
#define	INCOMPATIBLECORPUSEXCEPTION_H

#define INCOMPATIBLE_CORPUS_MESSAGE "Error. Corpus is not compatible with this Pipe."

#include "mewt/util/exceptions/Exception.h"
#include <vector>

using std::vector;

/**
 * Exception class which indicates that a corpus was piped to an incompatible
 * Pipe.
 * 
 */
class IncompatibleCorpusException : public Exception {
public:
    /**
     * Default constructor. Uses the default message for this
     * Exception.
     * 
     */
    IncompatibleCorpusException();
    /**
     * Specific constructor. Generated an informative message
     * about the error.
     * 
     * @param corpusType the type of the corpus.
     * @param compatibleTypes the types that are compatible with the Pipe
     * which was run.
     * 
     */
    IncompatibleCorpusException(int const & corpusType,
            vector< int > const * const compatibleTypes);
    /**
     * Uses the given message for this Exception.
     * 
     * @param message the message to use for this Exception.
     * 
     */
    IncompatibleCorpusException(string const & message);
private:
    /**
     * Creates an error message using the given type identifiers.
     * 
     * @param corpusType the type of the corpus.
     * @param compatibleTypes the types that are compatible with the Pipe
     * which was run.
     * @return an error message using the given type identifiers.
     * 
     */
    string const createErrorMessage(int const & corpusType,
            vector< int > const * const compatibleTypes) const;
};

#endif	/* INCOMPATIBLECORPUSEXCEPTION_H */

