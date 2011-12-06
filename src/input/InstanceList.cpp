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

#include <stddef.h>
#include <memory>

#include "tmte-cpp/main/input/InstanceList.h"

InstanceList::InstanceList() {
    instances = new vector<Instance>();
}

InstanceList::InstanceList(const InstanceList& orig) {
    instances = new vector<Instance>(*orig.getInstances());  
}

InstanceList::~InstanceList() {
}

vector<Instance> const * const InstanceList::getInstances() const{
    return instances;
}
