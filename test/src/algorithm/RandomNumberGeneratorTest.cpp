/**
 * @file RandomNumberGeneratorTest.cpp
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
#include "mewt/algorithm/RandomNumberGenerator.h"

using mewt::algorithm::RandomNumberGenerator;

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
