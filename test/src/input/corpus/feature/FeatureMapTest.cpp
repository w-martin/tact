/**
 * @file FeatureMapTest.cpp
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

#include "gtest/gtest.h"
#include "mewt/input/corpus/feature/FeatureMap.h"

namespace {

    /**
     * Tests FeatureMap.
     * 
     */
    class FeatureMapTest : public ::testing::Test {
    protected:

        FeatureMapTest() {
            featureMap = new FeatureMap();
        }

        virtual ~FeatureMapTest() {
            delete featureMap;
        }
        FeatureMap * featureMap;
    };

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(FeatureMapTest, CopyConstructorTest) {
        FeatureMap tmp(*featureMap);
        EXPECT_EQ(tmp, *featureMap);
    }

    /*
     * Tests whether the equals methods work correctly.
     * 
     */
    TEST_F(FeatureMapTest, EqualsTest) {
        FeatureMap tmp(*featureMap);
        EXPECT_TRUE(tmp.equals(*featureMap));
        EXPECT_EQ(tmp, *featureMap);
        EXPECT_FALSE(tmp != *featureMap);

        featureMap->setFeature(0, 10);
        EXPECT_FALSE(tmp.equals(*featureMap));
        EXPECT_NE(tmp, *featureMap);
        EXPECT_TRUE(tmp != *featureMap);

        tmp.setFeature(0, 1);
        EXPECT_FALSE(tmp.equals(*featureMap));
        EXPECT_NE(tmp, *featureMap);
        EXPECT_TRUE(tmp != *featureMap);

        tmp.incrementFeature(0, 9);
        EXPECT_TRUE(tmp.equals(*featureMap));
        EXPECT_EQ(tmp, *featureMap);
        EXPECT_FALSE(tmp != *featureMap);

        featureMap->incrementFeature(1, 1);
        EXPECT_FALSE(tmp.equals(*featureMap));
        EXPECT_NE(tmp, *featureMap);
        EXPECT_TRUE(tmp != *featureMap);

        tmp.incrementFeature(1, 1);
        EXPECT_TRUE(tmp.equals(*featureMap));
        EXPECT_EQ(tmp, *featureMap);
        EXPECT_FALSE(tmp != *featureMap);
    }

    /*
     * Tests whether the getFeature method works correctly.
     * 
     */
    TEST_F(FeatureMapTest, GetFeatureTest) {
        EXPECT_EQ(0, featureMap->getFeature(0));
        featureMap->setFeature(0, 10);
        EXPECT_EQ(10, featureMap->getFeature(0));
    }

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(FeatureMapTest, GetsSizeTest) {
        EXPECT_EQ(0, featureMap->getSize());
        featureMap->incrementFeature(0, 1);
        EXPECT_EQ(1, featureMap->getSize());
        featureMap->incrementFeature(0, 1);
        EXPECT_EQ(1, featureMap->getSize());
        featureMap->incrementFeature(1, 1);
        EXPECT_EQ(2, featureMap->getSize());
    }

    /*
     * Tests whether the incrementFeature method works correctly.
     * 
     */
    TEST_F(FeatureMapTest, IncrementFeatureTest) {
        EXPECT_EQ(0, featureMap->getFeature(0));
        featureMap->incrementFeature(0, 1);
        EXPECT_EQ(1, featureMap->getFeature(0));
        featureMap->incrementFeature(0, 32);
        EXPECT_EQ(33, featureMap->getFeature(0));
    }

    /*
     * Tests whether the removeFeature method works correctly.
     * 
     */
    TEST_F(FeatureMapTest, RemoveFeatureTest) {
        featureMap->setFeature(0, 10);
        featureMap->removeFeature(0);
        EXPECT_EQ(0, featureMap->getFeature(0));
    }

    /*
     * Tests whether the setFeature method works correctly.
     * 
     */
    TEST_F(FeatureMapTest, SetFeatureTest) {
        EXPECT_EQ(0, featureMap->setFeature(0, 10));
        EXPECT_EQ(10, featureMap->setFeature(0, 10));
        EXPECT_EQ(0, featureMap->setFeature(1, 10));
    }
}
