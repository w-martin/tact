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
#include <boost/thread.hpp>
#include <time.h>
#include <iostream>

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
    long startTime = time(NULL);
    int noThreads = boost::thread::hardware_concurrency();
    std::cout << noThreads;
}
