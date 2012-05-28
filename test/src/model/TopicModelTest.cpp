/**
 * @file TopicModelTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "mewt/model/TopicModel.h"

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
