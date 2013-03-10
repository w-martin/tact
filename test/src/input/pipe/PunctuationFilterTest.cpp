/**
 * @file PunctuationFilterTest.cpp
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
 *
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtest/gtest.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"
#include "teflon/input/corpus/text/TextDocument.h"
#include "teflon/input/pipe/PunctuationFilter.h"

namespace {

/**
 * Tests PunctuationFilter.
 *
 */
class PunctuationFilterTest : public ::testing::Test {
protected:

  PunctuationFilterTest() {
    pipe = new PunctuationFilter();
  }

  virtual ~PunctuationFilterTest() {
    delete pipe;
  }
  PunctuationFilter * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(PunctuationFilterTest, ProcessExceptionTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".", DOCUMENT_TYPE_BASIC));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);

  corpus = auto_ptr< Corpus > (
             new Corpus(".", DOCUMENT_TYPE_TEXT));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);
}

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(PunctuationFilterTest, ProcessTest) {
  auto_ptr< Corpus > corpus =
    auto_ptr< Corpus > (FeatureCorpus::createInstance("."));
  Alphabet * alphabet =
    ((FeatureCorpus *) corpus.get())->getAlphabet();
  string const abbrieviated = "don't'";
  string const fragmented = "({hello&£$%^world\\/()})";
  string const empty = ";'[]@£$%^&*(<>?:";
  int const index1 = alphabet->addTerm(abbrieviated);
  int const index2 = alphabet->addTerm(fragmented);
  int const index3 = alphabet->addTerm(empty);

  auto_ptr< FeatureMap > featureMap =
    auto_ptr< FeatureMap > (new FeatureMap());
  featureMap->incrementFeature(index1, 5);
  featureMap->incrementFeature(index2, 10);
  featureMap->incrementFeature(index3, 15);
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
  EXPECT_FALSE(alphabet->hasTerm(abbrieviated));
  EXPECT_FALSE(alphabet->hasTerm(fragmented));
  EXPECT_FALSE(alphabet->hasTerm(empty));
  EXPECT_TRUE(alphabet->hasTerm("dont"));
  EXPECT_TRUE(alphabet->hasTerm("hello"));
  EXPECT_TRUE(alphabet->hasTerm("world"));
  EXPECT_EQ(5, map->getFeature(alphabet->getIndex("dont")));
  EXPECT_EQ(10, map->getFeature(alphabet->getIndex("hello")));
  EXPECT_EQ(10, map->getFeature(alphabet->getIndex("world")));
}

/*
 * Tests whether the removePunctuation method work correctly.
 *
 */
TEST_F(PunctuationFilterTest, RemovePunctuationTest) {
  string term = "this;][$%^&*is()`m'y!term)(";
  vector< string > splitTerm =
    PunctuationFilter::removePunctuation(term);
  EXPECT_EQ(4, splitTerm.size());
  EXPECT_STREQ("this", splitTerm[0].c_str());
  EXPECT_STREQ("is", splitTerm[1].c_str());
  EXPECT_STREQ("my", splitTerm[2].c_str());
  EXPECT_STREQ("term", splitTerm[3].c_str());

  string const abbrieviated = "don't'";
  string const fragmented = "({hello&£$%^world\\/()})";
  string const empty = ";'[]@£$%^&*(<>?:";
  splitTerm = PunctuationFilter::removePunctuation(abbrieviated);
  EXPECT_EQ(1, splitTerm.size());
  EXPECT_STREQ("dont", splitTerm[0].c_str());
  splitTerm = PunctuationFilter::removePunctuation(fragmented);
  EXPECT_EQ(2, splitTerm.size());
  EXPECT_STREQ("hello", splitTerm[0].c_str());
  EXPECT_STREQ("world", splitTerm[1].c_str());
  splitTerm = PunctuationFilter::removePunctuation(empty);
  EXPECT_EQ(0, splitTerm.size());
}
}
