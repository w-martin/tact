/**
 * @file FeatureMapIterator.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/corpus/feature/FeatureMapIterator.h"

FeatureMapIterator::FeatureMapIterator(const intMapType::const_iterator iter) {
    FeatureMapIterator::iter = iter;
}

FeatureMapIterator::FeatureMapIterator(FeatureMapIterator const & orig) {
    iter = orig.getIterator();
}

FeatureMapIterator::~FeatureMapIterator() {
}

FeatureMapIterator FeatureMapIterator::operator ++() {
    iter++;
    return *this;
}

FeatureMapIterator FeatureMapIterator::operator ++(int) {
    FeatureMapIterator dummy(iter);
    ++(*this);
    return dummy;
}

bool const FeatureMapIterator::equals(FeatureMapIterator const & other) const {
    return iter == other.getIterator();
}

bool const FeatureMapIterator::operator ==(
        FeatureMapIterator const & other) const {
    return equals(other);
}

bool const FeatureMapIterator::operator !=(
        FeatureMapIterator const & other) const {
    return !equals(other);
}

int const FeatureMapIterator::getFeature() const {
    return iter->first;
}

int const FeatureMapIterator::getCount() const {
    return iter->second;
}

intMapType::const_iterator const FeatureMapIterator::getIterator() const {
    return iter;
}
