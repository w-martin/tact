/**
 * @file AbstractTopicModelTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/algorithm/AbstractTopicModel.h"

namespace {

    /**
     * Tests TopicModel.
     * 
     */
    class AbstractTopicModelTest : public ::testing::Test {
    protected:

        AbstractTopicModelTest() {
            noIterations = 7;
            noTopics = 60;
            topicModel = new AbstractTopicModel(noIterations, noTopics);
        }

        virtual ~AbstractTopicModelTest() {
            delete topicModel;
        }
        AbstractTopicModel * topicModel;
        int noIterations;
        int noTopics;
    };

    /*
     * Tests whether the getNoIterations method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetNoIterationsTest) {
        EXPECT_EQ(noIterations, topicModel->getNoIterations());
    }

    /*
     * Tests whether the getNoTopics method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetNoTopicsTest) {
        EXPECT_EQ(noTopics, topicModel->getNoTopics());
    }

    /*
     * Tests whether the getAlpha method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetAlphaTest) {
        double const * const alpha = topicModel->getAlpha();
        for (int i = 0; i < noTopics; i++) {
            EXPECT_EQ(0.0, alpha[i]);
        }
    }

    /*
     * Tests whether the setAlpha method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, SetAlphaTest) {
        double value = 0.456;
        topicModel->setAlpha(noTopics - 1, value);
        EXPECT_EQ(value, topicModel->getAlpha()[noTopics - 1]);
        EXPECT_EQ(value, topicModel->getAlphaSum());
    }

    /*
     * Tests whether the setAlpha method throws an exception correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, SetAlphaExceptionTest) {
        EXPECT_THROW(topicModel->setAlpha(noTopics, 0.0),
                OutOfBoundsException);
    }

    /*
     * Tests whether the getAlphaSum method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetAlphaSumTest) {
        EXPECT_EQ(0.0, topicModel->getAlphaSum());
    }

    /*
     * Tests whether the getBeta method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetBetaTest) {
        EXPECT_EQ(DEFAULT_BETA, topicModel->getBeta());
    }

    /*
     * Tests whether the setBeta method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, SetBetaTest) {
        double value = 0.876;
        topicModel->setBeta(value);
        EXPECT_EQ(value, topicModel->getBeta());
    }

    /*
     * Tests whether the getBetaSum method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetBetaSumTest) {
        EXPECT_EQ(0.0, topicModel->getBetaSum());
    }

    /*
     * Tests whether the getBetaSum method works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, GetTopicAssignmentsTest) {
        vector<TopicAssignment*> const * const assignments =
                topicModel->getTopicAssignments();
        EXPECT_EQ(0, assignments->size());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(AbstractTopicModelTest, CopyConstructorTest) {
        AbstractTopicModel tmp = (*topicModel);
        EXPECT_EQ(noIterations, tmp.getNoIterations());
        EXPECT_EQ(noTopics, tmp.getNoTopics());
        EXPECT_EQ(0, tmp.getTopicAssignments()->size());
    }
}
