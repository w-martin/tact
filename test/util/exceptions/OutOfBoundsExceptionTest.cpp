/**
 * @file OutOfBoundsExceptionTest.cpp
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
#include "tmte-cpp/main/util/exceptions/OutOfBoundsException.h"

#define message "test message"

namespace {

    /**
     * Tests OutOfBoundsException.
     * 
     */
    class OutOfBoundsExceptionTest : public ::testing::Test {
    protected:

        OutOfBoundsExceptionTest() {
            testException = new OutOfBoundsException(message);
        }

        virtual ~OutOfBoundsExceptionTest() {
            delete testException;
        }
        OutOfBoundsException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(OutOfBoundsExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(OutOfBoundsExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new OutOfBoundsException();

        EXPECT_STREQ(OUT_OF_BOUNDS_MESSAGE, testException->what());
    }

    /*
     * Tests whether the specific message is generated correctly.
     * 
     */
    TEST_F(OutOfBoundsExceptionTest, SpecificMessageTest) {
        delete testException;
        testException = new OutOfBoundsException(5, 2);

        char const * const whatMessage = testException->what();
        EXPECT_STRNE(NULL, whatMessage);
        EXPECT_STRNE(OUT_OF_BOUNDS_MESSAGE, whatMessage);
        EXPECT_STRNE(message, whatMessage);
        EXPECT_GT(strlen(whatMessage), 0);
    }
}
