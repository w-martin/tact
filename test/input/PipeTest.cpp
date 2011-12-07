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
#include "tmte-cpp/main/input/Pipe.h"
#include "tmte-cpp/main/model/Alphabet.h"

namespace {

    /**
     * Tests Pipe.
     * 
     */
    class PipeTest : public ::testing::Test {
    protected:

        PipeTest() {
            pipe = new Pipe();
        }

        virtual ~PipeTest() {
            delete pipe;
        }
        Pipe const * pipe;
    };

    /*
     * Tests whether the dataAlphabet getter and setter methods work correctly.
     * 
     */
    TEST_F(PipeTest, DataAlphabetTest) {
        EXPECT_EQ(0, pipe->getDataAlphabet());
        Alphabet const * testAlphabet = new Alphabet();
        
    }
}
