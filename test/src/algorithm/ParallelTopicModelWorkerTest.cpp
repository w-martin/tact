/**
 * @file ParallelTopicModelWorkerTest.cpp
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
#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"

namespace {

    /**
     * Tests ParallelTopicModelWorkerTest.
     * 
     */
    class ParallelTopicModelWorkerTest : public ::testing::Test {
    protected:

        ParallelTopicModelWorkerTest() {
            worker = new ParallelTopicModelWorker();
        }

        virtual ~ParallelTopicModelWorkerTest() {
            delete worker;
        }
        ParallelTopicModelWorker * worker;
    };

    /*
     * Tests whether the pass to the super constructor worked correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, SuperConstructionTest) {
        
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, CopyConstructorTest) {
        
    }
}
