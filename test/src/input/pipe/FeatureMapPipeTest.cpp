/**
 * @file FeatureMapPipeTest.cpp
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
#include "tact/input/pipe/FeatureMapPipe.h"
#include "tact/input/corpus/text/TextCorpus.h"
#include "tact/input/corpus/text/TextDocument.h"
#include "tact/input/corpus/feature/FeatureDocument.h"
#include "tact/input/corpus/feature/Alphabet.h"
#include "tact/input/corpus/feature/FeatureCorpus.h"

using std::auto_ptr;

namespace {

/**
 * Tests FeatureMapPipe.
 *
 */
class FeatureMapPipeTest : public ::testing::Test {
protected:

  FeatureMapPipeTest() {
    pipe = new FeatureMapPipe();
  }

  virtual ~FeatureMapPipeTest() {
    delete pipe;
  }
  FeatureMapPipe * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(FeatureMapPipeTest, ProcessExceptionTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".", DOCUMENT_TYPE_BASIC));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);

  corpus = auto_ptr< Corpus > (
             new Corpus(".", DOCUMENT_TYPE_FEATURE));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);
}

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(FeatureMapPipeTest, ProcessTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new TextCorpus("."));
  auto_ptr< string > text =
    auto_ptr< string > (new string("this is some text this"));
  corpus->addDocument(auto_ptr< Document > (
                        new TextDocument("CMakeCache.txt", text)));
  auto_ptr< Corpus > featureCorpus = pipe->pipe(corpus);

  FeatureDocument const * const onlyDocument =
    (FeatureDocument const * const) featureCorpus->
    getDocuments()->at(0);
  Alphabet const * const alphabet =
    ((FeatureCorpus *) featureCorpus.get())->getAlphabet();
  EXPECT_EQ(4, alphabet->getSize());
  FeatureMap const * const featureMap = onlyDocument->getFeatureMap();
  EXPECT_EQ(2, featureMap->getFeature(0));
  EXPECT_EQ(1, featureMap->getFeature(1));
  EXPECT_EQ(1, featureMap->getFeature(2));
  EXPECT_EQ(1, featureMap->getFeature(3));
  EXPECT_EQ(0, featureMap->getFeature(4));
}

/*
 * Tests whether the getDocumentTypes method works correctly.
 *
 */
TEST_F(FeatureMapPipeTest, GetDocumentTypesTest) {
  vector< int > const * compatibleTypes = pipe->getCompatibleTypes();
  EXPECT_EQ(1, compatibleTypes->size());
  EXPECT_EQ(DOCUMENT_TYPE_TEXT, compatibleTypes->at(0));
}
}
