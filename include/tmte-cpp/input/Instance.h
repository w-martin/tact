/**
 * @file Instance.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include "tmte-cpp/input/FeatureVector.h"

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
