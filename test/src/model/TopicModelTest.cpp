/**
 * @file TopicModelTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/model/TopicModel.h"

namespace {

    /**
     * Tests TopicModel.
     * 
     */
    class TopicModelTest : public ::testing::Test {
    protected:

        TopicModelTest() {
            topicModel = new TopicModel();
        }

        virtual ~TopicModelTest() {
            delete topicModel;
        }
        TopicModel * topicModel;
    };

    /*
     * Tests whether the getNoTopics method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetNoTopicsTest) {
        EXPECT_EQ(0, topicModel->getNoTopics());
    }

    /*
     * Tests whether the getAlpha method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetAlphaTest) {
        double const * const alpha = topicModel->getAlpha();
        for (int i = 0; i < 0; i++) {
            EXPECT_EQ(0.0, alpha[i]);
        }
    }

    /*
     * Tests whether the setAlpha method throws an exception correctly.
     * 
     */
    TEST_F(TopicModelTest, SetAlphaExceptionTest) {
        EXPECT_THROW(topicModel->setAlpha(1, 0.0),
                OutOfBoundsException);
    }

    /*
     * Tests whether the getAlphaSum method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetAlphaSumTest) {
        EXPECT_EQ(0.0, topicModel->getAlphaSum());
    }

    /*
     * Tests whether the getBeta method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetBetaTest) {
        EXPECT_EQ(0.0, topicModel->getBeta());
    }

    /*
     * Tests whether the setBeta method works correctly.
     * 
     */
    TEST_F(TopicModelTest, SetBetaTest) {
        double value = 0.876;
        topicModel->setBeta(value);
        EXPECT_EQ(value, topicModel->getBeta());
    }

    /*
     * Tests whether the getBetaSum method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetBetaSumTest) {
        EXPECT_EQ(0.0, topicModel->getBetaSum());
    }

    /*
     * Tests whether the getBetaSum method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetTopicAssignmentsTest) {
        vector<TopicAssignment*> const * const assignments =
                topicModel->getTopicAssignments();
        EXPECT_EQ(0, assignments->size());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(TopicModelTest, CopyConstructorTest) {
        TopicModel tmp = (*topicModel);
        EXPECT_EQ(0.0, tmp.getNoTopics());
        EXPECT_EQ(0, tmp.getTopicAssignments()->size());
    }
}
