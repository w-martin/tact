/**
 * @file InstanceListTest.cpp
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
#include "tmte-cpp/main/input/InstanceList.h"
#include "tmte-cpp/main/input/Pipe.h"
#include "tmte-cpp/main/model/Alphabet.h"
#include <memory>

using std::auto_ptr;

namespace {

    /**
     * Tests InstanceList.
     * 
     */
    class InstanceListTest : public ::testing::Test {
    protected:

        InstanceListTest() {
            testAlphabet = new Alphabet();
            testAlphabet->addWord(testWord);
            alphabetPTR = auto_ptr<Alphabet>(testAlphabet);
            testPipe = new Pipe();
            testPipe->setDataAlphabet(alphabetPTR);
            pipePTR = auto_ptr<Pipe>(testPipe);
            instanceList = new InstanceList(pipePTR);
        }

        virtual ~InstanceListTest() {
            delete instanceList;
        }
        InstanceList * instanceList;
        Pipe * testPipe;
        auto_ptr<Pipe> pipePTR;
        Alphabet * testAlphabet;
        auto_ptr<Alphabet> alphabetPTR;
    };

    /*
     * Tests whether the dataAlphabet getter and setter methods work correctly.
     * 
     */
    TEST_F(InstanceListTest, DataAlphabetTest) {
        
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(InstanceListTest, CopyConstructorTest) {
        
    }
}
