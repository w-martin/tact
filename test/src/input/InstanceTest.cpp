/**
 * @file InstanceTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#define testWord "testWord"

#include "gtest/gtest.h"
#include "tmte-cpp/input/Instance.h"

namespace {

    /**
     * Tests Instance.
     * 
     */
    class InstanceTest : public ::testing::Test {
    protected:

        InstanceTest() {
            auto_ptr<Alphabet > alphabet =
                    auto_ptr<Alphabet > (new Alphabet());
            auto_ptr<vector<int> > features =
                    auto_ptr<vector<int> >(new vector<int>());
            data = new FeatureVector(alphabet, features);
            instance = new Instance(auto_ptr<FeatureVector > (data));
        }

        virtual ~InstanceTest() {
            delete instance;
        }
        Instance * instance;
        FeatureVector * data;
    };

    /*
     * Tests whether the getData method works correctly.
     * 
     */
    TEST_F(InstanceTest, GetDataTest) {
        EXPECT_EQ(data, instance->getData());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(InstanceTest, CopyConstructorTest) {
        Instance tmp(*instance);
        EXPECT_NE(data, tmp.getData());
        EXPECT_EQ(data->getSize(), tmp.getData()->getSize());
    }
}
