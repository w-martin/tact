/**
 * @file InstanceTest.cpp
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
