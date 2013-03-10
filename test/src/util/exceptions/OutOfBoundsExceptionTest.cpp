/**
 * @file OutOfBoundsExceptionTest.cpp
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
#include "teflon/util/exceptions/OutOfBoundsException.h"

#define message "test message"

namespace {

/**
 * Tests OutOfBoundsException.
 *
 */
class OutOfBoundsExceptionTest : public ::testing::Test {
protected:

  OutOfBoundsExceptionTest() {
    testException = new OutOfBoundsException(message);
  }

  virtual ~OutOfBoundsExceptionTest() {
    delete testException;
  }
  OutOfBoundsException *testException;
};

/*
 * Tests whether the <code>Exception</code>'s message was set correctly.
 *
 */
TEST_F(OutOfBoundsExceptionTest, MessageTest) {
  EXPECT_STREQ(message, testException->what());
}

/*
 * Tests whether the default message is set correctly.
 *
 */
TEST_F(OutOfBoundsExceptionTest, DefaultMessageTest) {
  delete testException;
  testException = new OutOfBoundsException();

  EXPECT_STREQ(OUT_OF_BOUNDS_MESSAGE, testException->what());
}

/*
 * Tests whether the specific message is generated correctly.
 *
 */
TEST_F(OutOfBoundsExceptionTest, SpecificMessageTest) {
  delete testException;
  testException = new OutOfBoundsException(5, 2);

  char const * const whatMessage = testException->what();
  EXPECT_STRNE(NULL, whatMessage);
  EXPECT_STRNE(OUT_OF_BOUNDS_MESSAGE, whatMessage);
  EXPECT_STRNE(message, whatMessage);
  EXPECT_GT(strlen(whatMessage), 0);
}
}
