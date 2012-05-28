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

/**
 * Instance class for inputting corpus files.
 * 
 */
class Instance {
public:
    Instance(auto_ptr<FeatureVector> data);
    Instance(const Instance& orig);
    virtual ~Instance();
    /**
     * Gets the data.
     * 
     * @return the data.
     * 
     */
    FeatureVector * const getData() const;
private:
    auto_ptr<FeatureVector> data;
};

#endif	/* INSTANCE_H */
