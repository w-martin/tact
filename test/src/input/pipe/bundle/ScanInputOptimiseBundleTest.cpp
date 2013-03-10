/**
 * @file ScanInputOptimiseBundleTest.cpp
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
#include "teflon/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

/**
 * Tests ScanInputOptimiseBundle.
 *
 */
class ScanInputOptimiseBundleTest : public ::testing::Test {
protected:

  ScanInputOptimiseBundleTest() {
    pipe = new ScanInputOptimiseBundle();
  }

  virtual ~ScanInputOptimiseBundleTest() {
    delete pipe;
  }
  ScanInputOptimiseBundle * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(ScanInputOptimiseBundleTest, ProcessTest) {
  string const file1 = ".ScanInputOptimiseBundleTest/file1";
  string const file2 = ".ScanInputOptimiseBundleTest/dir/file2";
  fs::create_directories(".ScanInputOptimiseBundleTest/dir");
  fs::copy_file("CTestTestfile.cmake", file1);
  fs::copy_file("CTestTestfile.cmake", file2);

  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".ScanInputOptimiseBundleTest",
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
  EXPECT_LT(0, featureCorpus->getAlphabet()->getSize());

  fs::remove_all(".ScanInputOptimiseBundleTest");
}
}
