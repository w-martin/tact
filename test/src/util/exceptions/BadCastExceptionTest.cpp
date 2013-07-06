/**
 * @file BadCastExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtest/gtest.h"
#include "tact/util/exceptions/BadCastException.h"

namespace {

/**
 * Tests BadCastException.
 *
 */
class BadCastExceptionTest : public ::testing::Test {
protected:

  BadCastExceptionTest() {
    exception = new BadCastException();
  }

  virtual ~BadCastExceptionTest() {
    delete exception;
  }
  BadCastException * exception;
};

/*
 * Tests whether the default constructor work correctly.
 *
 */
TEST_F(BadCastExceptionTest, DefaultConstructorTest) {
  EXPECT_STREQ(BAD_CAST_MESSAGE, exception->what());
}

/*
 * Tests whether the specific constructor work correctly.
 *
 */
TEST_F(BadCastExceptionTest, SpecificConstructorTest) {
  string message = "bad cast!!!";
  delete exception;
  exception = new BadCastException(message);
  EXPECT_STREQ(message.c_str(), exception->what());
}
}
