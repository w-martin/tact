/**
 * @file ParallelTopicModelTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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
#include "mewt/algorithm/ParallelTopicModel.h"

namespace {

    /**
     * Tests ParallelTopicModelTest.
     * 
     */
    class ParallelTopicModelTest : public ::testing::Test {
    protected:

        ParallelTopicModelTest() {
            noIterations = 5;
            noTopics = 100;
            noThreads = 8;
            lda = new ParallelTopicModel(
                    noIterations, noTopics, noThreads);
        }

        virtual ~ParallelTopicModelTest() {
            delete lda;
        }
        ParallelTopicModel * lda;
        int noIterations;
        int noTopics;
        int noThreads;
    };

    /*
     * Tests whether the pass to the super constructor worked correctly.
     * 
     */
    TEST_F(ParallelTopicModelTest, SuperConstructionTest) {
        EXPECT_EQ(noIterations, lda->getNoIterations());
        EXPECT_EQ(noTopics, lda->getNoTopics());
    }

    /*
     * Tests whether the getNoThreads method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelTest, GetNoThreadsTest) {
        EXPECT_EQ(noThreads, lda->getNoThreads());
    }

    /*
     * Tests whether the getNoIterations method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelTest, GetNoIterationsTest) {
        EXPECT_EQ(noIterations, lda->getNoIterations());
    }

    /*
     * Tests whether the pass to the estimate method correctly.
     * 
     */
    TEST_F(ParallelTopicModelTest, EstimateTest) {
        lda->estimate();
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(ParallelTopicModelTest, CopyConstructorTest) {
        ParallelTopicModel tmp = (*lda);
        EXPECT_EQ(noIterations, tmp.getNoIterations());
        EXPECT_EQ(noTopics, tmp.getNoTopics());
        EXPECT_EQ(noThreads, tmp.getNoThreads());
    }
}
