/**
 * @file TopicAssignmentTest.cpp
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
#include "tmte-cpp/output/TopicAssignment.h"

namespace {

    /**
     * Tests TopicAssignment.
     * 
     */
    class TopicAssignmentTest : public ::testing::Test {
    protected:

        TopicAssignmentTest() {
            auto_ptr<Alphabet > alphabet =
                    auto_ptr<Alphabet > (new Alphabet());
            auto_ptr<vector<int> > features =
                    auto_ptr<vector<int> >(new vector<int>());
            data = new FeatureVector(alphabet, features);
            topicSequence = new FeatureVector(*data);
            instance = new Instance(auto_ptr<FeatureVector > (data));

            assignment = new TopicAssignment(instance, topicSequence);
        }

        virtual ~TopicAssignmentTest() {
            delete assignment;
            delete instance;
            delete topicSequence;
        }
        TopicAssignment * assignment;
        Instance * instance;
        FeatureVector * data;
        FeatureVector * topicSequence;
    };

    /*
     * Tests whether the getInstance method works correctly.
     * 
     */
    TEST_F(TopicAssignmentTest, GetInstanceTest) {
        EXPECT_EQ(instance, assignment->getInstance());
    }

    /*
     * Tests whether the getTopicSequence method works correctly.
     * 
     */
    TEST_F(TopicAssignmentTest, GetTopicSequenceTest) {
        EXPECT_EQ(topicSequence, assignment->getTopicSequence());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(TopicAssignmentTest, CopyConstructorTest) {
        TopicAssignment * tmp = new TopicAssignment(*assignment);
        EXPECT_EQ(instance, tmp->getInstance());
        EXPECT_EQ(topicSequence, tmp->getTopicSequence());
        delete tmp;
    }
}
