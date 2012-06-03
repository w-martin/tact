/**
 * @file LowerCasePipe.h
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

#ifndef LOWERCASEPIPE_H
#define	LOWERCASEPIPE_H

#include "mewt/input/pipe/Pipe.h"

/**
 * LowerCasePipe class for transforming Corpus objects.
 * 
 */
class LowerCasePipe : public Pipe {
public:
    /**
     * Default constructor.
     * 
     */
    LowerCasePipe();
    /**
     * Default destructor.
     * 
     */
    virtual ~LowerCasePipe();
    /**
     * Checks if the given term contains any upper case characters.
     * 
     * @param corpus the corpus to check for upper case characters.
     * @return true if the given term contains any upper case characters,
     * false otherwise.
     * 
     */
    static bool const containsUpperCase(string const & term);
    /**
     * Transforms the given term to lower case.
     * 
     * @param originalTerm the original term containing upper case characters.
     * @return the transformed term.
     * 
     */
    static string const toLowerCase(string const & originalTerm);
private:
    /**
     * Process the given corpus.
     * 
     * @param corpus the Corpus to process.
     * @return the processed Corpus.
     * @throw IncompatibleCorpusException if the given Corpus was of an
     * incompatible type with this Pipe.
     * 
     */
    auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const
    throw (IncompatibleCorpusException);
};

#endif	/* LOWERCASEPIPE_H */
