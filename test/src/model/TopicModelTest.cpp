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
     * Tests whether the setBeta method works correctly.
     * 
     */
    TEST_F(TopicModelTest, SetBetaTest) {
        double value = 0.876;
        topicModel->setBeta(value);
        EXPECT_EQ(value, topicModel->getBeta());
    }
}
