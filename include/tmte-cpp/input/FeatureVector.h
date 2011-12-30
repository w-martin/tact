/**
 * @file FeatureVector.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef FEATUREVECTOR_H
#define	FEATUREVECTOR_H

#include "tmte-cpp/model/Alphabet.h"
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
            int const * const features);
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
    int * features;
    void copyFeatures()
};

#endif	/* FEATUREVECTOR_H */
