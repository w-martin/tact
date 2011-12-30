/**
 * @file RandomNumberGeneratorTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/algorithm/RandomNumberGenerator.h"

namespace {

    /**
     * Tests RandomNumberGenerator.
     * 
     */
    class RandomNumberGeneratorTest : public ::testing::Test {
    protected:

        RandomNumberGeneratorTest() {
            seed = 15;
            generator = new RandomNumberGenerator(seed);
        }

        virtual ~RandomNumberGeneratorTest() {
            delete generator;
        }

        RandomNumberGenerator * generator;
        int seed;
    };

    /*
     * Tests whether the getSeed method works correctly.
     * 
     */
    TEST_F(RandomNumberGeneratorTest, GetSeedTest) {
        EXPECT_EQ(seed, generator->getSeed());
    }

    /*
     * Tests whether the nextUniform method works correctly.
     * 
     */
    TEST_F(RandomNumberGeneratorTest, NextUniformTest) {
        double r1 = generator->nextUniform();
        EXPECT_GE(r1, 0);
        EXPECT_LE(r1, 1);
        double r2 = generator->nextUniform();
        EXPECT_GE(r2, 0);
        EXPECT_LE(r2, 1);
        EXPECT_NE(r1, r2);
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(RandomNumberGeneratorTest, CopyConstructorTest) {
        RandomNumberGenerator tmp(*generator);
        EXPECT_EQ(seed, tmp.getSeed());
    }
}
