/**
 * @file FeatureCorpusTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"
#include "teflon/input/corpus/feature/MockFeatureDocument.h"

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
            alphabet->addTerm("hello");
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
     * Tests whether the equals method works correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, EqualsTest) {
        FeatureCorpus * other = new FeatureCorpus("notLocation",
                auto_ptr< Alphabet > (new Alphabet(*alphabet)));
        EXPECT_NE(*other, *corpus);

        delete other;
        other = new FeatureCorpus(location,
                auto_ptr< Alphabet > (new Alphabet(*alphabet)));
        EXPECT_EQ(*other, *corpus);

        other->addDocument(auto_ptr<Document > (new MockFeatureDocument()));
        EXPECT_NE(*other, *corpus);

        corpus->addDocument(auto_ptr<Document > (new MockFeatureDocument()));
        EXPECT_EQ(*other, *corpus);

        delete other;
    }

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
     * Tests whether the replaceTerm method works correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, ReplaceTermTest) {
        string const original = "FOO";
        string const replacement1 = "foo";
        string const replacement2 = "bar";
        vector< string > replacements;
        replacements.push_back(replacement1);
        replacements.push_back(replacement2);

        Alphabet * const alphabet = corpus->getAlphabet();
        int const index = alphabet->addTerm(original);
        int const count = 33;
        auto_ptr< FeatureMap > featureMap =
                auto_ptr< FeatureMap > (new FeatureMap());
        featureMap->setFeature(index, count);
        auto_ptr< Document > document = auto_ptr< Document > (
                new FeatureDocument("testDoc", featureMap));
        corpus->addDocument(document);

        corpus->replaceTerm(original, replacements);
        EXPECT_FALSE(alphabet->hasTerm(original));
        EXPECT_TRUE(alphabet->hasTerm(replacement1));
        EXPECT_TRUE(alphabet->hasTerm(replacement2));

        FeatureDocument const * const featureDocument =
                (FeatureDocument *) corpus->getDocuments()->at(0);
        FeatureMap const * const map = featureDocument->getFeatureMap();
        EXPECT_EQ(count, map->getFeature(alphabet->getIndex(replacement1)));
        EXPECT_EQ(count, map->getFeature(alphabet->getIndex(replacement2)));
        EXPECT_EQ(0, map->getFeature(index));
    }

    /*
     * Tests whether the squash method works correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, SquashTest) {
        string const original = "hello";
        Alphabet * const alphabet = corpus->getAlphabet();
        alphabet->removeTerm(original);
        
        int const index = alphabet->addTerm(original);
        int const count = 33;
        auto_ptr< FeatureMap > featureMap =
                auto_ptr< FeatureMap > (new FeatureMap());
        featureMap->setFeature(index, count);
        auto_ptr< Document > document = auto_ptr< Document > (
                new FeatureDocument("testDoc", featureMap));
        corpus->addDocument(document);
        
        FeatureDocument const * const featureDocument =
                (FeatureDocument *) corpus->getDocuments()->at(0);
        FeatureMap const * const map = featureDocument->getFeatureMap();
        EXPECT_EQ(0, map->getFeature(0));
        EXPECT_EQ(count, map->getFeature(1));
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_EQ(2, alphabet->getNextIndex());
        
        corpus->squash();
        EXPECT_EQ(count, map->getFeature(0));
        EXPECT_EQ(0, map->getFeature(1));
        EXPECT_EQ(1, alphabet->getSize());
        EXPECT_EQ(1, alphabet->getNextIndex());
    }

    /*
     * Tests whether the createInstance method works correctly.
     * 
     */
    TEST_F(FeatureCorpusTest, CreateInstanceTest) {
        auto_ptr< FeatureCorpus > featureCorpus =
                FeatureCorpus::createInstance(location);
        EXPECT_STREQ(location.c_str(), featureCorpus->getLocation().c_str());
        EXPECT_EQ(0, featureCorpus->getAlphabet()->getSize());
        EXPECT_EQ(0, featureCorpus->getDocuments()->size());
        EXPECT_EQ(DOCUMENT_TYPE_FEATURE, featureCorpus->getDocumentsType());
        EXPECT_EQ(0, featureCorpus->getSize());
    }
}
