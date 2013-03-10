/**
 * @file FeatureMapIteratorTest.cpp
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

#include "gtest/gtest.h"
#include "teflon/input/corpus/feature/FeatureMapIterator.h"
#include "teflon/input/corpus/feature/FeatureMap.h"

namespace {

/**
 * Tests FeatureMapIterator.
 *
 */
class FeatureMapIteratorTest : public ::testing::Test {
protected:

  FeatureMapIteratorTest() {
    featureMap = new FeatureMap();
    featureMap->incrementFeature(0, 1);
    featureMap->incrementFeature(1, 5);
  }

  virtual ~FeatureMapIteratorTest() {
    delete featureMap;
  }
  FeatureMap * featureMap;
};

/*
 * Tests whether the copy constructor work correctly.
 *
 */
TEST_F(FeatureMapIteratorTest, CopyConstructorTest) {
  FeatureMapIterator iter = featureMap->begin();
  FeatureMapIterator tmp(iter);
  EXPECT_EQ(iter.getFeature(), tmp.getFeature());
  EXPECT_EQ(iter.getCount(), tmp.getCount());
  EXPECT_EQ(iter, tmp);
}

/*
 * Tests whether the increment methods work correctly.
 *
 */
TEST_F(FeatureMapIteratorTest, IncrementTest) {
  FeatureMapIterator iter = featureMap->begin();
  iter++;
  iter++;
  EXPECT_TRUE(iter == featureMap->end());
  iter = featureMap->begin();
  ++iter;
  ++iter;
  EXPECT_TRUE(iter == featureMap->end());
}

/*
 * Tests whether the equals methods work correctly.
 *
 */
TEST_F(FeatureMapIteratorTest, EqualsTest) {
  FeatureMapIterator iter = featureMap->begin();
  FeatureMapIterator other = featureMap->begin();
  EXPECT_TRUE(iter.equals(other));
  EXPECT_TRUE(iter == other);
  EXPECT_FALSE(iter != other);

  iter++;
  EXPECT_FALSE(iter.equals(other));
  EXPECT_FALSE(iter == other);
  EXPECT_TRUE(iter != other);

  other++;
  EXPECT_TRUE(iter.equals(other));
  EXPECT_TRUE(iter == other);
  EXPECT_FALSE(iter != other);
}

/*
 * Tests whether the getFeature method works correctly.
 *
 */
TEST_F(FeatureMapIteratorTest, GetFeatureTest) {
  FeatureMapIterator iter = featureMap->begin();
  EXPECT_EQ(0, iter.getFeature());
  iter++;
  EXPECT_EQ(1, iter.getFeature());
}

/*
 * Tests whether the getCount method works correctly.
 *
 */
TEST_F(FeatureMapIteratorTest, GetCountTest) {
  FeatureMapIterator iter = featureMap->begin();
  EXPECT_EQ(1, iter.getCount());
  EXPECT_EQ(iter.getCount(), featureMap->getFeature(iter.getFeature()));
  iter++;
  EXPECT_EQ(5, iter.getCount());
  EXPECT_EQ(iter.getCount(), featureMap->getFeature(iter.getFeature()));
}
}
