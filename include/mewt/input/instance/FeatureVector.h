/**
 * @file FeatureVector.h
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

#ifndef FEATUREVECTOR_H
#define	FEATUREVECTOR_H

#include "mewt/input/Alphabet.h"
#include <memory>
#include <vector>

using std::auto_ptr;
using std::vector;

/**
 * FeatureVector class for inputting corpus files.
 * 
 */
class FeatureVector {
public:
    FeatureVector(auto_ptr<Alphabet> alphabet,
            auto_ptr<vector<int> > features);
    FeatureVector(const FeatureVector& orig);
    virtual ~FeatureVector();
    /**
     * Gets the Alphabet.
     * 
     * @return the Alphabet.
     * 
     */
    Alphabet const * const getAlphabet() const;
    /**
     * Gets the features (index) vector.
     * 
     * @return the features (index) vector.
     * 
     */
    vector<int> const * const getFeatures() const;
    /**
     * Gets the size of this FeatureVector.
     * 
     * @return the size of this FeatureVector.
     * 
     */
    int const getSize() const;
private:
    auto_ptr<Alphabet> alphabet;
    auto_ptr<vector<int> > features;
};

#endif	/* FEATUREVECTOR_H */
