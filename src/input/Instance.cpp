/**
 * @file Instance.cpp
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