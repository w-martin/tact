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

/**
 * Represents a Topic Model.
 * 
 */
class TopicModel {
public:
    TopicModel(int const noIterations);
    TopicModel(const TopicModel& orig);
    virtual ~TopicModel();
    virtual Alphabet const * const getAlphabet() const;
    virtual int const getNoTopics() const;
    int const getNoIterations() const;
    void setNoIterations(int const noIterations);
private:
    int noIterations;
};

#endif	/* TOPICMODEL_H */

