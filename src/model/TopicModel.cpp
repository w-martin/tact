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

TopicModel::TopicModel(int const noIterations,
        int const noTopics) {
    TopicModel::noIterations = noIterations;
    TopicModel::noTopics = noTopics;
}

TopicModel::TopicModel(const TopicModel& orig) {
    TopicModel::noIterations = orig.getNoIterations();
    TopicModel::noTopics = orig.getNoTopics();
}

TopicModel::~TopicModel() {
}

int const TopicModel::getNoIterations() const {
    return noIterations;
}

int const TopicModel::getNoTopics() const {
    return noTopics;
}
