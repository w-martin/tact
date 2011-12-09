/**
 * @file LatentDirichletAllocationTest.cpp
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
     * Tests LatentDirichletAllocation.
     * 
     */
    class LatentDirichletAllocationTest : public ::testing::Test {
    protected:

        LatentDirichletAllocationTest() {
            noIterations = 5;
            noTopics = 100;
            lda = new LatentDirichletAllocation(noIterations, noTopics);
        }

        virtual ~LatentDirichletAllocationTest() {
            delete lda;
        }
        LatentDirichletAllocation * lda;
        int noIterations;
        int noTopics;
    };

    /*
     * Tests whether the pass to the super constructor worked correctly.
     * 
     */
    TEST_F(LatentDirichletAllocationTest, SuperConstructionTest) {
        EXPECT_EQ(noIterations, lda->getNoIterations());
        EXPECT_EQ(noTopics, lda->getNoTopics());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(LatentDirichletAllocationTest, CopyConstructorTest) {
        LatentDirichletAllocation tmp = (*lda);
        EXPECT_EQ(noIterations, tmp.getNoIterations());
        EXPECT_EQ(noTopics, tmp.getNoTopics());
    }
}
