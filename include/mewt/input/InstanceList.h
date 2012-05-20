/**
 * @file InstanceList.h
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

#ifndef INSTANCELIST_H
#define	INSTANCELIST_H

#include "mewt/input/Pipe.h"
#include "mewt/input/Instance.h"
#include "mewt/input/Alphabet.h"
#include <memory>

using std::auto_ptr;

/**
 * List of instances for use with Pipe.
 * 
 */
class InstanceList {
public:
    InstanceList(auto_ptr<Pipe> pipe);
    InstanceList(const InstanceList& orig);
    virtual ~InstanceList();
    /**
     * Adds the given Instance to this InstanceList.
     * 
     * @param instance the Instance to add.
     * @return true if the Instance was added successfully, false otherwise.
     * 
     */
    bool const addInstance (Instance * const instance);
    /**
     * Gets the Instance objects.
     * 
     * @return the Instance objects.
     * 
     */
    vector<Instance*> const * const getInstances() const;
    /**
     * Checks if this InstanceList contains the given Instance.
     * 
     * @param instance the Instance to check for.
     * @return true if this InstanceList contains the given Instance,
     * false otherwise.
     * 
     */
    bool const containsInstance(Instance const * const instance) const;
    /**
     * Gets the size of this InstanceList.
     * 
     * @return the size of this InstanceList.
     * 
     */
    int const getSize() const;
    /**
     * Gets the Pipe that this InstanceList uses.
     * 
     * @return the Pipe that this InstanceList uses.
     * 
     */
    Pipe const * const getPipe() const;
    /**
     * Sets the Pipe that this InstanceList uses.
     * 
     * @param pipe the Pipe that this InstanceList will use.
     * @return true if the Pipe was set, false otherwise.
     * 
     */
    bool const setPipe(auto_ptr<Pipe> pipe);
    /**
     * Gets the data Alphabet.
     * 
     * @return the data Alphabet.
     * 
     */
    Alphabet const * const getDataAlphabet() const;
    /**
     * Gets the target Alphabet.
     * 
     * @return the target Alphabet.
     * 
     */
    Alphabet const * const getTargetAlphabet() const;
private:
    auto_ptr<Pipe> pipe;
    vector<Instance*> * instances;
};

#endif	/* INSTANCELIST_H */
