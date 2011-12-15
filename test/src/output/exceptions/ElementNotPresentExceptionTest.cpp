/**
 * @file ElementNotPresentExceptionTest.cpp
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
#include "tmte-cpp/output/exceptions/ElementNotPresentException.h"

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
