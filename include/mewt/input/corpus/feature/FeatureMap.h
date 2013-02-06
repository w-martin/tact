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

#include "mewt/input/corpus/feature/FeatureMapIterator.h"
#include <map>

using std::make_pair;
using std::map;
using std::pair;

namespace mewt {

  namespace input {

    namespace corpus {

      namespace feature {

        /**
         * FeatureMap class for storing a map of a Document's features.
         * 
         */
        class FeatureMap {
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
           * Gets the FeatureMapIterator that points to the start of this 
           * FeatureMap.
           * 
           * @return the FeatureMapIterator that points to the start of 
           * this FeatureMap.
           * 
           */
          FeatureMapIterator const begin() const;
          /**
           * Gets the FeatureMapIterator that points to the end of this 
           * FeatureMap.
           * 
           * @return the FeatureMapIterator that points to the end of this 
           * FeatureMap.
           * 
           */
          FeatureMapIterator const end() const;
          /**
           * Checks if this FeatureMap is equal to the given FeatureMap.
           * 
           * @param other the FeatureMap to compare against.
           * @return true if this FeatureMap is equal to the given 
           * FeatureMap, false otherwise.
           * 
           */
          bool const equals(FeatureMap const & other) const;
          /**
           * Checks if this FeatureMap is equal to the given FeatureMap.
           * 
           * @param other the FeatureMap to compare against.
           * @return true if this FeatureMap is equal to the given 
           * FeatureMap, false otherwise.
           * 
           */
          bool const operator==(FeatureMap const & other) const;
          /**
           * Checks if this FeatureMap is not equal to the given 
           * FeatureMap.
           * 
           * @param other the FeatureMap to compare against.
           * @return true if this FeatureMap is not equal to the given 
           * FeatureMap, false otherwise.
           * 
           */
          bool const operator!=(FeatureMap const & other) const;
          /**
           * Gets the count of the given feature.
           * 
           * @param featureID the feature to get.
           * @return the count of the given feature.
           * 
           */
          int const getFeature(int const & featureID) const;
          /**
           * Gets the number of distinct feature types present in this 
           * FeatureMap.
           * 
           * @return the number of distinct feature types present in this 
           * FeatureMap.
           * 
           */
          int const getSize() const;
          /**
           * Increments the count of the given feature, or adds it if it 
           * is not present.
           * 
           * @param featureID the feature to increment.
           * @param amount the amount to increment the feature by.
           * 
           */
          void incrementFeature(int const & featureID,
                  int const & amount);
          /**
           * Sets the given feature with the given count. Overwrites 
           * previous mapping if present.
           * 
           * @param feature the feature to add.
           * @param count the count of the given feature.
           * @return the previous mapping, or 0 if none was present.
           * 
           */
          int const setFeature(int const feature, int const count);
          /**
           * Removes the feature with the given feature ID.
           * 
           * @param featureID the ID of the feature to remove.
           * 
           */
          void removeFeature(int const & featureID);
        protected:
          /**
           * Gets the internal representation of data.
           * 
           */
          intMapType const * const getData() const;
        private:
          /**
           * Internal representation of data.
           * 
           */
          intMapType * data;
          /**
           * The total number of feature counts in the FeatureMap.
           * 
           */
          int size;
        };

      };

    };

  };

};

#endif	/* FEATUREMAP_H */
