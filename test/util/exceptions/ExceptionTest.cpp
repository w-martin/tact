/**
 * @file ExceptionTest.cpp
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
 * Tests Exception.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/main/util/exceptions/Exception.h"

#define message "test message"

namespace {

    class ExceptionTest : public ::testing::Test {
    protected:

        ExceptionTest() {
            testException = new Exception(message);
        }

        virtual ~ExceptionTest() {
            delete testException;
        }
        Exception *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(ExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }
}
