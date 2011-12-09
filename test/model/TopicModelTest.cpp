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
#include "tmte-cpp/main/model/TopicModel.h"

namespace {

    /**
     * Tests TopicModel.
     * 
     */
    class TopicModelTest : public ::testing::Test {
    protected:

        TopicModelTest() {
            noIterations = 7;
            noTopics = 60;
            topicModel = new TopicModel(noIterations, noTopics);
        }

        virtual ~TopicModelTest() {
            delete topicModel;
        }
        TopicModel * topicModel;
        int noIterations;
        int noTopics;
    };

    /*
     * Tests whether the getNoIterations method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetNoIterationsTest) {
        EXPECT_EQ(noIterations, topicModel->getNoIterations());
    }

    /*
     * Tests whether the getNoTopics method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetNoTopicsTest) {
        EXPECT_EQ(noTopics, topicModel->getNoTopics());
    }

    /*
     * Tests whether the getAlpha method works correctly.
     * 
     */
    TEST_F(TopicModelTest, GetAlphaTest) {
        double const * const alpha = topicModel->getAlpha();
        for (int i = 0; i < noTopics; i++) {
            EXPECT_EQ(0.0, alpha[i]);
        }
    }

    /*
     * Tests whether the setAlpha method works correctly.
     * 
     */
    TEST_F(TopicModelTest, SetAlphaTest) {
        double value = 0.456;
        topicModel->setAlpha(noTopics - 1, value);
        EXPECT_EQ(value, topicModel->getAlpha()[noTopics - 1]);
        EXPECT_EQ(value, topicModel->getAlphaSum());
    }

    /*
     * Tests whether the setAlpha method throws an exception correctly.
     * 
     */
    TEST_F(TopicModelTest, SetAlphaExceptionTest) {
        EXPECT_THROW(topicModel->setAlpha(noTopics, 0.0),
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
        EXPECT_EQ(DEFAULT_BETA, topicModel->getBeta());
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
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(TopicModelTest, CopyConstructorTest) {
        TopicModel tmp = (*topicModel);
        EXPECT_EQ(noIterations, tmp.getNoIterations());
        EXPECT_EQ(noTopics, tmp.getNoTopics());
    }
}
