/**
 * @file TopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/main/model/TopicModel.h"
#include <cstring>

TopicModel::TopicModel(int const noIterations,
        int const noTopics) {
    TopicModel::noIterations = noIterations;
    TopicModel::noTopics = noTopics;
    TopicModel::alpha = (double*) calloc(noTopics, sizeof (double));
    alphaSum = 0.0;
    beta = DEFAULT_BETA;
    betaSum = 0.0;
}

TopicModel::TopicModel(const TopicModel& orig) {
    TopicModel::noIterations = orig.getNoIterations();
    TopicModel::noTopics = orig.getNoTopics();
    double const * const originalAlpha = orig.getAlpha();
    memcpy(&alpha, &originalAlpha, sizeof (originalAlpha));
    TopicModel::alphaSum = orig.getAlphaSum();
    TopicModel::beta = orig.getBeta();
    TopicModel::betaSum = orig.getBetaSum();
}

TopicModel::~TopicModel() {
    free(alpha);
}

int const TopicModel::getNoIterations() const {
    return noIterations;
}

int const TopicModel::getNoTopics() const {
    return noTopics;
}

double const * const TopicModel::getAlpha() const {
    return alpha;
}

void TopicModel::setAlpha(int const & index,
        const double value)
throw (OutOfBoundsException) {
    if (index >= noTopics) {
        throw OutOfBoundsException(index, noTopics);
    } else {
        alphaSum -= alpha[index];
        alpha[index] = value;
        alphaSum += value;
    }
}

double const TopicModel::getAlphaSum() const {
    return alphaSum;
}

double const TopicModel::getBeta() const {
    return beta;
}

void TopicModel::setBeta(const double beta) {
    TopicModel::beta = beta;
}

double const TopicModel::getBetaSum() const {
    return betaSum;
}
