/**
 * @file FeatureCorpusTest.cpp
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

#include "gtest/gtest.h"
#include "mewt/input/corpus/feature/FeatureCorpus.h"

namespace {

    /**
     * Tests FeatureCorpus.
     * 
     */
    class FeatureCorpusTest : public ::testing::Test {
    protected:

        FeatureCorpusTest() {
            location = "testLocation/";
            alphabet = new Alphabet();
            alphabet->addWord("hello");
            corpus = new FeatureCorpus(location,
                    auto_ptr< Alphabet > (new Alphabet(*alphabet)));
        }

        virtual ~FeatureCorpusTest() {
            delete corpus;
            delete alphabet;
        }
        FeatureCorpus * corpus;
        string location;
        Alphabet * alphabet;
    };

    /*
     * Tests whether the documents type is set correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, GetDocumentsTypeTest) {
        EXPECT_EQ(DOCUMENT_TYPE_FEATURE, corpus->getDocumentsType());
    }

    /*
     * Tests whether the documents type is set correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, GetAlphabetTest) {
        Alphabet const * const a = corpus->getAlphabet();
        EXPECT_EQ(1, a->getSize());
    }

    /*
     * Tests whether the copy constructor correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, CopyConstructorTest) {
        FeatureCorpus tmp(*corpus);
        EXPECT_EQ(DOCUMENT_TYPE_FEATURE, tmp.getDocumentsType());
        EXPECT_EQ(1, tmp.getAlphabet()->getSize());
    }
}
