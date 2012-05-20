/**
 * @file AbstractTopicModel.cpp
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

#include "mewt/algorithm/AbstractTopicModel.h"
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
    tokensPerTopic = new int[noTopics];
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
        TopicAssignment * assignment = new TopicAssignment(instance,
                new FeatureVector(
                auto_ptr<Alphabet > (new Alphabet()),
                auto_ptr<vector<int> >(new vector<int>())));
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
