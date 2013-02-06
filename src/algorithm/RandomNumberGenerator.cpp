/**
 * @file RandomNumberGenerator.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

mewt::algorithm::RandomNumberGenerator::RandomNumberGenerator() {
    count = 0;
    seed = time(NULL);
}

mewt::algorithm::RandomNumberGenerator::RandomNumberGenerator(const int seed) {
    count = 0;
    mewt::algorithm::RandomNumberGenerator::seed = seed;
}

mewt::algorithm::RandomNumberGenerator::RandomNumberGenerator(
        const RandomNumberGenerator& orig) {
    count = orig.getCount();
    seed = orig.getSeed();
}

mewt::algorithm::RandomNumberGenerator::~RandomNumberGenerator() {
}

int const mewt::algorithm::RandomNumberGenerator::getCount() const {
    return count;
}

int const mewt::algorithm::RandomNumberGenerator::getSeed() const {
    return seed;
}

double const mewt::algorithm::RandomNumberGenerator::nextUniform() {
    // ensures consecutive calls generate different numbers
    srand((unsigned int) time(NULL) - count);
    double r = rand() / double(RAND_MAX);
    count++;
    srand(1);
    return r;
}
