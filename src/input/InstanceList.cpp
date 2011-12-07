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
#include "tmte-cpp/main/model/Alphabet.h"

InstanceList::InstanceList(auto_ptr<Pipe> pipe) {
    InstanceList::pipe = pipe;
    dataAlphabet = pipe->getDataAlphabet();
    targetAlphabet = pipe->getTargetAlphabet();
    instances = new vector<Instance>();
}

InstanceList::InstanceList(const InstanceList& orig) {
    pipe = auto_ptr<Pipe>(new Pipe(*orig.getPipe()));
    dataAlphabet = pipe->getDataAlphabet();
    targetAlphabet = pipe->getTargetAlphabet();
    instances = new vector<Instance>(*orig.getInstances());  
}

InstanceList::~InstanceList() {
    delete instances;
}

vector<Instance> const * const InstanceList::getInstances() const {
    return instances;
}

Pipe const * const InstanceList::getPipe() const {
    return pipe.get();
}

bool const InstanceList::setPipe(auto_ptr<Pipe> pipe) {
    InstanceList::pipe = pipe;
    dataAlphabet = pipe->getDataAlphabet();
    targetAlphabet = pipe->getTargetAlphabet();
    return true;
}

bool const InstanceList::addInstance(Instance const & instance) {
    instances->push_back(instance);
    return true;
}

Alphabet const * const InstanceList::getDataAlphabet() const {
    return dataAlphabet;
}

Alphabet const * const InstanceList::getTargetAlphabet() const {
    return targetAlphabet;
}
