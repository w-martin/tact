/**
 * @file InputPipe.h
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

#ifndef INPUTPIPE_H
#define	INPUTPIPE_H

#include "mewt/input/pipe/Pipe.h"

/**
 * InputPipe class for transforming Corpus objects.
 * 
 */
class InputPipe : public Pipe {
public:
    /**
     * Default constructor.
     * 
     */
    InputPipe();
    /**
     * Default destructor.
     * 
     */
    virtual ~InputPipe();
    /**
     * Computes the file name of a Document from its name and the location
     * of the Corpus.
     * 
     * @param location the location of the corpus.
     * @param name the name of the Document.
     * @return the file name of a Document.
     * 
     */
    static string const computeFileName(string const & location,
            string const & name);
    /**
     * Reads the given file directly into a string.
     * 
     * @param location the location of the file on disk.
     * @return the string which was read.
     * 
     */
    static auto_ptr< string > readFileIntoString(string const & location);
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

#endif	/* INPUTPIPE_H */
