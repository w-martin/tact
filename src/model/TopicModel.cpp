/**
 * @file TopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "tmte-cpp/model/TopicModel.h"

TopicModel::TopicModel() {
}

TopicModel::TopicModel(const TopicModel& orig) {
    noTopics = orig.getNoTopics();

    double const * const tmp = orig.getAlpha();
    alpha = new double[noTopics];
    for (int i = 0; i < noTopics; i++) {
        alpha[i] = tmp[i];
    }

    alphaSum = orig.getAlphaSum();
    beta = orig.getBeta();
    betaSum = orig.getBetaSum();
    copyTokensPerTopic(orig.getTokensPerTopic());
    copyTopicAssignments(orig.getTopicAssignments());
    copyTypeTopicCounts(orig.getTypeTopicCounts());
}

TopicModel::~TopicModel() {
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

int const * const TopicModel::getTokensPerTopic() const {
    return tokensPerTopic;
}

vector<TopicAssignment*> * const TopicModel::getTopicAssignments()
const {
    return topicAssignments;
}

vector<vector<int> > const * const TopicModel::getTypeTopicCounts() const {
    return typeTopicCounts;
}

void TopicModel::deleteAssignments() {
    for (int i = 0; i < topicAssignments->size(); i++) {
        delete topicAssignments->at(i);
    }
    delete topicAssignments;
}

void TopicModel::copyTokensPerTopic(
        int const * const orig) {
    tokensPerTopic = new int[noTopics];
    for (int i = 0; i < noTopics; i++) {
        tokensPerTopic[i] = orig[i];
    }
}

void TopicModel::copyTopicAssignments(
        vector<TopicAssignment*> const * const orig) {
    topicAssignments = new vector<TopicAssignment*>();
    for (int i = 0; i < orig->size(); i++) {
        topicAssignments->push_back(
                new TopicAssignment(*orig->at(i)));
    }
}

void TopicModel::copyTypeTopicCounts(
        vector<vector<int> > const * const orig) {
    typeTopicCounts = new vector<vector<int> >();
    for (int i = 0; i < orig->size(); i++) {
        typeTopicCounts->push_back(vector<int>(orig->at(i)));
    }
}
