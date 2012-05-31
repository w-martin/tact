/**
 * @file FeatureMap.cpp
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

#include "mewt/input/corpus/feature/FeatureMap.h"

FeatureMap::FeatureMap() : map() {
}

FeatureMap::FeatureMap(const FeatureMap& orig) : map(orig) {
}

FeatureMap::~FeatureMap() {
}

int const FeatureMap::getFeature(int const & featureID) const {
    const_iterator iter = find(featureID);
    if (end() == iter) {
        return 0;
    } else {
        return iter->second;
    }
}

int const FeatureMap::setFeature(const int feature, const int count) {
    int const previousCount = getFeature(feature);
    if (0 == count) {
        removeFeature(feature);
    } else {
        pair< int, int > p = make_pair(feature, count);
        insert(p);
    }
    return previousCount;
}

void FeatureMap::removeFeature(int const & featureID) {
    erase(featureID);
}
