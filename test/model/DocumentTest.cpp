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
 * @section DESCRIPTION
 *
 * Tests Document.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/main/model/Document.h"

namespace {

    class DocumentTest : public ::testing::Test {
    protected:

        DocumentTest() {
            testWords = new int[1];
            testCounts = new int[2];
            testLength = 5;
            testTotal = 10;
            testDocument = new Document(
                    auto_ptr<int>(testWords),
                    auto_ptr<int>(testCounts),
                    testLength,
                    testTotal);
        }

        virtual ~DocumentTest() {
            delete testDocument;
        }
        Document const * testDocument;
        int * testWords;
        int * testCounts;
        int testLength;
        int testTotal;
    };

    /*
     * Tests whether the Document's words were set correctly.
     * 
     */
    TEST_F(DocumentTest, WordsTest) {
        EXPECT_EQ(testWords, testDocument->getWords());
    }

    /*
     * Tests whether the Document's counts were set correctly.
     * 
     */
    TEST_F(DocumentTest, CountsTest) {
        EXPECT_EQ(testCounts, testDocument->getCounts());
    }

    /*
     * Tests whether the Document's length was correctly.
     * 
     */
    TEST_F(DocumentTest, LengthTest) {
        EXPECT_EQ(testLength, testDocument->getLength());
    }

    /*
     * Tests whether the Document's total was set correctly.
     * 
     */
    TEST_F(DocumentTest, TotalTest) {
        EXPECT_EQ(testTotal, testDocument->getTotal());
    }
}
