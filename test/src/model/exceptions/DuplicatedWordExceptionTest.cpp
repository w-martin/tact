/**
 * @file DuplicatedWordExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
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
