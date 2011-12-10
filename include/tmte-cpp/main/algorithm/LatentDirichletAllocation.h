/**
 * @file LatentDirichletAllocation.h
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

#include "tmte-cpp/main/model/TopicModel.h"

/**
 * Performs LDA on a corpus.
 * 
 */
class LatentDirichletAllocation : public TopicModel {
public:
    LatentDirichletAllocation(int const noIterations, int const noTopics);
    LatentDirichletAllocation(const LatentDirichletAllocation& orig);
    virtual ~LatentDirichletAllocation();
    /**
     * Estimates the topic model.
     * 
     */
    virtual void estimate();
private:

};

#endif	/* LATENTDIRICHLETALLOCATION_H */

