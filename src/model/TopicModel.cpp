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

vector<int> const * const TopicModel::getTokensPerTopic() const {
    return tokensPerTopic;
}

vector<TopicAssignment*> * const TopicModel::getTopicAssignments()
const {
    return topicAssignments;
}

vector<vector<int>*> const * const TopicModel::getTypeTopicCounts() const {
    return typeTopicCounts;
}

void TopicModel::deleteAssignments() {
    for (int i = 0; i < topicAssignments->size(); i++) {
        delete topicAssignments->at(i);
    }
    delete topicAssignments;
}

void TopicModel::copyTopicAssignments(TopicModel const & orig) {
    vector<TopicAssignment*> const * const originalAssignments =
            orig.getTopicAssignments();
    topicAssignments = new vector<TopicAssignment*>();
    for (int i = 0; i < originalAssignments->size(); i++) {
        topicAssignments->push_back(
                new TopicAssignment(*originalAssignments->at(i)));
    }
}
