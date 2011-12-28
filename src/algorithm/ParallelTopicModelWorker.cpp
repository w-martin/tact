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

#include <iostream>

#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"
#include "tmte-cpp/input/FeatureVector.h"

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

    // needed for estimation
    cachedCoefficients = new double[noTopics];
    isFinished = false;
    shouldSaveState = false;
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

    // needed for estimation
    cachedCoefficients = new double[noTopics];
    isFinished = true;
    shouldSaveState = false;
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

void ParallelTopicModelWorker::run() {

    //    try {
    //
    //        if (!isFinished) {
    //            System.out.println("already running!");
    //            return;
    //        }
    if (!isFinished) {
        std::cout << "already running!";
        return;
    }

    //        isFinished = false;
    isFinished = false;

    //        // Initialize the smoothing-only sampling bucket
    //        smoothingOnlyMass = 0;
    smoothingOnlyMass = 0;

    //        // Initialize the cached coefficients, using only smoothing.
    //        //  These values will be selectively replaced in documents with
    //        //  non-zero counts in particular topics.
    //
    //        for (int topic = 0; topic < numTopics; topic++) {
    //            smoothingOnlyMass += alpha[topic] * beta / (tokensPerTopic[topic] + betaSum);
    //            cachedCoefficients[topic] = alpha[topic] / (tokensPerTopic[topic] + betaSum);
    //        }
    for (int topic = 0; topic < noTopics; topic++) {
        smoothingOnlyMass += alpha[topic] * beta /
                (tokensPerTopic->at(topic) + betaSum);
        cachedCoefficients[topic] = alpha[topic] /
                (tokensPerTopic->at(topic) + betaSum);
    }

    //        for (int doc = startDoc;
    //                doc < data.size() && doc < startDoc + numDocs;
    //                doc++) {
    //
    //            /*
    //            if (doc % 10000 == 0) {
    //            System.out.println("processing doc " + doc);
    //            }
    //             */
    //
    //            FeatureSequence tokenSequence =
    //                    (FeatureSequence) data.get(doc).instance.getData();
    //            LabelSequence topicSequence =
    //                    (LabelSequence) data.get(doc).topicSequence;
    //
    //            sampleTopicsForOneDoc(tokenSequence, topicSequence,
    //                    true);
    //        }
    for (int doc = startDocument;
            doc < noDocuments && doc < (startDocument + noDocuments);
            doc++) {
//        FeatureVector * tokenSequence = data->at(i)->getData();
    }

    //        if (shouldBuildLocalCounts) {
    //            buildLocalTypeTopicCounts();
    //        }
    //
    //        shouldSaveState = false;
    //        isFinished = true;
    //
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //    }
}
