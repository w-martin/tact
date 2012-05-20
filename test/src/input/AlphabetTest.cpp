/**
 * @file AlphabetTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#define testWord "testWord"

#include "gtest/gtest.h"
#include "mewt/input/Alphabet.h"

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

    /*
     * Tests whether the getNextIndex method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetNextIndexTest) {
        EXPECT_EQ(1, alphabet->getNextIndex());
        alphabet->addWord("hello");
        EXPECT_EQ(2, alphabet->getNextIndex());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(AlphabetTest, CopyConstructorTest) {
        Alphabet * tmp = new Alphabet(*alphabet);
        EXPECT_EQ(1, tmp->getSize());
        EXPECT_STREQ(testWord, tmp->getWord(0).c_str());
        delete tmp;
    }
}
