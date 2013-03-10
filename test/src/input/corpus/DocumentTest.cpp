/**
 * @file DocumentTest.cpp
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
#include "teflon/input/corpus/Document.h"

namespace {

/**
 * Tests Document.
 *
 */
class DocumentTest : public ::testing::Test {
protected:

  DocumentTest() {
    name = "test name";
    document = new Document(name);
  }

  virtual ~DocumentTest() {
    delete document;
  }
  Document * document;
  string name;
};

/*
 * Tests whether the equals method works correctly.
 *
 */
TEST_F(DocumentTest, EqualsTest) {
  EXPECT_TRUE(document->equals(*document));
  EXPECT_EQ(*document, *document);
  EXPECT_FALSE(*document != *document);

  Document tmp("different name");
  EXPECT_FALSE(document->equals(tmp));
  EXPECT_NE(*document, tmp);
  EXPECT_TRUE(*document != tmp);
}

/*
 * Tests whether the getName method works correctly.
 *
 */
TEST_F(DocumentTest, GetNameTest) {
  EXPECT_EQ(0, strcmp(name.c_str(), document->getName().c_str()));
}

/*
 * Tests whether the getName method works correctly.
 *
 */
TEST_F(DocumentTest, GetTypeTest) {
  EXPECT_EQ(DOCUMENT_TYPE_BASIC, document->getType());
}

/*
 * Tests whether the copy constructor works correctly.
 *
 */
TEST_F(DocumentTest, CopyConstructorTest) {
  Document tmp(*document);
  EXPECT_EQ(0, strcmp(name.c_str(), tmp.getName().c_str()));
  EXPECT_EQ(document->getType(), tmp.getType());
}
}
