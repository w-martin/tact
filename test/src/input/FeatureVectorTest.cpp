/**
 * @file FeatureVectorTest.cpp
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
#include "mewt/input/FeatureVector.h"
#include "mewt/input/Alphabet.h"
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
