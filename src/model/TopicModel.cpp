/**
 * @file TopicModel.cpp
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

#include "mewt/model/TopicModel.h"

TopicModel::TopicModel() {
}

TopicModel::TopicModel(const TopicModel& orig) {
    noDocuments = orig.getNoDocuments();
    noTopics = orig.getNoTopics();

    double const * const tmp = orig.getAlpha();
    alpha = new double[noTopics];
    for (int i = 0; i < noTopics; i++) {
        alpha[i] = tmp[i];
    }

    alphaSum = orig.getAlphaSum();
    beta = orig.getBeta();
    betaSum = orig.getBetaSum();
    topicDocumentMatrix = new ProbabilityMatrix(*orig.getTopicDocumentMatrix());
    termTopicMatrix = new ProbabilityMatrix(*orig.getTermTopicMatrix());
}

TopicModel::~TopicModel() {
}

int const TopicModel::getNoDocuments() const {
    return noDocuments;
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

ProbabilityMatrix const * const TopicModel::getTopicDocumentMatrix() const {
    return topicDocumentMatrix;
}

ProbabilityMatrix const * const TopicModel::getTermTopicMatrix() const {
    return termTopicMatrix;
}
