/**
 * @file PipeTest.cpp
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

#define testWord "testWord"

#include "gtest/gtest.h"
#include "mewt/input/Pipe.h"
#include "mewt/input/Alphabet.h"
#include <memory>

using std::auto_ptr;

namespace {

    /**
     * Tests Pipe.
     * 
     */
    class PipeTest : public ::testing::Test {
    protected:

        PipeTest() {
            pipe = new Pipe();
            testAlphabet = new Alphabet();
            testAlphabet->addWord(testWord);
            alphabetPTR = auto_ptr<Alphabet>(testAlphabet);
        }

        virtual ~PipeTest() {
            delete pipe;
        }
        Pipe * pipe;
        Alphabet * testAlphabet;
        auto_ptr<Alphabet> alphabetPTR;
    };

    /*
     * Tests whether the dataAlphabet getter and setter methods work correctly.
     * 
     */
    TEST_F(PipeTest, DataAlphabetTest) {
        EXPECT_EQ(0, pipe->getDataAlphabet());
        pipe->setDataAlphabet(alphabetPTR);
        EXPECT_EQ(testAlphabet, pipe->getDataAlphabet());
    }

    /*
     * Tests whether the dataAlphabet setter throws an exception correctly.
     * 
     */
    TEST_F(PipeTest, SetDataAlphabetExceptionTest) {
        pipe->setDataAlphabet(alphabetPTR);
        EXPECT_EQ(testAlphabet, pipe->getDataAlphabet());
        auto_ptr<Alphabet> tmp = auto_ptr<Alphabet>(new Alphabet());
        tmp->addWord(testWord);
        EXPECT_THROW(pipe->setDataAlphabet(tmp), AlphabetSetException);
    }

    /*
     * Tests whether the targetAlphabet getter and setter methods work correctly.
     * 
     */
    TEST_F(PipeTest, TargetAlphabetTest) {
        EXPECT_EQ(0, pipe->getTargetAlphabet());
        pipe->setTargetAlphabet(alphabetPTR);
        EXPECT_EQ(testAlphabet, pipe->getTargetAlphabet());
    }

    /*
     * Tests whether the targetAlphabet setter throws an exception correctly.
     * 
     */
    TEST_F(PipeTest, SetTargetAlphabetExceptionTest) {
        pipe->setTargetAlphabet(alphabetPTR);
        EXPECT_EQ(testAlphabet, pipe->getTargetAlphabet());
        auto_ptr<Alphabet> tmp = auto_ptr<Alphabet>(new Alphabet());
        tmp->addWord(testWord);
        EXPECT_THROW(pipe->setTargetAlphabet(tmp), AlphabetSetException);
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(PipeTest, CopyConstructorTest) {
        pipe->setDataAlphabet(alphabetPTR);
        Pipe * tmp = new Pipe(*pipe);
        Alphabet const * const alph = tmp->getDataAlphabet();
        EXPECT_EQ(1, alph->getSize());
        EXPECT_STREQ(testWord, alph->getWord(0).c_str());
        EXPECT_EQ(0, tmp->getTargetAlphabet());
        delete tmp;
    }
}
