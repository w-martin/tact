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
 *
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "mewt/input/corpus/Corpus.h"
#include "mewt/input/corpus/text/TextDocument.h"
#include "mewt/input/corpus/feature/FeatureDocument.h"

namespace {

    /**
     * Tests Corpus.
     * 
     */
    class CorpusTest : public ::testing::Test {
    protected:

        CorpusTest() {
            location = "testLocation/";
            corpus = new Corpus(location, DOCUMENT_TYPE_BASIC);
        }

        virtual ~CorpusTest() {
            delete corpus;
        }
        Corpus * corpus;
        string location;
    };

    /*
     * Tests whether the addDocument method works correctly.
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
     * Tests whether the addDocument method throws an exception correctly.
     * 
     */
    TEST_F(CorpusTest, AddDocumentExceptionTest) {
        auto_ptr< Document > document =
                auto_ptr< Document > (new TextDocument("testName",
                auto_ptr< string > (new string("text"))));
        EXPECT_THROW(
                corpus->addDocument(document), IncompatibleCorpusException);
    }

    /*
     * Tests whether the contains method works correctly.
     * 
     */
    TEST_F(CorpusTest, ContainsTest) {
        string testName = "testName";
        Document * d = new Document(testName);

        EXPECT_FALSE(corpus->contains(d));
        corpus->addDocument(auto_ptr< Document > (new Document(*d)));
        EXPECT_TRUE(corpus->contains(d));
    }

    /*
     * Tests whether the equals methods work correctly.
     * 
     */
    TEST_F(CorpusTest, EqualsTest) {
        Corpus * other = new Corpus("notlocation", DOCUMENT_TYPE_BASIC);
        EXPECT_FALSE(corpus->equals(*other));
        EXPECT_NE(*corpus, *other);
        EXPECT_TRUE(*corpus != *other);
        
        delete other;
        other = new Corpus(location, DOCUMENT_TYPE_FEATURE);
        EXPECT_FALSE(corpus->equals(*other));
        EXPECT_NE(*corpus, *other);
        EXPECT_TRUE(*corpus != *other);
        
        delete other;
        other = new Corpus(location, DOCUMENT_TYPE_BASIC);
        EXPECT_TRUE(corpus->equals(*other));
        EXPECT_EQ(*corpus, *other);
        EXPECT_FALSE(*corpus != *other);
        
        Document * d = new Document("docname");
        corpus->addDocument(auto_ptr< Document > (d));
        EXPECT_FALSE(corpus->equals(*other));
        EXPECT_NE(*corpus, *other);
        EXPECT_TRUE(*corpus != *other);
        
        other->addDocument(auto_ptr< Document > (d));
        EXPECT_TRUE(corpus->equals(*other));
        EXPECT_EQ(*corpus, *other);
        EXPECT_FALSE(*corpus != *other);
    }

    /*
     * Tests whether the getDocuments method works correctly.
     * 
     */
    TEST_F(CorpusTest, GetDocumentsTest) {
        vector< Document * > const * const documents = corpus->getDocuments();
        EXPECT_EQ(0, documents->size());
    }

    /*
     * Tests whether the getDocumentsType method works correctly.
     * 
     */
    TEST_F(CorpusTest, GetDocumentsTypeTest) {
        EXPECT_EQ(DOCUMENT_TYPE_BASIC, corpus->getDocumentsType());
    }

    /*
     * Tests whether the getLocation method works correctly.
     * 
     */
    TEST_F(CorpusTest, GetLocationTest) {
        EXPECT_EQ(0, strcmp(location.c_str(), corpus->getLocation().c_str()));
    }

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
     * Tests whether the removeDocument method works correctly.
     * 
     */
    TEST_F(CorpusTest, RemoveDocumentTest) {
        vector< Document * > const * const documents = corpus->getDocuments();
        corpus->addDocument(auto_ptr< Document > (new Document("testName")));
        EXPECT_EQ(1, documents->size());
        corpus->removeDocument(documents->at(0));
        EXPECT_EQ(0, documents->size());
    }
}
