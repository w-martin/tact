/**
 * @file ParallelTopicModelTest.cpp
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
#include "tmte-cpp/main/algorithm/LatentDirichletAllocation.h"

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
