/**
 * @file Pipe.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#include "mewt/input/exceptions/AlphabetSetException.h"
#include "mewt/input/Instance.h"
#include "mewt/input/Alphabet.h"
#include <vector>
#include <memory>

using std::vector;
using std::auto_ptr;

/**
 * Pipe class for transforming Instance objects.
 * 
 */
class Pipe : vector<Instance> {
public:
    Pipe();
    Pipe(const Pipe& orig);
    virtual ~Pipe();
    /**
     * Gets the data Alphabet.
     * 
     * @return the data Alphabet.
     * 
     */
    Alphabet const * const getDataAlphabet() const;
    /**
     * Sets the data Alphabet.
     * 
     * @param dataAlphabet the data Alphabet.
     * 
     */
    void setDataAlphabet(auto_ptr<Alphabet> dataAlphabet)
    throw (AlphabetSetException);
    /**
     * Gets the target Alphabet.
     * 
     * @return the target Alphabet.
     * 
     */
    Alphabet const * const getTargetAlphabet() const;
    /**
     * Sets the target Alphabet.
     * 
     * @param targetAlphabet the target Alphabet.
     * 
     */
    void setTargetAlphabet(auto_ptr<Alphabet> targetAlphabet)
    throw (AlphabetSetException);
    /**
     * Performs the pipe operation of this Pipe.
     * 
     * @param instance the Instance to perform the pipe operation on.
     * @return the transformed Instance.
     * 
     */
    virtual Instance const pipe(Instance const & instance) const;
private:
    auto_ptr<Alphabet> dataAlphabet;
    auto_ptr<Alphabet> targetAlphabet;
};

#endif	/* PIPE_H */
