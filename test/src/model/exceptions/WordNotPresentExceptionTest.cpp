/**
 * @file WordNotPresentExceptionTest.cpp
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
#include "tmte-cpp/model/exceptions/WordNotPresentException.h"

#define message "test message"

namespace {

    /**
     * Tests WordNotPresentException.
     * 
     */
    class WordNotPresentExceptionTest : public ::testing::Test {
    protected:

        WordNotPresentExceptionTest() {
            testException = new WordNotPresentException(message);
        }

        virtual ~WordNotPresentExceptionTest() {
            delete testException;
        }
        WordNotPresentException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(WordNotPresentExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(WordNotPresentExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new WordNotPresentException();

        EXPECT_STREQ(WORD_NOT_PRESENT_MESSAGE, testException->what());
    }

    /*
     * Tests whether the specific message is generated correctly.
     * 
     */
    TEST_F(WordNotPresentExceptionTest, SpecificMessageTest) {
        delete testException;
        testException = new WordNotPresentException(message, false);

        char const * const whatMessage = testException->what();
        EXPECT_STRNE(NULL, whatMessage);
        EXPECT_STRNE(WORD_NOT_PRESENT_MESSAGE, whatMessage);
        EXPECT_STRNE(message, whatMessage);
        EXPECT_GT(strlen(whatMessage), 0);

        delete testException;
        testException = new WordNotPresentException(message, true);
        EXPECT_STREQ(message, testException->what());
    }
}
