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

TopicModel::TopicModel() {
}

TopicModel::TopicModel(const TopicModel& orig) {
}

TopicModel::~TopicModel() {
}

void TopicModel::setAlphabet(
        auto_ptr<Alphabet> alphabet) {
    TopicModel::alphabet = alphabet;
}

Alphabet const * const TopicModel::getAlphabet() const {
    return alphabet.get();
}
