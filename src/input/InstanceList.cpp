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

#include "tmte-cpp/input/InstanceList.h"

InstanceList::InstanceList(auto_ptr<Pipe> pipe) {
    InstanceList::pipe = pipe;
    instances = new vector<Instance*> ();
}

InstanceList::InstanceList(const InstanceList& orig) {
    pipe = auto_ptr<Pipe > (new Pipe(*orig.getPipe()));
    instances = new vector<Instance*>(*orig.getInstances());
}

InstanceList::~InstanceList() {
    for (int i = instances->size() - 1; i >= 0; i--) {
        delete instances->at(i);
    }
    delete instances;
}

bool const InstanceList::addInstance(Instance * const instance) {
    if (!containsInstance(instance)) {
        instances->push_back(instance);
        return true;
    } else {
        return false;
    }
}

vector<Instance*> const * const InstanceList::getInstances() const {
    return instances;
}

bool const InstanceList::containsInstance(
        Instance const * const instance) const {
    for (int i = 0; i < instances->size(); i++) {
        if (instance == instances->at(i)) {
            return true;
        }
    }
    return false;
}

int const InstanceList::getSize() const {
    return instances->size();
}

Pipe const * const InstanceList::getPipe() const {
    return pipe.get();
}

bool const InstanceList::setPipe(auto_ptr<Pipe> pipe) {
    InstanceList::pipe = pipe;
    return true;
}

Alphabet const * const InstanceList::getDataAlphabet() const {
    return pipe->getDataAlphabet();
}

Alphabet const * const InstanceList::getTargetAlphabet() const {
    return pipe->getTargetAlphabet();
}
