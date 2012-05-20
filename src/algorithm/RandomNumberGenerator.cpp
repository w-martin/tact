/**
 * @file RandomNumberGenerator.cpp
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

#include "mewt/algorithm/RandomNumberGenerator.h"
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
