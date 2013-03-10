/**
 * @file IncompatibleCorpusExceptionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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
#include "teflon/input/exceptions/IncompatibleCorpusException.h"
#include "teflon/input/corpus/Document.h"

#define message "test message"

namespace {

/**
 * Tests IncompatibleCorpusException.
 *
 */
class IncompatibleCorpusExceptionTest : public ::testing::Test {
protected:

  IncompatibleCorpusExceptionTest() {
    testException = new IncompatibleCorpusException(message);
  }

  virtual ~IncompatibleCorpusExceptionTest() {
    delete testException;
  }
  IncompatibleCorpusException *testException;
};

/*
 * Tests whether the <code>Exception</code>'s message was set correctly.
 *
 */
TEST_F(IncompatibleCorpusExceptionTest, MessageTest) {
  EXPECT_STREQ(message, testException->what());
}

/*
 * Tests whether the default message is set correctly.
 *
 */
TEST_F(IncompatibleCorpusExceptionTest, DefaultMessageTest) {
  delete testException;
  testException = new IncompatibleCorpusException();

  EXPECT_STREQ(INCOMPATIBLE_CORPUS_MESSAGE, testException->what());
}

/*
 * Tests whether the specific message is generated correctly.
 *
 */
TEST_F(IncompatibleCorpusExceptionTest, SpecificMessageTest) {
  delete testException;
  vector< int > * types = new vector< int >();
  types->push_back(0);
  testException = new IncompatibleCorpusException(0, types,
      "IncompatibleCorpusExceptionTest");

  char const * whatMessage = testException->what();
  EXPECT_STRNE(NULL, whatMessage);
  EXPECT_STRNE(INCOMPATIBLE_CORPUS_MESSAGE, whatMessage);
  EXPECT_STRNE(message, whatMessage);
  EXPECT_GT(strlen(whatMessage), 0);

  delete testException;
  testException = new IncompatibleCorpusException(0, 0,
      "IncompatibleCorpusExceptionTest");

  whatMessage = testException->what();
  EXPECT_STRNE(NULL, whatMessage);
  EXPECT_STRNE(INCOMPATIBLE_CORPUS_MESSAGE, whatMessage);
  EXPECT_STRNE(message, whatMessage);
  EXPECT_GT(strlen(whatMessage), 0);
}
}
