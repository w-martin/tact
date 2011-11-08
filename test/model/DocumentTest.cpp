/**
 * @file DocumentTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/main/model/Document.h"

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
