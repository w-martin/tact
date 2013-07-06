/**
 * @file DuplicateExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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
#include "tact/util/exceptions/DuplicateException.h"

#define message "test message"

namespace {

/**
 * Tests DuplicateException.
 *
 */
class DuplicateExceptionTest : public ::testing::Test {
protected:

  DuplicateExceptionTest() {
    exception = new DuplicateException(message);
  }

  virtual ~DuplicateExceptionTest() {
    delete exception;
  }
  DuplicateException * exception;
};

/*
 * Tests whether the default constructor works correctly.
 *
 */
TEST_F(DuplicateExceptionTest, DefaultConstructorTest) {
  delete exception;
  exception = new DuplicateException();
  EXPECT_STREQ(DUPLICATE_MESSAGE, exception->what());
}

/*
 * Tests whether the specific constructor works correctly.
 *
 */
TEST_F(DuplicateExceptionTest, SpecificConstructorTest) {
  EXPECT_STREQ(message, exception->what());
}
}
