/**
 * @file InstanceList.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/main/input/InstanceList.h"

InstanceList::InstanceList() {
    instances = new vector<Instance>();
}

InstanceList::InstanceList(const InstanceList& orig) {
    instances = new vector<Instance>(*orig.getInstances());  
}

InstanceList::~InstanceList() {
    delete instances;
}

vector<Instance> const * const InstanceList::getInstances() const {
    return instances;
}

bool const InstanceList::addInstance(Instance const & instance) {
    instances->push_back(instance);
    return true;
}
