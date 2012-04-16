/**
 * @file PipeTest.cpp
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
#include "tmte-cpp/input/Pipe.h"
#include "tmte-cpp/input/Alphabet.h"
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
