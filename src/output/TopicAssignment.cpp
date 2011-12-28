/**
 * @file TopicAssignment.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include "tmte-cpp/output/TopicAssignment.h"

TopicAssignment::TopicAssignment(Instance const * const instance,
        FeatureVector * const topicSequence) {
    TopicAssignment::instance = instance;
    TopicAssignment::topicSequence = topicSequence;
}

TopicAssignment::TopicAssignment(TopicAssignment const & orig)
: Assignment(orig) {
    TopicAssignment::instance = orig.getInstance();
    TopicAssignment::topicSequence = orig.getTopicSequence();
}

TopicAssignment::~TopicAssignment() {
}

Instance const * const TopicAssignment::getInstance() const {
    return instance;
}

FeatureVector * const TopicAssignment::getTopicSequence() const {
    return topicSequence;
}
