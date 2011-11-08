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
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetWordsTest) {
        vector<string> const * const words = alphabet->getWords();
        EXPECT_EQ(1, words->size());
        EXPECT_STREQ(testWord, words->at(0).c_str());
    }
}
