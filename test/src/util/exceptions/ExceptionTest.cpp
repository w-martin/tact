/**
 * @file ExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.0
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
#include "mewt/util/exceptions/Exception.h"

#define message "test message"

namespace {

    /**
     * Tests Exception.
     * 
     */
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
