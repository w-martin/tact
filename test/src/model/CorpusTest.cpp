/**
 * @file CorpusTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
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
#include "mewt/model/Corpus.h"
#include "test/mock/mewt/model/MockDocument.h"

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
