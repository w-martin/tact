/**
 * @file Instance.h
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

#ifndef INSTANCE_H
#define	INSTANCE_H

#include "mewt/input/FeatureVector.h"
#include <string>

/**
 * Instance class for corpus files. Stores the name of the file.
 * 
 */
class Instance {
public:
    /**
     * Default constructor.
     * 
     * @param name the name of the file.
     * 
     */
    Instance(string const name);
    /**
     * Copy constructor.
     * 
     * @param orig the Instance to copy.
     * 
     */
    Instance(const Instance& orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~Instance();
    /**
     * Gets the name of this Instance.
     * 
     * @return the name of this Instance.
     * 
     */
    string const getName() const;
private:
    string name;
};

#endif	/* INSTANCE_H */
