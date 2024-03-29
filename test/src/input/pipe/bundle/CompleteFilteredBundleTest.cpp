/**
 * @file CompleteFilteredBundleTest.cpp
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
#include "tact/input/pipe/bundle/CompleteFilteredBundle.h"
#include "tact/input/corpus/Document.h"
#include "tact/input/corpus/feature/FeatureCorpus.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

/**
 * Tests CompleteFilteredBundle.
 *
 */
class CompleteFilteredBundleTest : public ::testing::Test {
protected:

  CompleteFilteredBundleTest() {
    pipe = new CompleteFilteredBundle("CTestTestfile.cmake");
  }

  virtual ~CompleteFilteredBundleTest() {
    delete pipe;
  }
  CompleteFilteredBundle * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(CompleteFilteredBundleTest, ProcessTest) {
  string const file1 = ".CompleteFilteredBundleTest/file1";
  string const file2 = ".CompleteFilteredBundleTest/dir/file2";
  fs::create_directories(".CompleteFilteredBundleTest/dir");
  fs::copy_file("CTestTestfile.cmake", file1);
  fs::copy_file("CTestTestfile.cmake", file2);

  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".CompleteFilteredBundleTest",
                                    DOCUMENT_TYPE_BASIC));
  corpus = pipe->pipe(corpus);
  EXPECT_EQ(2, corpus->getSize());
  vector< Document * > const * documents = corpus->getDocuments();
  EXPECT_TRUE(file1 == documents->at(0)->getName()
              || file1 == documents->at(1)->getName());
  EXPECT_TRUE(file2 == documents->at(0)->getName()
              || file2 == documents->at(1)->getName());
  FeatureCorpus const * const featureCorpus =
    (FeatureCorpus *) corpus.get();
  EXPECT_EQ(0, featureCorpus->getAlphabet()->getSize());

  fs::remove_all(".CompleteFilteredBundleTest");
}
}
