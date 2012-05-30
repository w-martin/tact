/**
 * @file FeatureMap.h
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

#ifndef FEATUREMAP_H
#define	FEATUREMAP_H

#include <map>

using std::make_pair;
using std::map;
using std::pair;

/**
 * FeatureMap class for storing a map of a Document's features.
 * 
 */
class FeatureMap : private map< int, int > {
public:
    /**
     * Default constructor.
     * 
     * @param name the name of the file.
     * 
     */
    FeatureMap();
    /**
     * Copy constructor.
     * 
     * @param orig the FeatureMap to copy.
     * 
     */
    FeatureMap(const FeatureMap& orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~FeatureMap();
    /**
     * Adds the given feature to this FeatureMap if it is not already present.
     * 
     * @param feature the feature to add.
     * @param count the count of the given feature.
     * @return true if the feature was added, false otherwise.
     * 
     */
    bool const addFeature(int const feature, int const count);
    /**
     * Gets the count of the given feature.
     * 
     * @param featureID the feature to get.
     * @return the count of the given feature.
     * 
     */
    int const getFeature(int const & featureID) const;
    /**
     * Removes the feature with the given feature ID.
     * 
     * @param featureID the ID of the feature to remove.
     * 
     */
    void removeFeature(int const & featureID);
};

#endif	/* FEATUREMAP_H */
