/**
 * @file TopicAssignmentTest.cpp
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
