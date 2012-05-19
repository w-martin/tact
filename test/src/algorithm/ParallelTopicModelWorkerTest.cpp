/**
 * @file ParallelTopicModelWorkerTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
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
            randomNumberGenerator = new RandomNumberGenerator();
            startDocument = rand();
            tokensPerTopic = new int[noTopics];
            for (int i = 0; i < noTopics; i++) {
                tokensPerTopic[i] = rand();
            }
            topicAssignments = new vector<TopicAssignment*>();
            noTypes = TESTNO * 5;
            typeTopicCounts = new vector<vector<int> >();
            for (int i = 0; i < noTypes; i++) {
                typeTopicCounts->push_back(vector<int>());
                for (int j = 0; j < noTopics; j++) {
                    typeTopicCounts->at(i).push_back(rand());
                }
            }

            worker = new ParallelTopicModelWorker(
                    alpha,
                    alphaSum,
                    beta,
                    noDocuments,
                    noTopics,
                    noTypes,
                    randomNumberGenerator,
                    startDocument,
                    tokensPerTopic,
                    topicAssignments,
                    typeTopicCounts);
        }

        virtual ~ParallelTopicModelWorkerTest() {
            delete worker;
            delete [] alpha;
            delete [] tokensPerTopic;
            delete randomNumberGenerator;
            delete topicAssignments;
            delete typeTopicCounts;
        }
        ParallelTopicModelWorker * worker;
        double * alpha;
        double alphaSum;
        double beta;
        int noDocuments;
        int noTopics;
        RandomNumberGenerator * randomNumberGenerator;
        int startDocument;
        int * tokensPerTopic;
        vector<TopicAssignment*> * topicAssignments;
        vector<vector<int> > * typeTopicCounts;
        int noTypes;
    };

    /*
     * Tests whether the pass to the collectAlphaStatistics method works 
     * correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, CollectAlphaStatisticsTest) {
        worker->collectAlphaStatistics();
    }

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
     * Tests whether the pass to the getRandomNumberGenerator method 
     * works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, GetRandomNumberGeneratorTest) {
        EXPECT_EQ(randomNumberGenerator, worker->getRandomNumberGenerator());
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
        vector<vector<int> > const * const actual =
                worker->getTypeTopicCounts();
        EXPECT_EQ(typeTopicCounts->size(), actual->size());
        for (int i = 0; i < noTypes; i++) {
            EXPECT_EQ(typeTopicCounts->at(i).size(), actual->at(i).size());
            for (int j = 0; j < noTopics; j++) {
                EXPECT_EQ(typeTopicCounts->at(i).at(j), actual->at(i).at(j));
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
        EXPECT_EQ(randomNumberGenerator, tmp.getRandomNumberGenerator());
        EXPECT_EQ(startDocument, tmp.getStartDocument());

        int const * const actual3 = worker->getTokensPerTopic();
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

        vector<vector<int> > const * const actual6 =
                worker->getTypeTopicCounts();
        EXPECT_EQ(typeTopicCounts->size(), actual6->size());
        for (int i = 0; i < noTypes; i++) {
            EXPECT_EQ(typeTopicCounts->at(i).size(), actual6->at(i).size());
            for (int j = 0; j < noTopics; j++) {
                EXPECT_EQ(typeTopicCounts->at(i).at(j), actual6->at(i).at(j));
            }
        }
    }
}
