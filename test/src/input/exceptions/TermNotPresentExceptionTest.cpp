/**
 * @file TermNotPresentExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "teflon/input/exceptions/TermNotPresentException.h"

#define message "test message"

namespace {

    /**
     * Tests TermNotPresentException.
     * 
     */
    class TermNotPresentExceptionTest : public ::testing::Test {
    protected:

        TermNotPresentExceptionTest() {
            testException = new TermNotPresentException(message);
        }

        virtual ~TermNotPresentExceptionTest() {
            delete testException;
        }
        TermNotPresentException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(TermNotPresentExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(TermNotPresentExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new TermNotPresentException();

        EXPECT_STREQ(TERM_NOT_PRESENT_MESSAGE, testException->what());
    }

    /*
     * Tests whether the specific message is generated correctly.
     * 
     */
    TEST_F(TermNotPresentExceptionTest, SpecificMessageTest) {
        delete testException;
        testException = new TermNotPresentException(message, false);

        char const * const whatMessage = testException->what();
        EXPECT_STRNE(NULL, whatMessage);
        EXPECT_STRNE(TERM_NOT_PRESENT_MESSAGE, whatMessage);
        EXPECT_STRNE(message, whatMessage);
        EXPECT_GT(strlen(whatMessage), 0);

        delete testException;
        testException = new TermNotPresentException(message, true);
        EXPECT_STREQ(message, testException->what());
    }
}
