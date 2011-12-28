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
#include "tmte-cpp/input/InstanceList.h"

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
            
            auto_ptr<Alphabet > alphabet =
                    auto_ptr<Alphabet > (new Alphabet());
            auto_ptr<vector<int> > features =
                    auto_ptr<vector<int> >(new vector<int>());
            data = new FeatureVector(alphabet, features);
            instance = new Instance(auto_ptr<FeatureVector > (data));
        }

        virtual ~InstanceListTest() {
            delete instanceList;
            delete instance;
        }
        Instance * instance;
        FeatureVector * data;
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
        Instance * i = new Instance(*instance);
        EXPECT_TRUE(instanceList->addInstance(i));
        vector<Instance*> const * tmp = instanceList->getInstances();
        EXPECT_EQ(1, tmp->size());
        EXPECT_EQ(i, tmp->at(0));
        EXPECT_FALSE(instanceList->addInstance(i));
        i = new Instance(*instance);
        EXPECT_TRUE(instanceList->addInstance(i));
        tmp = instanceList->getInstances();
        EXPECT_EQ(2, tmp->size());
        EXPECT_EQ(i, tmp->at(1));
        EXPECT_FALSE(instanceList->addInstance(i));
    }

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(InstanceListTest, GetSizeTest) {
        EXPECT_EQ(0, instanceList->getSize());
        Instance * i = new Instance(*instance);
        instanceList->addInstance(i);
        EXPECT_EQ(1, instanceList->getSize());
    }

    /*
     * Tests whether the pipe getter and setter methods work correctly.
     * 
     */
    TEST_F(InstanceListTest, PipeTest) {
        EXPECT_EQ(testPipe, instanceList->getPipe());
        Pipe * p = new Pipe();
        instanceList->setPipe(auto_ptr<Pipe > (p));
        EXPECT_NE(testPipe, instanceList->getPipe());
        EXPECT_EQ(p, instanceList->getPipe());
        EXPECT_EQ((void*) 0, instanceList->getDataAlphabet());
        EXPECT_EQ((void*) 0, instanceList->getTargetAlphabet());
    }

    /*
     * Tests whether the getDataAlphabet method works correctly.
     * 
     */
    TEST_F(InstanceListTest, GetDataAlphabetTest) {
        EXPECT_EQ(testAlphabet, instanceList->getDataAlphabet());
    }

    /*
     * Tests whether the getTargetAlphabet method works correctly.
     * 
     */
    TEST_F(InstanceListTest, GetTargetAlphabetTest) {
        EXPECT_EQ((void*) 0, instanceList->getTargetAlphabet());
        Pipe * p = new Pipe();
        Alphabet * a = new Alphabet();
        p->setTargetAlphabet(auto_ptr<Alphabet > (a));
        instanceList->setPipe(auto_ptr<Pipe > (p));
        EXPECT_EQ(a, instanceList->getTargetAlphabet());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(InstanceListTest, CopyConstructorTest) {
        Instance * i = new Instance(*instance);
        instanceList->addInstance(i);
        InstanceList const * const tmp = new InstanceList(*instanceList);
        EXPECT_NE(tmp, instanceList);
        EXPECT_EQ(1, tmp->getSize());
        EXPECT_NE((void*) 0, tmp->getDataAlphabet());
        EXPECT_EQ((void*) 0, tmp->getTargetAlphabet());
    }
}
