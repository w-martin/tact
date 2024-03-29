/**
 * @file LowerCasePipeTest.cpp
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

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtest/gtest.h"
#include "tact/input/pipe/LowerCasePipe.h"
#include "tact/input/corpus/feature/FeatureDocument.h"
#include "tact/input/corpus/feature/FeatureCorpus.h"
#include "tact/input/corpus/text/TextDocument.h"

namespace {

/**
 * Tests LowerCasePipe.
 *
 */
class LowerCasePipeTest : public ::testing::Test {
protected:

  LowerCasePipeTest() {
    pipe = new LowerCasePipe();
  }

  virtual ~LowerCasePipeTest() {
    delete pipe;
  }
  LowerCasePipe * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(LowerCasePipeTest, ProcessExceptionTest) {
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
TEST_F(LowerCasePipeTest, ProcessTest) {
  auto_ptr< Corpus > corpus =
    auto_ptr< Corpus > (FeatureCorpus::createInstance("."));
  Alphabet * alphabet =
    ((FeatureCorpus *) corpus.get())->getAlphabet();
  string const LARGE = "LARGE";
  string const small = "small";
  string const large = "large";
  int const index1 = alphabet->addTerm(LARGE);
  int const index2 = alphabet->addTerm(small);
  int const index3 = alphabet->addTerm(large);

  auto_ptr< FeatureMap > featureMap =
    auto_ptr< FeatureMap > (new FeatureMap());
  featureMap->incrementFeature(index1, 5);
  featureMap->incrementFeature(index2, 10);
  auto_ptr< Document > document =
    auto_ptr< Document > (new FeatureDocument("doc", featureMap));
  corpus->addDocument(document);

  corpus = pipe->pipe(corpus);
  FeatureCorpus * featureCorpus = (FeatureCorpus *) corpus.get();
  alphabet = featureCorpus->getAlphabet();
  FeatureMap const * const map =
    ((FeatureDocument *) featureCorpus->getDocuments()
     ->at(0))->getFeatureMap();

  EXPECT_EQ(2, alphabet->getSize());
  EXPECT_FALSE(alphabet->hasTerm(LARGE));
  EXPECT_TRUE(alphabet->hasTerm(small));
  EXPECT_TRUE(alphabet->hasTerm(large));
  EXPECT_EQ(0, map->getFeature(index1));
  EXPECT_EQ(10, map->getFeature(index2));
  EXPECT_EQ(5, map->getFeature(index3));
}

/*
 * Tests whether the getDocumentTypes method works correctly.
 *
 */
TEST_F(LowerCasePipeTest, GetDocumentTypesTest) {
  vector< int > const * compatibleTypes = pipe->getCompatibleTypes();
  EXPECT_EQ(1, compatibleTypes->size());
  EXPECT_EQ(DOCUMENT_TYPE_FEATURE, compatibleTypes->at(0));
}
}
