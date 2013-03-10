/**
 * @file IdentifierTest.cpp
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

#define testWord "1"

#include "gtest/gtest.h"
#include "teflon/output/Identifier.h"

namespace {

/**
 * Tests Identifier.
 *
 */
class IdentifierTest : public ::testing::Test {
protected:

  IdentifierTest() {
    identifier = new Identifier(testWord);
  }

  virtual ~IdentifierTest() {
    delete identifier;
  }
  Identifier * identifier;
};

/*
 * Tests whether the getName method works correctly.
 *
 */
TEST_F(IdentifierTest, GetNameTest) {
  EXPECT_STREQ(testWord, identifier->getName().c_str());
}

/*
 * Tests whether the less than operator works correctly.
 *
 */
TEST_F(IdentifierTest, LessThanOperatorTest) {
  Identifier different("0");
  EXPECT_TRUE(different < (*identifier));
  EXPECT_FALSE((*identifier) < (*identifier));
}

/*
 * Tests whether the not equal to operator works correctly.
 *
 */
TEST_F(IdentifierTest, NotEqualToOperatorTest) {
  Identifier different("0");
  EXPECT_TRUE(different != (*identifier));
  EXPECT_FALSE((*identifier) != (*identifier));
}

/*
 * Tests whether the equal to operator works correctly.
 *
 */
TEST_F(IdentifierTest, EqualToOperatorTest) {
  Identifier different("0");
  EXPECT_FALSE(different == (*identifier));
  EXPECT_TRUE((*identifier) == (*identifier));
}

/*
 * Tests whether the equals method works correctly.
 *
 */
TEST_F(IdentifierTest, EqualsTest) {
  Identifier const same(testWord);
  Identifier const different("different");
  EXPECT_TRUE(identifier->equals(same));
  EXPECT_FALSE(identifier->equals(different));
}

/*
 * Tests whether the copy constructor works correctly.
 *
 */
TEST_F(IdentifierTest, CopyConstructorTest) {
  Identifier * tmp = new Identifier(*identifier);
  EXPECT_STREQ(testWord, tmp->getName().c_str());
  delete tmp;
}
}
