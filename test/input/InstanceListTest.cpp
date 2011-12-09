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
            alphabetPTR = auto_ptr<Alphabet > (testAlphabet);
            testPipe = new Pipe();
            testPipe->setDataAlphabet(alphabetPTR);
            pipePTR = auto_ptr<Pipe > (testPipe);
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
     * Tests whether the addInstance and getInstances methods work correctly.
     * 
     */
    TEST_F(InstanceListTest, InstancesTest) {
        EXPECT_EQ(0, instanceList->getInstances()->size());
        Instance * i = new Instance();
        EXPECT_TRUE(instanceList->addInstance(i));
        vector<Instance*> const * tmp = instanceList->getInstances();
        EXPECT_EQ(1, tmp->size());
        EXPECT_EQ(i, tmp->at(0));
        EXPECT_FALSE(instanceList->addInstance(i));
        i = new Instance();
        EXPECT_TRUE(instanceList->addInstance(i));
        tmp = instanceList->getInstances();
        EXPECT_EQ(2, tmp->size());
        EXPECT_EQ(i, tmp->at(1));
        EXPECT_FALSE(instanceList->addInstance(i));
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(InstanceListTest, CopyConstructorTest) {
        Instance * i = new Instance();
        instanceList->addInstance(i);
        InstanceList const * const tmp = new InstanceList(*instanceList);
        EXPECT_NE(tmp, instanceList);
        EXPECT_EQ(1, tmp->getSize());
        EXPECT_NE((void*) 0, tmp->getDataAlphabet());
        EXPECT_EQ((void*) 0, tmp->getTargetAlphabet());
    }
}
