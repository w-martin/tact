/**
 * @file Instance.cpp
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

#include "mewt/input/Instance.h"

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
