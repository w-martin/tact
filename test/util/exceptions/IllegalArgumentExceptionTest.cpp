/**
 * @file IllegalArgumentExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 *
 * @section DESCRIPTION
 *
 * Tests IllegalArgumentException.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/main/util/exceptions/IllegalArgumentException.h"

#define message "test message"

namespace {

    class IllegalArgumentExceptionTest : public ::testing::Test {
    protected:

        IllegalArgumentExceptionTest() {
            testException = new IllegalArgumentException(message);
        }

        virtual ~IllegalArgumentExceptionTest() {
            delete testException;
        }
        IllegalArgumentException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(IllegalArgumentExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(IllegalArgumentExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new IllegalArgumentException();

        EXPECT_STREQ(ILLEGAL_ARGUMENT_MESSAGE, testException->what());
    }
}
