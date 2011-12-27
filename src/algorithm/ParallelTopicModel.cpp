/**
 * @file ParallelTopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/algorithm/ParallelTopicModel.h"
#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"
#include <time.h>
#include <iostream>
#include <pthread.h>

ParallelTopicModel::ParallelTopicModel(
        int const noIterations,
        int const noTopics,
        int const noThreads)
: AbstractTopicModel(noIterations, noTopics) {
    ParallelTopicModel::noThreads = noThreads;
}

ParallelTopicModel::ParallelTopicModel(
        const ParallelTopicModel& orig)
: AbstractTopicModel(orig) {
    noThreads = orig.getNoThreads();
}

ParallelTopicModel::~ParallelTopicModel() {
}

int const ParallelTopicModel::getNoThreads() const {
    return noThreads;
}

void ParallelTopicModel::estimate() {
    long startTime = time(NULL);
    int const noDocumentsPerThread = topicAssignments->size() / noThreads;
    // create worker objects
    vector<ParallelTopicModelWorker*> * const workers
            = new vector<ParallelTopicModelWorker*>();
    int startingDocument = 0;

    for (int i = 0; i < noThreads; i++) {
        // skip copy
        // runnableTotals is tokensPertopic
        //        int[] runnableTotals = new int[numTopics];
        //        System.arraycopy(tokensPerTopic, 0, runnableTotals, 0, numTopics);

        // runnableCounts is typeTopicCounts
        //        int[][] runnableCounts = new int[numTypes][];
        //        for (int type = 0; type < numTypes; type++) {
        //            int[] counts = new int[typeTopicCounts[type].length];
        //            System.arraycopy(typeTopicCounts[type], 0, counts, 0, counts.length);
        //            runnableCounts[type] = counts;
        //        }

        //        // some docs may be missing at the end due to integer division
        //        if (thread == numThreads - 1) {
        //            docsPerThread = data.size() - offset;
        //        }
        if (noThreads - 1 == i) {
            noDocumentsPerThread = topicAssignments->size() - startingDocument;
        }

        // ignoring random number generator for now
        //        Randoms random = null;
        //        if (randomSeed == -1) {
        //            random = new Randoms();
        //        } else {
        //            random = new Randoms(randomSeed);
        //        }

        // assign thread objects
        //        runnables[thread] = new WorkerRunnable(numTopics,
        //                alpha, alphaSum, beta,
        //                random, data,
        //                runnableCounts, runnableTotals,
        //                offset, docsPerThread);
        workers->push_back(new ParallelTopicModelWorker(
                alpha,
                alphaSum,
                beta,
                noDocumentsPerThread,
                noTopics,
                typeTopicCounts->size(),
                startingDocument,
                tokensPerTopic,
                topicAssignments,
                typeTopicCounts));

        // ignored as this is done in worker constructor
        // initializes statistics gathering
        //        runnables[thread].initializeAlphaStatistics(docLengthCounts.length);

        // increment starting document for thread
        //        offset += docsPerThread;
        startingDocument += noDocumentsPerThread;
    }
    // start threads
    pthread_t * threads = new pthread_t[noThreads];
    for (int i = 0; i < noThreads; i++) {

    }
    // wait on threads
    // evaluate

    // free memory
    for (int i = 0; i < workers->size(); i++) {
        delete workers->at(i);
    }
    delete workers;
    delete threads;
}

//void * thread(void *argv) {
//    int i = *(int*) argv;
//    cout << "I am thread " << i << endl;
//    return NULL;
//}
//
//void usesThread(){
//    vector<pthread_t> threads;
//    int numbers[4];
//    for (int i = 0; i < 4; i++) {
//        numbers[i] = i;
//        int * number = &numbers[i];
//        pthread_t t;
//        pthread_create(&t, NULL, thread, (void*) number);
//        threads.push_back(t);
//    }
//    for (int i = 0; i < 4; i++) {
//        pthread_t t = threads.at(i);
//        pthread_join(t, NULL);
//    }
//    cout << "Back in main thread" << endl;
//}
