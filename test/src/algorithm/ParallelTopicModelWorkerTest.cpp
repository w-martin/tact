/**
 * @file ParallelTopicModelWorkerTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#define TESTNO 5

#include "gtest/gtest.h"
#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"
#include <cstdlib>

namespace {

    /**
     * Tests ParallelTopicModelWorkerTest.
     * 
     */
    class ParallelTopicModelWorkerTest : public ::testing::Test {
    protected:

        ParallelTopicModelWorkerTest() {
            srandom((unsigned) time(0));
            srand((unsigned) time(0));

            alpha = new double[TESTNO];
            for (int i = 0; i < TESTNO; i++) {
                alpha[i] = random();
            }
            alphaSum = random();
            beta = random();
            noDocuments = TESTNO - 1;
            noTopics = TESTNO * 3;
            startDocument = rand();
            tokensPerTopic = new int[noTopics];
            for (int i = 0; i < noTopics; i++) {
                tokensPerTopic[i] = rand();
            }
            topicAssignments = new vector<TopicAssignment*>();
            noTypes = TESTNO * 5;
            typeTopicCounts = new int*[noTypes];
            for (int i = 0; i < noTypes; i++) {
                typeTopicCounts[i] = new int[noTopics];
                for (int j = 0; j < noTopics; j++) {
                    typeTopicCounts[i][j] = rand();
                }
            }

            worker = new ParallelTopicModelWorker(
                    alpha,
                    alphaSum,
                    beta,
                    noDocuments,
                    noTopics,
                    noTypes,
                    startDocument,
                    tokensPerTopic,
                    topicAssignments,
                    typeTopicCounts);
        }

        virtual ~ParallelTopicModelWorkerTest() {
            delete worker;
            delete [] alpha;
            delete [] tokensPerTopic;
            delete topicAssignments;
            for (int i = 0; i < noTypes; i++) {
                delete [] typeTopicCounts[i];
            }
            delete [] typeTopicCounts;
        }
        ParallelTopicModelWorker * worker;
        double * alpha;
        double alphaSum;
        double beta;
        int noDocuments;
        int noTopics;
        int startDocument;
        int * tokensPerTopic;
        vector<TopicAssignment*> * topicAssignments;
        int * * typeTopicCounts;
        int noTypes;
    };

    /*
     * Tests whether the pass to the getAlpha method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetAlphaTest) {
        double const * const actual = worker->getAlpha();
        for (int i = 0; i < TESTNO; i++) {
            EXPECT_EQ(alpha[i], actual[i]);
        }
    }

    /*
     * Tests whether the pass to the getAlphaSum method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetAlphaSumTest) {
        EXPECT_EQ(alphaSum, worker->getAlphaSum());
    }

    /*
     * Tests whether the pass to the getBeta method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetBetaTest) {
        EXPECT_EQ(beta, worker->getBeta());
    }

    /*
     * Tests whether the pass to the getBetaSum method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetBetaSumTest) {
        EXPECT_EQ(noTypes * beta, worker->getBetaSum());
    }

    /*
     * Tests whether the pass to the getDocumentLengthCounts method 
     * works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetDocumentLengthCountsTest) {
        int const * const actual = worker->getDocumentLengthCounts();
        for (int i = 0; i < noDocuments; i++) {
            EXPECT_EQ(0, actual[i]);
        }
    }

    /*
     * Tests whether the pass to the getNoDocuments method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetNoDocumentsTest) {
        EXPECT_EQ(noDocuments, worker->getNoDocuments());
    }

    /*
     * Tests whether the pass to the getNoTopics method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetNoTopicsTest) {
        EXPECT_EQ(noTopics, worker->getNoTopics());
    }

    /*
     * Tests whether the pass to the getStartDocument method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetStartDocumentTest) {
        EXPECT_EQ(startDocument, worker->getStartDocument());
    }

    /*
     * Tests whether the pass to the getTokensPerTopic method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTokensPerTopicTest) {
        int const * const actual = worker->getTokensPerTopic();
        for (int i = 0; i < noTopics; i++) {
            EXPECT_EQ(tokensPerTopic[i], actual[i]);
        }
    }

    /*
     * Tests whether the pass to the getTopicAssignments method 
     * works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTopicAssignmentsTest) {
        vector<TopicAssignment*> const * const actual =
                worker->getTopicAssignments();
        EXPECT_EQ(0, actual->size());
    }

    /*
     * Tests whether the pass to the getTopicBits method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTopicBitsTest) {
        EXPECT_EQ(0, worker->getTopicBits());
    }

    /*
     * Tests whether the pass to the getTopicDocumentCounts method 
     * works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTopicDocumentCountsTest) {
        int const * const * const actual = worker->getTopicDocumentCounts();
        for (int i = 0; i < noTopics; i++) {
            for (int j = 0; j < noDocuments; j++) {
                EXPECT_EQ(0.0, actual[i][j]);
            }
        }
    }

    /*
     * Tests whether the pass to the getTopicMask method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTopicMaskTest) {
        EXPECT_EQ(0, worker->getTopicMask());
    }

    /*
     * Tests whether the pass to the getTypeTopicCounts method works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetTypeTopicCountsTest) {
        int const * const * const actual = worker->getTypeTopicCounts();
        for (int i = 0; i < noTypes; i++) {
            for (int j = 0; j < noTopics; j++) {
                EXPECT_EQ(typeTopicCounts[i][j], actual[i][j]);
            }
        }
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, CopyConstructorTest) {
        ParallelTopicModelWorker tmp(*worker);

        double const * const actual1 = tmp.getAlpha();
        for (int i = 0; i < TESTNO; i++) {
            EXPECT_EQ(alpha[i], actual1[i]);
        }
        EXPECT_EQ(alphaSum, tmp.getAlphaSum());
        EXPECT_EQ(beta, tmp.getBeta());
        EXPECT_EQ(noTypes * beta, tmp.getBetaSum());
        int const * const actual2 = tmp.getDocumentLengthCounts();
        for (int i = 0; i < noDocuments; i++) {
            EXPECT_EQ(0, actual2[i]);
        }
        EXPECT_EQ(noDocuments, tmp.getNoDocuments());
        EXPECT_EQ(noTopics, tmp.getNoTopics());
        EXPECT_EQ(startDocument, tmp.getStartDocument());
        int const * const actual3 = tmp.getTokensPerTopic();
        for (int i = 0; i < noTopics; i++) {
            EXPECT_EQ(tokensPerTopic[i], actual3[i]);
        }
        vector<TopicAssignment*> const * const actual4 =
                tmp.getTopicAssignments();
        EXPECT_EQ(0, actual4->size());
        EXPECT_EQ(0, tmp.getTopicBits());
        int const * const * const actual5 = tmp.getTopicDocumentCounts();
        for (int i = 0; i < noTopics; i++) {
            for (int j = 0; j < noDocuments; j++) {
                EXPECT_EQ(0.0, actual5[i][j]);
            }
        }
        EXPECT_EQ(0, tmp.getTopicMask());
        int const * const * const actual6 = tmp.getTypeTopicCounts();
        for (int i = 0; i < noTypes; i++) {
            for (int j = 0; j < noTopics; j++) {
                EXPECT_EQ(typeTopicCounts[i][j], actual6[i][j]);
            }
        }
    }
}
