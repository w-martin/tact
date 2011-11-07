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
     * Sets the number of iterations of EM training to do.
     * 
     * @param noIterations the number of iterations of EM training to do.
     * 
     */
    void setNoIterations(int const noIterations);
    /**
     * Gets the number of Topics.
     * 
     * @return the number of Topics.
     * 
     */
    int const getNoTopics() const;
    /**
     * Sets the number of Topics.
     * 
     * @param noTopics the number of Topics.
     * 
     */
    void setNoTopics(int const noTopics);
private:
    int noIterations;
    int noTopics;
};

#endif	/* TOPICMODEL_H */

