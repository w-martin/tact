/**
 * @file LDATest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
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
#include "tact/algorithm/LDA.h"
#include "tact/input/corpus/feature/MockFeatureCorpus.h"
#include "tact/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

/**
 * Tests LDA.
 *
 */
class LDATest : public ::testing::Test {
protected:

  LDATest() {
    alpha = 0.56;
    beta = 0.65;
    noTopics = 23;
    lda = new LDA(alpha, beta,
                  auto_ptr< Corpus > (new MockFeatureCorpus()), noTopics);
  }

  virtual ~LDATest() {
    delete lda;
  }
  LDA * lda;
  double alpha, beta;
  int noTopics;
};

/*
 * Tests whether the estimate method works correctly.
 *
 */
TEST_F(LDATest, EstimateTest) {
  int const noIterations = 53;
  string const outputDirectory = ".EstimateTest";
  int const saveInterval = 10;
  lda->estimate(noIterations, outputDirectory, saveInterval);
  EXPECT_EQ(noIterations, lda->getNoIterationsCompleted());
  fs::remove_all(outputDirectory);
}
}
