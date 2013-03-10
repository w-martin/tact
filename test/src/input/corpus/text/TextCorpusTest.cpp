/**
 * @file TextCorpusTest.cpp
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
#include "teflon/input/corpus/text/TextCorpus.h"

namespace {

/**
 * Tests TextCorpus.
 *
 */
class TextCorpusTest : public ::testing::Test {
protected:

  TextCorpusTest() {
    location = "testLocation/";
    corpus = new TextCorpus(location);
  }

  virtual ~TextCorpusTest() {
    delete corpus;
  }
  TextCorpus * corpus;
  string location;
};

/*
 * Tests whether the documents type is set correctly.
 *
 */
TEST_F(TextCorpusTest, GetDocumentsTypeTest) {
  EXPECT_EQ(DOCUMENT_TYPE_TEXT, corpus->getDocumentsType());
}
}
