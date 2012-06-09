/**
 * @file AlphabetTest.cpp
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

#define testTerm "testTerm"

#include "gtest/gtest.h"
#include "mewt/input/corpus/feature/Alphabet.h"

namespace {

    /**
     * Tests Alphabet.
     * 
     */
    class AlphabetTest : public ::testing::Test {
    protected:

        AlphabetTest() {
            alphabet = new Alphabet();
            alphabet->addTerm(testTerm);
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
     * Tests whether the getTerm method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetTermTest) {
        string const term = alphabet->getTerm(0);
        EXPECT_STREQ(testTerm, term.c_str());
        EXPECT_THROW(alphabet->getTerm(1), TermNotPresentException);
    }

    /*
     * Tests whether the hasTerm method works correctly.
     * 
     */
    TEST_F(AlphabetTest, HasTermTest) {
        EXPECT_TRUE(alphabet->hasTerm(testTerm));
        EXPECT_FALSE(alphabet->hasTerm("hello"));
    }

    /*
     * Tests whether the hasIndex method works correctly.
     * 
     */
    TEST_F(AlphabetTest, HasIndexTest) {
        EXPECT_TRUE(alphabet->hasIndex(0));
        EXPECT_FALSE(alphabet->hasIndex(1));
    }

    /*
     * Tests whether the getIndex method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetIndexTest) {
        int const index = alphabet->getIndex(testTerm);
        EXPECT_EQ(0, index);
        EXPECT_THROW(alphabet->getIndex("not test term"),
                TermNotPresentException);
    }

    /*
     * Tests whether the add term method works correctly.
     * 
     */
    TEST_F(AlphabetTest, AddTermTest) {
        string const term1 = "one", term2 = "two";
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_EQ(0, alphabet->getIndex(testTerm));
        EXPECT_FALSE(alphabet->hasTerm(term1));
        EXPECT_FALSE(alphabet->hasTerm(term2));
        EXPECT_TRUE(alphabet->hasIndex(0));
        EXPECT_FALSE(alphabet->hasIndex(1));
        EXPECT_FALSE(alphabet->hasIndex(2));
        EXPECT_FALSE(alphabet->hasIndex(3));
        
        EXPECT_THROW(alphabet->addTerm(term1, 0), DuplicateException);
        EXPECT_EQ(2, alphabet->addTerm(term1, 2));
        EXPECT_EQ(2, alphabet->getIndex(term1));
        EXPECT_FALSE(alphabet->hasTerm(term2));
        EXPECT_TRUE(alphabet->hasIndex(0));
        EXPECT_FALSE(alphabet->hasIndex(1));
        EXPECT_TRUE(alphabet->hasIndex(2));
        EXPECT_FALSE(alphabet->hasIndex(3));
        
        EXPECT_THROW(alphabet->addTerm(term1, 1), DuplicateException);
        EXPECT_EQ(1, alphabet->addTerm(term2));
        EXPECT_EQ(1, alphabet->getIndex(term2));
        EXPECT_TRUE(alphabet->hasIndex(0));
        EXPECT_TRUE(alphabet->hasIndex(1));
        EXPECT_TRUE(alphabet->hasIndex(2));
        EXPECT_FALSE(alphabet->hasIndex(3));
        
        EXPECT_EQ(3, alphabet->getNextIndex());
    }

    /*
     * Tests whether the add and remove term methods work correctly.
     * 
     */
    TEST_F(AlphabetTest, AddRemoveTermTest) {
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_STREQ(testTerm, alphabet->removeTerm(0).c_str());
        EXPECT_EQ(0, alphabet->getSize());
        EXPECT_EQ(1, alphabet->addTerm(testTerm));
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_EQ(1, alphabet->removeTerm(testTerm));
        EXPECT_EQ(0, alphabet->getSize());
    }

    /*
     * Tests whether the getNextIndex method works correctly.
     * 
     */
    TEST_F(AlphabetTest, GetNextIndexTest) {
        EXPECT_EQ(1, alphabet->getNextIndex());
        alphabet->addTerm("hello");
        EXPECT_EQ(2, alphabet->getNextIndex());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(AlphabetTest, CopyConstructorTest) {
        Alphabet * tmp = new Alphabet(*alphabet);
        EXPECT_EQ(1, tmp->getSize());
        EXPECT_STREQ(testTerm, tmp->getTerm(0).c_str());
        delete tmp;
    }

    /*
     * Tests whether the equals method works correctly.
     * 
     */
    TEST_F(AlphabetTest, EqualsTest) {
        Alphabet * tmp = new Alphabet(*alphabet);
        EXPECT_TRUE(alphabet->equals(tmp));
        EXPECT_EQ(*alphabet, tmp);

        tmp->addTerm("hello");
        EXPECT_FALSE(alphabet->equals(tmp));
        EXPECT_NE(*alphabet, tmp);

        alphabet->addTerm("hello");
        EXPECT_TRUE(alphabet->equals(tmp));
        EXPECT_EQ(*alphabet, tmp);

        EXPECT_TRUE((*alphabet == tmp) == !(*alphabet != tmp));

        delete tmp;
    }
}
