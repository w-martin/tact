/**
 * @file ParallelTopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#include "mewt/algorithm/ParallelTopicModel.h"
#include "mewt/algorithm/ParallelTopicModelWorker.h"
#include <time.h>
#include <iostream>
#include <pthread.h>

ParallelTopicModel::ParallelTopicModel(
        int const noIterations,
        int const noTopics,
        int const noThreads)
: AbstractTopicModel(noIterations, noTopics) {

    ParallelTopicModel::noThreads = noThreads;

    // needed for estimation
    burnInPeriod = 200;
    saveSampleInterval = 10;
    optimizeInterval = 50;
    temperingInterval = 0;
    showTopicsInterval = 50;
    wordsPerTopic = 7;
    saveStateInterval = 0;
}

ParallelTopicModel::ParallelTopicModel(
        const ParallelTopicModel& orig)
: AbstractTopicModel(orig) {

    noThreads = orig.getNoThreads();

    // needed for estimation
    burnInPeriod = 200;
    saveSampleInterval = 10;
    optimizeInterval = 50;
    temperingInterval = 0;
    showTopicsInterval = 50;
    wordsPerTopic = 7;
    saveStateInterval = 0;
}

ParallelTopicModel::~ParallelTopicModel() {
}

int const ParallelTopicModel::getNoThreads() const {
    return noThreads;
}

void * run(void* argv);

void ParallelTopicModel::estimate() {
    long startTime = time(NULL);
    int noDocumentsPerThread = topicAssignments->size() / noThreads;
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
        RandomNumberGenerator * const randomNumberGenerator =
                new RandomNumberGenerator();
        workers->push_back(new ParallelTopicModelWorker(
                alpha,
                alphaSum,
                beta,
                noDocumentsPerThread,
                noTopics,
                typeTopicCounts->size(),
                randomNumberGenerator,
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
    pthread_t ** threads = new pthread_t*[noThreads];
    for (int iteration = 0; iteration < noIterations; iteration++) {
        // note start time
        //            long iterationStart = System.currentTimeMillis();
        long iterationStartTime = time(NULL);

        // ignored for now
        // log information and save state and model
        //        if (showTopicsInterval != 0 && iteration != 0 && iteration % showTopicsInterval == 0) {
        //                logger.info("\n" + displayTopWords(wordsPerTopic, false));
        //            }
        //
        //            if (saveStateInterval != 0 && iteration % saveStateInterval == 0) {
        //                this.printState(new File(stateFilename + '.' + iteration));
        //            }
        //
        //            if (saveModelInterval != 0 && iteration % saveModelInterval == 0) {
        //                this.write(new File(modelFilename + '.' + iteration));
        //            }

        // start threads
        for (int i = 0; i < noThreads; i++) {
            // collect statistics
            if (iteration > burnInPeriod
                    && optimizeInterval != 0
                    && iteration % saveSampleInterval == 0) {
                workers->at(i)->collectAlphaStatistics();
            }

            // log thread started
            //            logger.fine("submitting thread " + thread);

            // start thread
            //            executor.submit(runnables[thread]);
            pthread_t thread;
            pthread_create(&thread, NULL, run, (void*) workers->at(i));
            threads[i] = &thread;
        }
        // wait on threads
        for (int i = 0; i < noThreads; i++) {
            pthread_t thread = *threads[i];
            pthread_join(thread, NULL);
        }
        // evaluate
        // here
    }

    // free memory
    for (int i = 0; i < workers->size(); i++) {
        delete workers->at(i);
    }
    delete workers;
    delete threads;
}

void * run(void* argv) {
    ParallelTopicModelWorker * worker = (ParallelTopicModelWorker*) argv;
    //    int i = *(int*) argv;
    //    cout << "I am thread " << i << endl;

    worker->run();

    return NULL;
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
