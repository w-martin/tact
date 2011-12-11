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

using namespace std;

void *thread(void *argv)
{
    cout<<"Into a spawned thread"<<endl;
}

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

void LatentDirichletAllocation::estimate() {
    
    pthread_t t;
    pthread_create(&t,NULL,thread,NULL);
    pthread_join(t,NULL);
    cout<<"Back in main thread"<<endl;
}
