/**
 * @file RandomNumberGenerator.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/algorithm/RandomNumberGenerator.h"
#include <stdlib.h>
#include <time.h>

RandomNumberGenerator::RandomNumberGenerator() {
    count = 0;
    seed = time(NULL);
}

RandomNumberGenerator::RandomNumberGenerator(const int seed) {
    count = 0;
    RandomNumberGenerator::seed = seed;
}

RandomNumberGenerator::RandomNumberGenerator(
        const RandomNumberGenerator& orig) {
    count = orig.getCount();
    seed = orig.getSeed();
}

RandomNumberGenerator::~RandomNumberGenerator() {
}

int const RandomNumberGenerator::getCount() const {
    return count;
}

int const RandomNumberGenerator::getSeed() const {
    return seed;
}

double const RandomNumberGenerator::nextUniform() {
    srand((unsigned int) time(NULL));
    // ensures consecutive calls generate different numbers
    for (int i = 0; i < count; i++) {
        rand();
    }
    double r = rand() / double(RAND_MAX);
    count++;
    srand(1);
    return r;
}
