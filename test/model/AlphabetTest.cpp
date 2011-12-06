/**
 * @file AlphabetTest.cpp
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
#include "tmte-cpp/main/model/Alphabet.h"

namespace {

    /**
     * Tests Alphabet.
     * 
     */
    class AlphabetTest : public ::testing::Test {
    protected:

        AlphabetTest() {
            alphabet = new Alphabet();
            alphabet->addWord(testWord);
        }

        virtual ~AlphabetTest() {
            delete alphabet;
        }
        Alphabet * alphabet;
        int noIterations;
        int noTopics;
    };

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetSizeTest) {
        EXPECT_EQ(1, alphabet->getSize());
    }

    /*
     * Tests whether the getWords method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetWordsTest) {
        vector<string> const * const words = alphabet->getWords();
        EXPECT_EQ(1, words->size());
        EXPECT_STREQ(testWord, words->at(0).c_str());
    }

    /*
     * Tests whether the getWord method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetWordTest) {
        string const word = alphabet->getWord(0);
        EXPECT_STREQ(testWord, word.c_str());
    }

    /*
     * Tests whether the hasWord method works correctly.
     * 
     */
    TEST_F(AlphabetTest, HasWordTest) {
        EXPECT_TRUE(alphabet->hasWord(testWord));
    }

    /*
     * Tests whether the getIndex method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetIndexTest) {
        int const index = alphabet->getIndex(testWord);
        EXPECT_EQ(0, index);
    }

    /*
     * Tests whether the getIndices method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetIndicesTest) {
        vector<int> const * const indices = alphabet->getIndices();
        EXPECT_EQ(1, indices->size());
        EXPECT_EQ(0, indices->at(0));
    }

    /*
     * Tests whether the add and remove word methods work correctly.
     * 
     */
    TEST_F(AlphabetTest, AddRemoveWordTest) {
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_STREQ(testWord, alphabet->removeWord(0).c_str());
        EXPECT_EQ(0, alphabet->getSize());
        EXPECT_EQ(1, alphabet->addWord(testWord));
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_EQ(1, alphabet->removeWord(testWord));
        EXPECT_EQ(0, alphabet->getSize());
    }
}
