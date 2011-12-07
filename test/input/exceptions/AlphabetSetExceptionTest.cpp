/**
 * @file AlphabetSetExceptionTest.cpp
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
#include "tmte-cpp/main/input/exceptions/AlphabetSetException.h"

#define message "test message"

namespace {

    /**
     * Tests AlphabetSetException.
     * 
     */
    class AlphabetSetExceptionTest : public ::testing::Test {
    protected:

        AlphabetSetExceptionTest() {
            testException = new AlphabetSetException(message);
        }

        virtual ~AlphabetSetExceptionTest() {
            delete testException;
        }
        AlphabetSetException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(AlphabetSetExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(AlphabetSetExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new AlphabetSetException();

        EXPECT_STREQ(ALPHABET_SET_MESSAGE, testException->what());
    }
}
