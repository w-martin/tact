/**
 * @file LengthFilter.h
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
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef LENGTHFILTER_H
#define LENGTHFILTER_H

#include "mewt/input/pipe/Pipe.h"

class LengthFilter : public Pipe {
public:
    /**
     * Default constructor.
     * 
     * @param minimumLength the minimumLength that terms must have to pass 
     * this length filter.
     * 
     */
    LengthFilter(int const minimumLength);
    /**
     * Default destructor.
     * 
     */
    virtual ~LengthFilter();
    /**
     * Gets the minimumLength that terms must have to pass this length filter.
     * 
     * @return the minimumLength that terms must have to pass this length 
     * filter.
     * 
     */
    int const getMinimumLength() const;
private:
    /**
     * The minimumLength that terms must have to pass this length filter.
     * 
     */
    int minimumLength;
    /**
     * Process the given corpus.
     * 
     * @param corpus the Corpus to process.
     * @return the processed Corpus.
     * 
     */
    auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const;
};

#endif /* LENGTHFILTER_H */
