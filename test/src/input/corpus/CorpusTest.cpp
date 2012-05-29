/**
 * @file CorpusTest.cpp
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
#include "mewt/input/corpus/Corpus.h"

namespace {

    /**
     * Tests Corpus.
     * 
     */
    class CorpusTest : public ::testing::Test {
    protected:

        CorpusTest() {
            location = "testLocation/";
            corpus = new Corpus(location);
        }

        virtual ~CorpusTest() {
            delete corpus;
        }
        Corpus * corpus;
        string location;
    };

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(CorpusTest, GetSizeTest) {
        EXPECT_EQ(0, corpus->getSize());

        string testName = "testName";
        Document * d = new Document(testName);
        corpus->addDocument(auto_ptr< Document > (d));
        EXPECT_EQ(1, corpus->getSize());
    }

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(CorpusTest, GetNameTest) {
        EXPECT_EQ(0, strcmp(location.c_str(), corpus->getLocation().c_str()));
    }

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(CorpusTest, AddDocumentTest) {
        vector< Document * > const * const documents = corpus->getDocuments();
        EXPECT_EQ(0, documents->size());

        string testName = "testName";
        Document * d = new Document(testName);
        EXPECT_TRUE(corpus->addDocument(auto_ptr< Document > (d)));
        EXPECT_EQ(1, documents->size());
        EXPECT_EQ(0,
                strcmp(documents->at(0)->getName().c_str(), testName.c_str()));

        d = new Document(testName);
        EXPECT_FALSE(corpus->addDocument(auto_ptr< Document > (d)));
        EXPECT_EQ(1, documents->size());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(CorpusTest, CopyConstructorTest) {
        string testName = "testName";
        Document * d = new Document(testName);
        corpus->addDocument(auto_ptr< Document > (d));

        Corpus tmp(*corpus);
        EXPECT_EQ(0, strcmp(location.c_str(), tmp.getLocation().c_str()));
        vector< Document * > const * const documents = tmp.getDocuments();
        EXPECT_EQ(1, tmp.getSize());
        EXPECT_EQ(1, documents->size());
        EXPECT_EQ(0,
                strcmp(documents->at(0)->getName().c_str(), testName.c_str()));
    }
}
