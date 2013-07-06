/**
 * @file FeatureDocumentTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtest/gtest.h"
#include "tact/input/corpus/feature/FeatureDocument.h"
#include "tact/input/corpus/feature/MockFeatureDocument.h"

namespace {

/**
 * Tests FeatureDocument.
 *
 */
class FeatureDocumentTest : public ::testing::Test {
protected:

  FeatureDocumentTest() {
    name = "test name";
    featureMap = new FeatureMap();
    document = new FeatureDocument(
      name, auto_ptr< FeatureMap > (new FeatureMap(*featureMap)));
  }

  virtual ~FeatureDocumentTest() {
    delete document;
    delete featureMap;
  }
  FeatureDocument * document;
  string name;
  FeatureMap * featureMap;
};
};

/*
 * Tests whether the equals method works correctly.
 *
 */
TEST_F(FeatureDocumentTest, EqualsTest) {
  EXPECT_TRUE(document->equals(*document));
  EXPECT_EQ(*document, *document);
  EXPECT_FALSE(*document != *document);

  FeatureDocument * tmp = new FeatureDocument("different name",
      auto_ptr< FeatureMap > (new FeatureMap(*featureMap)));
  EXPECT_FALSE(document->equals(*tmp));
  EXPECT_NE(*document, *tmp);
  EXPECT_TRUE(*document != *tmp);

  delete tmp;
  tmp = new FeatureDocument(*document);
  EXPECT_TRUE(document->equals(*tmp));
  EXPECT_EQ(*document, *tmp);
  EXPECT_FALSE(*document != *tmp);

  document->getFeatureMap()->incrementFeature(0, 5);
  EXPECT_FALSE(document->equals(*tmp));
  EXPECT_NE(*document, *tmp);
  EXPECT_TRUE(*document != *tmp);

  tmp->getFeatureMap()->incrementFeature(0, 6);
  EXPECT_FALSE(document->equals(*tmp));
  EXPECT_NE(*document, *tmp);
  EXPECT_TRUE(*document != *tmp);

  document->getFeatureMap()->incrementFeature(0, 1);
  EXPECT_TRUE(document->equals(*tmp));
  EXPECT_EQ(*document, *tmp);
  EXPECT_FALSE(*document != *tmp);

  delete tmp;
}

/*
 * Tests whether the getName method works correctly.
 *
 */
TEST_F(FeatureDocumentTest, GetNameTest) {
  EXPECT_EQ(0, strcmp(name.c_str(), document->getName().c_str()));
}

/*
 * Tests whether the getText method works correctly.
 *
 */
TEST_F(FeatureDocumentTest, GetFeatureMapTest) {
  document->getFeatureMap();
}

/*
 * Tests whether the getName method works correctly.
 *
 */
TEST_F(FeatureDocumentTest, GetTypeTest) {
  EXPECT_EQ(DOCUMENT_TYPE_FEATURE, document->getType());
}

/*
 * Tests whether the copy constructor works correctly.
 *
 */
TEST_F(FeatureDocumentTest, CopyConstructorTest) {
  FeatureDocument tmp(*document);
  EXPECT_EQ(0, strcmp(name.c_str(), tmp.getName().c_str()));
}

/*
 * Tests whether the mock works correctly.
 *
 */
TEST_F(FeatureDocumentTest, MockTest) {
  EXPECT_TRUE((new MockFeatureDocument())->equals(
                *new MockFeatureDocument()));
  EXPECT_EQ(*new MockFeatureDocument(), *new MockFeatureDocument());
}
