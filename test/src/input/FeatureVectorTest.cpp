/**
 * @file FeatureVectorTest.cpp
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
#include "tmte-cpp/input/FeatureVector.h"
#include "tmte-cpp/model/Alphabet.h"
#include <memory>

using std::auto_ptr;

namespace {

    /**
     * Tests FeatureVector.
     * 
     */
    class FeatureVectorTest : public ::testing::Test {
    protected:

        FeatureVectorTest() {
            testAlphabet = new Alphabet();
            testAlphabet->addWord(testWord);
            alphabetPTR = auto_ptr<Alphabet > (testAlphabet);
            testFeatures = new vector<int>();
            testFeatures->push_back(0);
            featuresPTR = auto_ptr<vector<int> >(testFeatures);
            fv = new FeatureVector(alphabetPTR, featuresPTR);
        }

        virtual ~FeatureVectorTest() {
            delete fv;
        }
        FeatureVector * fv;
        Alphabet * testAlphabet;
        auto_ptr<Alphabet> alphabetPTR;
        vector<int> * testFeatures;
        auto_ptr<vector<int> > featuresPTR;
    };

    /*
     * Tests whether the alphabet getter works correctly.
     * 
     */
    TEST_F(FeatureVectorTest, GetAlphabetTest) {
        EXPECT_EQ(testAlphabet, fv->getAlphabet());
        EXPECT_STREQ(testWord,
                fv->getAlphabet()->getWord(0).c_str());
    }

    /*
     * Tests whether the features getter works correctly.
     * 
     */
    TEST_F(FeatureVectorTest, GetFeaturesTest) {
        EXPECT_EQ(testFeatures, fv->getFeatures());
        EXPECT_EQ(0, fv->getFeatures()->at(0));
    }

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(FeatureVectorTest, GetSizeTest) {
        EXPECT_EQ(1, fv->getSize());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(FeatureVectorTest, CopyConstructorTest) {
        FeatureVector const * tmp = new FeatureVector(*fv);
        Alphabet const * const a = tmp->getAlphabet();
        EXPECT_EQ(1, a->getSize());
        EXPECT_STREQ(testWord, a->getWord(0).c_str());
        vector<int> const * const f = tmp->getFeatures();
        EXPECT_EQ(1, f->size());
        EXPECT_EQ(0, f->at(0));
        EXPECT_EQ(1, tmp->getSize());
        delete tmp;
    }
}
