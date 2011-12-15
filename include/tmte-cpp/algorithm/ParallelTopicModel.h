/**
 * @file ParallelTopicModel.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef LATENTDIRICHLETALLOCATION_H
#define	LATENTDIRICHLETALLOCATION_H

#include "tmte-cpp/model/TopicModel.h"

/**
 * Performs LDA on a corpus.
 * 
 */
class ParallelTopicModel : public TopicModel {
public:
    ParallelTopicModel(
            int const noIterations,
            int const noTopics,
            int const noThreads);
    ParallelTopicModel(const ParallelTopicModel& orig);
    virtual ~ParallelTopicModel();
    /**
     * Estimates the topic model.
     * 
     */
    virtual void estimate();
    /**
     * Gets the number of threads for this algorithm to use.
     * 
     * @return the number of threads for this algorithm to use.
     * 
     */
    int const getNoThreads() const;
private:
    int noThreads;
};

#endif	/* LATENTDIRICHLETALLOCATION_H */
