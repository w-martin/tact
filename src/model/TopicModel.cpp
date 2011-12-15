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
#include "tmte-cpp/output/TopicAssignment.h"
#include <sstream>

using std::stringstream;

TopicModel::TopicModel(int const noIterations,
        int const noTopics) {
    TopicModel::noIterations = noIterations;
    TopicModel::noTopics = noTopics;

    alpha = new double[noTopics];
    for (int i = 0; i < noTopics; i++) {
        alpha[i] = 0;
    }

    alphaSum = 0.0;
    beta = DEFAULT_BETA;
    betaSum = 0.0;

    topicAssignments = new vector<TopicAssignment*> ();
}

TopicModel::TopicModel(const TopicModel& orig) {
    noIterations = orig.getNoIterations();
    noTopics = orig.getNoTopics();

    double const * const tmp = orig.getAlpha();
    alpha = new double[noTopics];
    for (int i = 0; i < noTopics; i++) {
        alpha[i] = tmp[i];
    }

    alphaSum = orig.getAlphaSum();
    beta = orig.getBeta();
    betaSum = orig.getBetaSum();

    topicAssignments = new vector<TopicAssignment*> ();
    vector<TopicAssignment*> const * const originalAssignments =
            orig.getTopicAssignments();
    for (int i = 0; i < originalAssignments->size(); i++) {
        TopicAssignment * copy =
                new TopicAssignment(*originalAssignments->at(i));
        topicAssignments->push_back(copy);
    }
}

TopicModel::~TopicModel() {
    delete [] alpha;
    deleteAssignments();
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

vector<TopicAssignment*> const * const TopicModel::getTopicAssignments() const {
    return topicAssignments;
}

void TopicModel::addInstances(auto_ptr<InstanceList> instanceList) {
    TopicModel::instanceList = instanceList;
    deleteAssignments();
    topicAssignments = new vector<TopicAssignment*>();
    vector<Instance*> const * const instances =
            TopicModel::instanceList->getInstances();
    for (int i = 0; i < TopicModel::instanceList->getSize(); i++) {
        Instance const * const instance = instances->at(i);
        TopicAssignment * assignment = new TopicAssignment(instance);
        for (int t = 0; t < noTopics; t++) {
            stringstream stream;
            stream << t;
            string name = stream.str();
            Identifier id(name);
            assignment->add(id, 0.0);
        }
        topicAssignments->push_back(assignment);
    }
}

void TopicModel::deleteAssignments() {
    for (int i = 0; i < topicAssignments->size(); i++) {
        delete topicAssignments->at(i);
    }
    delete topicAssignments;
}
