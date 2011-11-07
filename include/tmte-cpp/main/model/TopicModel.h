/**
 * @file TopicModel.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef TOPICMODEL_H
#define	TOPICMODEL_H

#include "tmte-cpp/main/model/Alphabet.h"
#include <memory>

using std::auto_ptr;

/**
 * Represents a Topic Model.
 * 
 */
class TopicModel {
public:
    TopicModel();
    TopicModel(const TopicModel& orig);
    virtual ~TopicModel();
    Alphabet const * const getAlphabet() const;
    void setAlphabet(auto_ptr<Alphabet> alphabet);
private:
    auto_ptr<Alphabet> alphabet;
};

#endif	/* TOPICMODEL_H */

