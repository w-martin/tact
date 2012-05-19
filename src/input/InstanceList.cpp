/**
 * @file InstanceList.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
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
