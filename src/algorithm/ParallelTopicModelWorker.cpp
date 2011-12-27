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
        double * const alpha,
        double alphaSum,
        double beta,
        int const noDocuments,
        int const noTopics,
        int const noTypes,
        int const startDocument,
        vector<int> const * const tokensPerTopic,
        vector<TopicAssignment*> * topicAssignments,
        vector<vector<int> > const * const typeTopicCounts) {

    ParallelTopicModelWorker::alpha = alpha;
    ParallelTopicModelWorker::alphaSum = alphaSum;
    ParallelTopicModelWorker::beta = beta;
    ParallelTopicModelWorker::noDocuments = noDocuments;
    ParallelTopicModelWorker::noTopics = noTopics;
    ParallelTopicModelWorker::noTypes = noTypes;
    ParallelTopicModelWorker::startDocument = startDocument;
    copyTokensPerTopic(tokensPerTopic);
    copyTopicAssignments(topicAssignments);
    copyTypeTopicCounts(typeTopicCounts);

    betaSum = beta * noTypes;
    documentLengthCounts = new int[noDocuments];
    for (int i = 0; i < noDocuments; i++) {
        documentLengthCounts[i] = 0;
    }
    topicBits = 0;
    topicDocumentCounts = new int*[noTopics];
    for (int i = 0; i < noTopics; i++) {
        topicDocumentCounts[i] = new int[noDocuments];
        for (int j = 0; j < noDocuments; j++) {
            topicDocumentCounts[i][j] = 0;
        }
    }
    topicMask = 0;
}

ParallelTopicModelWorker::ParallelTopicModelWorker(
        const ParallelTopicModelWorker& orig)
: TopicModel(orig) {
    noDocuments = orig.getNoDocuments();
    startDocument = orig.getStartDocument();
    copyTokensPerTopic(orig.getTokensPerTopic());
    copyTopicAssignments(orig.getTopicAssignments());
    copyTypeTopicCounts(orig.getTypeTopicCounts());

    noTypes = sizeof (typeTopicCounts) / sizeof (int*);
    int const * const originalDocumentLengthCounts =
            orig.getDocumentLengthCounts();
    documentLengthCounts = new int[noDocuments];
    for (int i = 0; i < noDocuments; i++) {
        documentLengthCounts[i] = originalDocumentLengthCounts[i];
    }
    topicBits = orig.getTopicBits();
    int const * const * const originalTopicDocumentCounts =
            orig.getTopicDocumentCounts();
    topicDocumentCounts = new int*[noTopics];
    for (int i = 0; i < noTopics; i++) {
        topicDocumentCounts[i] = new int[noDocuments];
        for (int j = 0; j < noDocuments; j++) {
            topicDocumentCounts[i][j] = originalTopicDocumentCounts[i][j];
        }
    }
    topicMask = orig.getTopicMask();
}

ParallelTopicModelWorker::~ParallelTopicModelWorker() {
    delete [] documentLengthCounts;
    for (int i = 0; i < noTopics; i++) {
        delete [] topicDocumentCounts[i];
    }
    delete [] topicDocumentCounts;
    delete typeTopicCounts;
}

int const * const ParallelTopicModelWorker::getDocumentLengthCounts() const {
    return documentLengthCounts;
}

int const ParallelTopicModelWorker::getNoDocuments() const {
    return noDocuments;
}

int const ParallelTopicModelWorker::getStartDocument() const {
    return startDocument;
}

int const ParallelTopicModelWorker::getTopicBits() const {
    return topicBits;
}

int const * const * const ParallelTopicModelWorker::getTopicDocumentCounts()
const {
    return topicDocumentCounts;
}

int const ParallelTopicModelWorker::getTopicMask() const {
    return topicMask;
}

void ParallelTopicModelWorker::collectAlphaStatistics() {
    shouldSaveState = true;
}
