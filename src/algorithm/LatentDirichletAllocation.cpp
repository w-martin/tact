/**
 * @file LatentDirichletAllocation.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/main/algorithm/LatentDirichletAllocation.h"
#include <time.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

LatentDirichletAllocation::LatentDirichletAllocation(
        int const noIterations, int const noTopics)
: TopicModel(noIterations, noTopics) {
}

LatentDirichletAllocation::LatentDirichletAllocation(
        const LatentDirichletAllocation& orig)
: TopicModel(orig) {
}

LatentDirichletAllocation::~LatentDirichletAllocation() {
}

void * thread(void *argv) {
    int i = *(int*) argv;
//    cout << "I am thread " << i << endl;
    return NULL;
}

void LatentDirichletAllocation::estimate() {
    vector<pthread_t> threads;
    int numbers[4];
    for (int i = 0; i < 4; i++) {
        numbers[i] = i;
        int * number = &numbers[i];
        pthread_t t;
        pthread_create(&t, NULL, thread, (void*) number);
        threads.push_back(t);
    }
    for (int i = 0; i < 4; i++) {
        pthread_t t = threads.at(i);
        pthread_join(t, NULL);
    }
//    cout << "Back in main thread" << endl;
}
