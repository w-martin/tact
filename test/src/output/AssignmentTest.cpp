/**
 * @file AssignmentTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#define testWord "testWord"

#include "gtest/gtest.h"
#include "tmte-cpp/output/Assignment.h"

namespace {

    /**
     * Tests Assignment.
     * 
     */
    class AssignmentTest : public ::testing::Test {
    protected:

        AssignmentTest() {
            assignment = new Assignment();
        }

        virtual ~AssignmentTest() {
            delete assignment;
        }
        Assignment * assignment;
    };

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(AssignmentTest, GetNameTest) {
        
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(AssignmentTest, CopyConstructorTest) {
        
    }
}
