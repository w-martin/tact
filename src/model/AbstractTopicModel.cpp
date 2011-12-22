/**
 * @file AbstractTopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/model/AbstractTopicModel.h"
#include <sstream>

using std::stringstream;

AbstractTopicModel::AbstractTopicModel(int const noIterations,
        int const noTopics) {
    AbstractTopicModel::noIterations = noIterations;
    AbstractTopicModel::noTopics = noTopics;

    alpha = new double[noTopics];
    for (int i = 0; i < noTopics; i++) {
        alpha[i] = 0.0;
    }
    alphaSum = 0.0;

    beta = DEFAULT_BETA;
    betaSum = 0.0;
    tokensPerTopic = new vector<int>(noTopics, 0);
    topicAssignments = new vector<TopicAssignment*>();
    typeTopicCounts = new vector<vector<int> >();
}

AbstractTopicModel::AbstractTopicModel(const AbstractTopicModel& orig)
: TopicModel(orig) {
    noIterations = orig.getNoIterations();
}

AbstractTopicModel::~AbstractTopicModel() {
    delete [] alpha;
    deleteAssignments();
    delete tokensPerTopic;
    delete typeTopicCounts;
}

int const AbstractTopicModel::getNoIterations() const {
    return noIterations;
}

void AbstractTopicModel::addInstances(auto_ptr<InstanceList> instanceList) {
    AbstractTopicModel::instanceList = instanceList;
    deleteAssignments();
    topicAssignments = new vector<TopicAssignment*>();
    vector<Instance*> const * const instances =
            AbstractTopicModel::instanceList->getInstances();
    for (int i = 0; i < AbstractTopicModel::instanceList->getSize(); i++) {
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
