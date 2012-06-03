/**
 * @file Pipe.h
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

#ifndef PIPE_H
#define	PIPE_H

#include "mewt/input/corpus/Corpus.h"
#include "mewt/input/pipe/exceptions/IncompatibleCorpusException.h"
#include <memory>

using std::auto_ptr;

/**
 * Pipe class for transforming Corpus objects.
 * 
 */
class Pipe {
public:
    /**
     * Default constructor.
     * 
     */
    Pipe();
    /**
     * Default destructor.
     * 
     */
    virtual ~Pipe();
    /**
     * Gets the next Pipe in the sequence.
     * 
     * @param nextPipe the next Pipe in the sequence.
     * 
     */
    Pipe const * const getNextPipe() const;
    /**
     * Attaches a pipe that will process the output at the end of this 
     * Pipe sequence.
     * 
     * @param nextPipe the next Pipe in the sequence.
     * 
     */
    void attachPipe(auto_ptr< Pipe > nextPipe);
    /**
     * Processes the given input and passes it to the next Pipe in the 
     * sequence.
     * 
     * @param corpus the Corpus to pipe.
     * @return the piped corpus.
     * @throw IncompatibleCorpusException if the given Corpus was of an
     * incompatible type with this Pipe.
     * 
     */
    auto_ptr< Corpus > pipe(auto_ptr< Corpus > corpus) const
    throw (IncompatibleCorpusException);
private:
    auto_ptr< Pipe > nextPipe;
    /**
     * Process the given corpus.
     * 
     * @param corpus the Corpus to process.
     * @return the processed Corpus.
     * @throw IncompatibleCorpusException if the given Corpus was of an
     * incompatible type with this Pipe.
     * 
     */
    virtual auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const
    throw (IncompatibleCorpusException) = 0;
};

#endif	/* PIPE_H */
