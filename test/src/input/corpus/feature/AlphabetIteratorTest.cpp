/**
 * @file AlphabetIteratorTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "mewt/input/corpus/feature/AlphabetIterator.h"
#include "mewt/input/corpus/feature/Alphabet.h"

namespace {

    /**
     * Tests AlphabetIterator.
     * 
     */ 
    class AlphabetIteratorTest : public ::testing::Test {
    protected:

        AlphabetIteratorTest() {
            alphabet = new Alphabet();
            alphabet->addTerm("hello");
            alphabet->addTerm("world");
        }

        virtual ~AlphabetIteratorTest() {
            delete alphabet;
        }
        Alphabet * alphabet;
    };

    /*
     * Tests whether the copy constructor work correctly.
     * 
     */
    TEST_F(AlphabetIteratorTest, CopyConstructorTest) {
        AlphabetIterator iter = alphabet->begin();
        AlphabetIterator tmp(iter);
        EXPECT_STREQ(iter.getTerm().c_str(), tmp.getTerm().c_str());
        EXPECT_EQ(iter.getIndex(), tmp.getIndex());
    }

    /*
     * Tests whether the increment methods work correctly.
     * 
     */
    TEST_F(AlphabetIteratorTest, IncrementTest) {
        AlphabetIterator iter = alphabet->begin();
        iter++;
        iter++;
        EXPECT_TRUE(iter == alphabet->end());
        iter = alphabet->begin();
        ++iter;
        ++iter;
        EXPECT_TRUE(iter == alphabet->end());
    }

    /*
     * Tests whether the equals methods work correctly.
     * 
     */
    TEST_F(AlphabetIteratorTest, EqualsTest) {
        AlphabetIterator iter = alphabet->begin();
        AlphabetIterator other = alphabet->begin();
        EXPECT_TRUE(iter.equals(other));
        EXPECT_TRUE(iter == other);
        EXPECT_FALSE(iter != other);
        
        iter++;
        EXPECT_FALSE(iter.equals(other));
        EXPECT_FALSE(iter == other);
        EXPECT_TRUE(iter != other);
        
        other++;
        EXPECT_TRUE(iter.equals(other));
        EXPECT_TRUE(iter == other);
        EXPECT_FALSE(iter != other);
    }

    /*
     * Tests whether the getIndex method works correctly.
     * 
     */
    TEST_F(AlphabetIteratorTest, GetIndexTest) {
        AlphabetIterator iter = alphabet->begin();
        EXPECT_EQ(0, iter.getIndex());
        iter++;
        EXPECT_EQ(1, iter.getIndex());
    }

    /*
     * Tests whether the getIndex method works correctly.
     * 
     */
    TEST_F(AlphabetIteratorTest, GetTermTest) {
        AlphabetIterator iter = alphabet->begin();
        EXPECT_STREQ("hello", iter.getTerm().c_str());
        iter++;
        EXPECT_STREQ("world", iter.getTerm().c_str());
    }
}
