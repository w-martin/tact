/**
 * @file ParallelTopicModelWorker.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"

ParallelTopicModelWorker::ParallelTopicModelWorker(
        double * alpha,
        double alphaSum,
        double beta,
        int noDocuments,
        int noTopics,
        int startDocument,
        int * tokensPerTopic,
        vector<TopicAssignment*> * topicAssignments,
        int * * typeTopicCounts) {
    ParallelTopicModelWorker::alpha = alpha;
    ParallelTopicModelWorker::alphaSum = alphaSum;
    ParallelTopicModelWorker::beta = beta;
    ParallelTopicModelWorker::noDocuments = noDocuments;
    ParallelTopicModelWorker::noTopics = noTopics;
    ParallelTopicModelWorker::startDocument = startDocument;
    ParallelTopicModelWorker::tokensPerTopic = tokensPerTopic;
    ParallelTopicModelWorker::topicAssignments = topicAssignments;
    ParallelTopicModelWorker::typeTopicCounts = typeTopicCounts;

    noTypes = sizeof (typeTopicCounts) / sizeof (int*);
    betaSum = beta * noTypes;
    documentLengthCounts = new int[noDocuments];
    topicBits = 0;
    topicDocumentCounts = new int[noTopics][noDocuments];
    topicMask = 0;
}

ParallelTopicModelWorker::ParallelTopicModelWorker(
        const ParallelTopicModelWorker& orig) {
}

ParallelTopicModelWorker::~ParallelTopicModelWorker() {
    delete documentLengthCounts;
    delete topicDocumentCounts;
}

