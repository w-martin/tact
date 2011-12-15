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
#include <time.h>
#include <iostream>
#include <pthread.h>

ParallelTopicModel::ParallelTopicModel(
        int const noIterations,
        int const noTopics,
        int const noThreads)
: TopicModel(noIterations, noTopics) {
    ParallelTopicModel::noThreads = noThreads;
}

ParallelTopicModel::ParallelTopicModel(
        const ParallelTopicModel& orig)
: TopicModel(orig) {
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
    pthread_t * threads = new pthread_t[noThreads];
    for (int i = 0; i < noThreads; i++) {
        
    }
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
