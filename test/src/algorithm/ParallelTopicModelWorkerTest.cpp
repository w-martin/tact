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
            noDocuments = TESTNO;
            noTopics = TESTNO;
            startDocument = TESTNO;
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
     * Tests whether the pass to the super constructor worked correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, SuperConstructionTest) {

    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(ParallelTopicModelWorkerTest, CopyConstructorTest) {
        ParallelTopicModelWorker tmp(*worker);
    }
}
