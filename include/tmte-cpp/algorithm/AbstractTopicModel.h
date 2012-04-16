/**
 * @file AbstractTopicModel.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef ABSTRACTTOPICMODEL_H
#define	ABSTRACTTOPICMODEL_H

#define DEFAULT_BETA 0.01

#include "tmte-cpp/input/InstanceList.h"
#include "tmte-cpp/input/Alphabet.h"
#include "tmte-cpp/model/TopicModel.h"

/**
 * Represents an abstract Topic Model.
 * 
 */
class AbstractTopicModel : public TopicModel {
public:
    AbstractTopicModel(int const noIterations,
            int const noTopics);
    AbstractTopicModel(const AbstractTopicModel& orig);
    virtual ~AbstractTopicModel();

    /**
     * Gets the Alphabet.
     * 
     * @return the Alphabet.
     * 
     */
    virtual Alphabet const * const getAlphabet() const {
        return NULL;
    }
    /**
     * Gets the number of iterations of EM training to do.
     * 
     * @return the number of iterations of EM training to do.
     * 
     */
    int const getNoIterations() const;

    /**
     * Adds the given Instances to this TopicModel.
     * 
     * @param instances the Instances to add to this TopicModel.
     * 
     */
    virtual void addInstances(auto_ptr<InstanceList> instanceList);
    /**
     * Estimates the topic model.
     * 
     */
    virtual void estimate() {
    }
protected:
    int noIterations;
    auto_ptr<InstanceList> instanceList;
    Alphabet const * alphabet;
};

#endif	/* ABSTRACTTOPICMODEL_H */
