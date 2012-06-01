/**
 * @file DuplicatedTermExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "mewt/input/corpus/feature/exceptions/DuplicatedTermException.h"

#define message "test message"

namespace {

    /**
     * Tests DuplicatedTermException.
     * 
     */
    class DuplicatedTermExceptionTest : public ::testing::Test {
    protected:

        DuplicatedTermExceptionTest() {
            testException = new DuplicatedTermException(message);
        }

        virtual ~DuplicatedTermExceptionTest() {
            delete testException;
        }
        DuplicatedTermException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(DuplicatedTermExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(DuplicatedTermExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new DuplicatedTermException();

        EXPECT_STREQ(DUPLICATED_TERM_MESSAGE, testException->what());
    }

    /*
     * Tests whether the specific message is generated correctly.
     * 
     */
    TEST_F(DuplicatedTermExceptionTest, SpecificMessageTest) {
        delete testException;
        testException = new DuplicatedTermException(message, false);

        char const * const whatMessage = testException->what();
        EXPECT_STRNE(NULL, whatMessage);
        EXPECT_STRNE(DUPLICATED_TERM_MESSAGE, whatMessage);
        EXPECT_STRNE(message, whatMessage);
        EXPECT_GT(strlen(whatMessage), 0);

        delete testException;
        testException = new DuplicatedTermException(message, true);
        EXPECT_STREQ(message, testException->what());
    }
}
