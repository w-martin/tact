/**
 * @file TopicModelTest.cpp
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
#include "teflon/model/TopicModel.h"
#include "teflon/input/corpus/feature/MockFeatureCorpus.h"
#include "teflon/model/MockTopicModel.h"

namespace {

/**
 * Tests TopicModel.
 *
 */
class TopicModelTest : public ::testing::Test {
protected:

  TopicModelTest() {
    alpha = 0.56;
    beta = 0.65;
    noTopics = 23;
    FeatureCorpus * corpus = new MockFeatureCorpus();
    corpus->addDocument(auto_ptr< Document > (
                          new MockFeatureDocument()));
    topicModel = new MockTopicModel(alpha, beta,
                                    auto_ptr< Corpus > (corpus), noTopics);
  }

  virtual ~TopicModelTest() {
    delete topicModel;
  }
  TopicModel * topicModel;
  double alpha, beta;
  int noTopics;
};
}

/*
 * Tests whether the getAlpha method works correctly.
 *
 */
TEST_F(TopicModelTest, GetAlphaTest) {
  EXPECT_EQ(alpha, topicModel->getAlpha());
}

/*
 * Tests whether the getBeta method works correctly.
 *
 */
TEST_F(TopicModelTest, GetBetaTest) {
  EXPECT_EQ(beta, topicModel->getBeta());
}

/*
 * Tests whether the getCorpus method works correctly.
 *
 */
TEST_F(TopicModelTest, GetCorpusTest) {
  FeatureCorpus const * const corpus = topicModel->getCorpus();
  EXPECT_EQ(1, corpus->getSize());
  EXPECT_EQ(0, corpus->getAlphabet()->getSize());
}

/*
 * Tests whether the getNoDocuments method works correctly.
 *
 */
TEST_F(TopicModelTest, GetNoDocumentsTest) {
  EXPECT_EQ(1, topicModel->getNoDocuments());
}

/*
 * Tests whether the getNoIterationsCompleted method works correctly.
 *
 */
TEST_F(TopicModelTest, GetNoIterationsCompletedTest) {
  EXPECT_EQ(0, topicModel->getNoIterationsCompleted());
}

/*
 * Tests whether the getNoTopics method works correctly.
 *
 */
TEST_F(TopicModelTest, GetNoTopicsTest) {
  EXPECT_EQ(noTopics, topicModel->getNoTopics());
}

/*
 * Tests whether the getTermTopicMatrix method works correctly.
 *
 */
TEST_F(TopicModelTest, GetTermTopicMatrixTest) {
  ProbabilityMatrix const * const matrix = topicModel->getTermTopicMatrix();
  EXPECT_EQ(noTopics, matrix->getNoRows());
  EXPECT_EQ(0, matrix->getNoColumns());
}

/*
 * Tests whether the getTopicDocumentMatrix method works correctly.
 *
 */
TEST_F(TopicModelTest, GetTopicDocumentMatrixTest) {
  ProbabilityMatrix const * const matrix =
    topicModel->getTopicDocumentMatrix();
  EXPECT_EQ(1, matrix->getNoRows());
  EXPECT_EQ(noTopics, matrix->getNoColumns());
}
