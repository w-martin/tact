/**
 * @file Instance.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/input/Instance.h"

Instance::Instance(auto_ptr<FeatureVector> data) {
    Instance::data = data;
}

Instance::Instance(const Instance& orig) {
    data = auto_ptr<FeatureVector > (new FeatureVector(*orig.getData()));
}

Instance::~Instance() {
}

FeatureVector * const Instance::getData() const {
    return data.get();
}