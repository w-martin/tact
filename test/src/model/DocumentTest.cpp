/**
 * @file DocumentTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
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
#include "tmte-cpp/model/Document.h"

namespace {

    /**
     * Tests Document.
     * 
     */
    class DocumentTest : public ::testing::Test {
    protected:

        DocumentTest() {
            length = 15;
            count = 1504;
            word = "testword";
            testDocument = new Document(length);
        }

        virtual ~DocumentTest() {
            delete testDocument;
        }
        Document * testDocument;
        char const* word;
        int count;
        int length;
    };

    /*
     * Tests whether the Document's words were set correctly.
     * 
     */
    TEST_F(DocumentTest, WordsTest) {
        testDocument->addWord(auto_ptr<char const>(word), count);
        EXPECT_STREQ(word, testDocument->getWords()->at(0));
    }

    /*
     * Tests whether the Document's counts were set correctly.
     * 
     */
    TEST_F(DocumentTest, CountsTest) {
        testDocument->addWord(auto_ptr<char const>(word), count);
        EXPECT_EQ(count, testDocument->getCounts()->at(0));
    }

    /*
     * Tests whether the Document's length was correctly.
     * 
     */
    TEST_F(DocumentTest, LengthTest) {
        EXPECT_EQ(length, testDocument->getLength());
    }

    /*
     * Tests whether the Document's total was set correctly.
     * 
     */
    TEST_F(DocumentTest, TotalTest) {
        testDocument->addWord(auto_ptr<char const>(word), count);
        EXPECT_EQ(count, testDocument->getTotal());
    }
}
