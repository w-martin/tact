/**
 * @file IllegalArgumentExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
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
#include "tmte-cpp/util/exceptions/IllegalArgumentException.h"

#define message "test message"

namespace {

    /**
     * Tests IllegalArgumentException.
     * 
     */
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
