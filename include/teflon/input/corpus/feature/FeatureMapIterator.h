/**
 * @file FeatureMapIterator.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef FEATUREMAPITERATOR_H
#define FEATUREMAPITERATOR_H

#include <map>

typedef std::map< int, int > intMapType;

/**
 * Iterates through FeatureMap entries.
 * 
 */
class FeatureMapIterator {
public:
    /**
     * Default constructor.
     * 
     * @param iter the iterator of the internal FeatureMap data representation.
     * 
     */
    FeatureMapIterator(intMapType::const_iterator const iter);
    /**
     * Copy constructor.
     * 
     * @param orig the FeatureMapIterator to copy from.
     * 
     */
    FeatureMapIterator(FeatureMapIterator const & orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~FeatureMapIterator();
    /**
     * Increments this FeatureMapIterator.
     * 
     * @return the next FeatureMapIterator.
     * 
     */
    FeatureMapIterator operator++();
    /**
     * Increments this FeatureMapIterator.
     * 
     * @param dummy variable.
     * @return the next FeatureMapIterator.
     * 
     */
    FeatureMapIterator operator++(int);
    /**
     * Checks if this FeatureMapIterator is equal to the given 
     * FeatureMapIterator.
     * 
     * @param other the FeatureMapIterator to compare against.
     * @return true if this FeatureMapIterator equals the given 
     * FeatureMapIterator, false otherwise.
     * 
     */
    bool const equals(FeatureMapIterator const & other) const;
    /**
     * Checks if this FeatureMapIterator is equal to the given 
     * FeatureMapIterator.
     * 
     * @param other the FeatureMapIterator to compare against.
     * @return true if this FeatureMapIterator equals the given 
     * FeatureMapIterator, false otherwise.
     * 
     */
    bool const operator==(FeatureMapIterator const & other) const;
    /**
     * Checks if this FeatureMapIterator is not equal to the given 
     * FeatureMapIterator.
     * 
     * @param other the FeatureMapIterator to compare against.
     * @return true if this FeatureMapIterator does not equal the given 
     * FeatureMapIterator, false otherwise.
     * 
     */
    bool const operator!=(FeatureMapIterator const & other) const;
    /**
     * Gets the feature at this iterator position.
     * 
     * @return the feature at this iterator position.
     * 
     */
    int const getFeature() const;
    /**
     * Gets the count at this iterator position.
     * 
     * @return the count at this iterator position.
     * 
     */
    int const getCount() const;
protected:
    /**
     * Gets the internal representation of data.
     * 
     * @return the internal representation of data.
     * 
     */
    intMapType::const_iterator const getIterator() const;
private:
    /** 
     * Internal representation of data.
     * 
     */
    intMapType::const_iterator iter;
};

#endif /* FEATUREMAPITERATOR_H */
