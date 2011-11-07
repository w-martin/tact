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
#include "tmte-cpp/main/model/Instance.h"
#include <vector>

using std::vector;

/**
 * Represents a Topic Model.
 * 
 */
class TopicModel {
public:
    TopicModel(int const noIterations,
            int const noTopics);
    TopicModel(const TopicModel& orig);
    virtual ~TopicModel();
    /**
     * Gets the Alphabet.
     * 
     * @return the Alphabet.
     * 
     */
    virtual Alphabet const * const getAlphabet() const;
    /**
     * Gets the number of iterations of EM training to do.
     * 
     * @return the number of iterations of EM training to do.
     * 
     */
    int const getNoIterations() const;
    /**
     * Gets the number of Topics.
     * 
     * @return the number of Topics.
     * 
     */
    int const getNoTopics() const;
    /**
     * Adds the given Instances to this TopicModel.
     * 
     * @param instances the Instances to add to this TopicModel.
     * 
     */
    virtual void addInstances(vector<Instance*> const * const instances);
private:
    int noIterations;
    int noTopics;
};

#endif	/* TOPICMODEL_H */

