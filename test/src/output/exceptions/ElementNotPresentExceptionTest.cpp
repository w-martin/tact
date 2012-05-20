/**
 * @file ElementNotPresentExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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
#include "mewt/output/exceptions/ElementNotPresentException.h"

#define message "test message"

namespace {

    /**
     * Tests ElementNotPresentException.
     * 
     */
    class ElementNotPresentExceptionTest : public ::testing::Test {
    protected:

        ElementNotPresentExceptionTest() {
            testException = new ElementNotPresentException(message);
        }

        virtual ~ElementNotPresentExceptionTest() {
            delete testException;
        }
        ElementNotPresentException *testException;
    };

    /*
     * Tests whether the <code>Exception</code>'s message was set correctly.
     * 
     */
    TEST_F(ElementNotPresentExceptionTest, MessageTest) {
        EXPECT_STREQ(message, testException->what());
    }

    /*
     * Tests whether the default message is set correctly.
     * 
     */
    TEST_F(ElementNotPresentExceptionTest, DefaultMessageTest) {
        delete testException;
        testException = new ElementNotPresentException();

        EXPECT_STREQ(ELEMENT_NOT_PRESENT_MESSAGE, testException->what());
    }
}
