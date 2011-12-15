/**
 * @file CorpusTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "gtest/gtest.h"
#include "tmte-cpp/model/Corpus.h"
#include "test/mock/tmte-cpp/model/MockDocument.h"

using ::testing::Return;
using ::testing::_;

namespace {

    /**
     * Tests Corpus.
     * 
     */
    class CorpusTest : public ::testing::Test {
    protected:

        CorpusTest() {
            noTerms = 15;
            noDocuments = 2345;
            documentMock = new MockDocument();
            testCorpus = new Corpus();
        }

        virtual ~CorpusTest() {
            delete testCorpus;
            delete documentMock;
        }
        Corpus * testCorpus;
        int noTerms;
        int noDocuments;
        Document * documentMock;
    };

    /*
     * Tests whether the addDocument and getDocuments methods work correctly.
     * 
     */
    TEST_F(CorpusTest, DocumentsTest) {
        EXPECT_EQ(0, testCorpus->getDocuments()->size());
        testCorpus->addDocument(auto_ptr<Document > (documentMock));
        EXPECT_EQ(1, testCorpus->getDocuments()->size());
        EXPECT_EQ(documentMock, testCorpus->getDocuments()->at(0));
    }

    /*
     * Tests whether the noTerms getter and setter work correctly.
     * 
     */
    TEST_F(CorpusTest, NoTermsTest) {
        EXPECT_EQ(0, testCorpus->getNoTerms());
        testCorpus->setNoTerms(noTerms);
        EXPECT_EQ(noTerms, testCorpus->getNoTerms());
    }
}
