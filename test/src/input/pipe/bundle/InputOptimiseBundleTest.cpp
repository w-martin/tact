/**
 * @file InputOptimiseBundleTest.cpp
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
#include "teflon/input/pipe/bundle/InputOptimiseBundle.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"

namespace {

/**
 * Tests InputOptimiseBundle.
 *
 */
class InputOptimiseBundleTest : public ::testing::Test {
protected:

  InputOptimiseBundleTest() {
    pipe = new InputOptimiseBundle();
  }

  virtual ~InputOptimiseBundleTest() {
    delete pipe;
  }
  InputOptimiseBundle * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(InputOptimiseBundleTest, ProcessTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".", DOCUMENT_TYPE_BASIC));
  auto_ptr< Document > document = auto_ptr< Document > (
                                    new Document("CMakeCache.txt"));
  corpus->addDocument(document);

  corpus = pipe->pipe(corpus);
  EXPECT_EQ(1, corpus->getSize());
  EXPECT_LT(0, ((FeatureCorpus *) corpus.get())->
            getAlphabet()->getSize());
}
}
