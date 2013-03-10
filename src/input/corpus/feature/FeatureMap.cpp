/**
 * @file FeatureMap.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 *
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "teflon/input/corpus/feature/FeatureMap.h"
#include "teflon/input/corpus/feature/FeatureMapIterator.h"

FeatureMap::FeatureMap() {
  data = new intMapType();
  size = 0;
}

FeatureMap::FeatureMap(const FeatureMap& orig) {
  data = new intMapType(*orig.getData());
  size = orig.getSize();
}

FeatureMap::~FeatureMap() {
  delete data;
}

FeatureMapIterator const FeatureMap::begin() const {
  return FeatureMapIterator(data->begin());
}

FeatureMapIterator const FeatureMap::end() const {
  return FeatureMapIterator(data->end());
}

bool const FeatureMap::equals(FeatureMap const & other) const {
  if (getSize() == other.getSize()) {
    FeatureMapIterator iter1 = begin();
    FeatureMapIterator iter2 = other.begin();
    while (end() != iter1
           && other.end() != iter2) {
      if(iter1.getFeature() != iter2.getFeature()
          || iter1.getCount() != iter2.getCount()) {
        return false;
      }
      iter1++;
      iter2++;
    }
  } else {
    return false;
  }
  return true;
}

bool const FeatureMap::operator ==(FeatureMap const & other) const {
  return equals(other);
}

bool const FeatureMap::operator !=(FeatureMap const & other) const {
  return !equals(other);
}

int const FeatureMap::getFeature(int const & featureID) const {
  intMapType::const_iterator iter = data->find(featureID);
  if (end() == iter) {
    return 0;
  } else {
    return iter->second;
  }
}

int const FeatureMap::getSize() const {
  return size;
}

void FeatureMap::incrementFeature(int const & featureID, int const & amount) {
  int const count = amount + getFeature(featureID);
  removeFeature(featureID);
  if (0 < count) {
    setFeature(featureID, count);
  }
}

int const FeatureMap::setFeature(const int feature, const int count) {
  int const previousCount = getFeature(feature);
  if (0 == count
      || 0 != previousCount) {
    removeFeature(feature);
  } else {
    pair< int, int > p = make_pair(feature, count);
    data->insert(p);
  }
  size += count - previousCount;
  return previousCount;
}

void FeatureMap::removeFeature(int const & featureID) {
  size -= getFeature(featureID);
  data->erase(featureID);
}

intMapType const * const FeatureMap::getData() const {
  return data;
}
