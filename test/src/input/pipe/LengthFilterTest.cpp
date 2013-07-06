/**
 * @file LengthFilterTest.cpp
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
#include "tact/input/corpus/feature/FeatureCorpus.h"
#include "tact/input/corpus/text/TextDocument.h"
#include "tact/input/pipe/LengthFilter.h"

namespace {

/**
 * Tests LengthFilter.
 *
 */
class LengthFilterTest : public ::testing::Test {
protected:

  LengthFilterTest() {
    length = 3;
    pipe = new LengthFilter(length);
  }

  virtual ~LengthFilterTest() {
    delete pipe;
  }
  LengthFilter * pipe;
  int length;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(LengthFilterTest, ProcessExceptionTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".", DOCUMENT_TYPE_BASIC));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);

  corpus = auto_ptr< Corpus > (
             new Corpus(".", DOCUMENT_TYPE_TEXT));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);
}

/*
 * Tests whether the getMinimumLength method works correctly.
 *
 */
TEST_F(LengthFilterTest, GetMinimumLengthTest) {
  EXPECT_EQ(length, pipe->getMinimumLength());
}

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(LengthFilterTest, ProcessTest) {
  auto_ptr< Corpus > corpus =
    auto_ptr< Corpus > (FeatureCorpus::createInstance("."));
  Alphabet * alphabet =
    ((FeatureCorpus *) corpus.get())->getAlphabet();
  string const one = "h";
  string const two = "he";
  string const three = "hel";
  string const four = "hell";
  string const five = "hello";
  int const index1 = alphabet->addTerm(one);
  int const index2 = alphabet->addTerm(two);
  int const index3 = alphabet->addTerm(three);
  int const index4 = alphabet->addTerm(four);
  int const index5 = alphabet->addTerm(five);

  auto_ptr< FeatureMap > featureMap =
    auto_ptr< FeatureMap > (new FeatureMap());
  featureMap->incrementFeature(index1, 5);
  featureMap->incrementFeature(index2, 10);
  featureMap->incrementFeature(index3, 15);
  featureMap->incrementFeature(index4, 20);
  featureMap->incrementFeature(index5, 25);
  auto_ptr< Document > document =
    auto_ptr< Document > (new FeatureDocument("doc", featureMap));
  corpus->addDocument(document);

  corpus = pipe->pipe(corpus);
  FeatureCorpus * featureCorpus = (FeatureCorpus *) corpus.get();
  alphabet = featureCorpus->getAlphabet();
  FeatureMap const * const map =
    ((FeatureDocument *) featureCorpus->getDocuments()
     ->at(0))->getFeatureMap();

  EXPECT_EQ(3, alphabet->getSize());
  EXPECT_FALSE(alphabet->hasTerm(one));
  EXPECT_FALSE(alphabet->hasTerm(two));
  EXPECT_TRUE(alphabet->hasTerm(three));
  EXPECT_TRUE(alphabet->hasTerm(four));
  EXPECT_TRUE(alphabet->hasTerm(five));
  EXPECT_EQ(15, map->getFeature(alphabet->getIndex(three)));
  EXPECT_EQ(20, map->getFeature(alphabet->getIndex(four)));
  EXPECT_EQ(25, map->getFeature(alphabet->getIndex(five)));
}
}
