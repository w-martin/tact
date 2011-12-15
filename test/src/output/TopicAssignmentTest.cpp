/**
 * @file TopicAssignmentTest.cpp
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
#include "tmte-cpp/output/TopicAssignment.h"

namespace {

    /**
     * Tests TopicAssignment.
     * 
     */
    class TopicAssignmentTest : public ::testing::Test {
    protected:

        TopicAssignmentTest() {
            testInstance = new Instance();
            assignment = new TopicAssignment(testInstance);
        }

        virtual ~TopicAssignmentTest() {
            delete assignment;
            delete testInstance;
        }
        TopicAssignment * assignment;
        Instance const * testInstance;
    };

    /*
     * Tests whether the getInstance method works correctly.
     * 
     */
    TEST_F(TopicAssignmentTest, GetInstanceTest) {
        EXPECT_EQ(testInstance, assignment->getInstance());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(TopicAssignmentTest, CopyConstructorTest) {
        TopicAssignment * tmp = new TopicAssignment(*assignment);
        EXPECT_EQ(testInstance, tmp->getInstance());
        delete tmp;
    }
}
