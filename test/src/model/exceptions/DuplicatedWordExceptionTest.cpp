/**
 * @file DuplicatedWordExceptionTest.cpp
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
#include "tmte-cpp/model/exceptions/DuplicatedWordException.h"

#define message "test message"

namespace {

    /**
     * Tests DuplicatedWordException.
     * 
     */
    class DuplicatedWordExceptionTest : public ::testing::Test {
    protected:

        DuplicatedWordExceptionTest() {
            testException = new DuplicatedWordException(message);
        }

        virtual ~DuplicatedWordExceptionTest() {
            delete testException;
        }
        DuplicatedWordException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(DuplicatedWordExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(DuplicatedWordExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new DuplicatedWordException();

        EXPECT_STREQ(DUPLICATED_WORD_MESSAGE, testException->what());
    }

    /*
     * Tests whether the specific message is generated correctly.
     * 
     */
    TEST_F(DuplicatedWordExceptionTest, SpecificMessageTest) {
        delete testException;
        testException = new DuplicatedWordException(message, false);

        char const * const whatMessage = testException->what();
        EXPECT_STRNE(NULL, whatMessage);
        EXPECT_STRNE(DUPLICATED_WORD_MESSAGE, whatMessage);
        EXPECT_STRNE(message, whatMessage);
        EXPECT_GT(strlen(whatMessage), 0);

        delete testException;
        testException = new DuplicatedWordException(message, true);
        EXPECT_STREQ(message, testException->what());
    }
}
