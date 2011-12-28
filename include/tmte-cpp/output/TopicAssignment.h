/**
 * @file TopicAssignment.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef TOPICASSIGNMENT_H
#define	TOPICASSIGNMENT_H

#include "tmte-cpp/input/Instance.h"
#include "tmte-cpp/output/Assignment.h"

/**
 * Represents an assignment of Topics to an Instance.
 * 
 */
class TopicAssignment : public Assignment {
public:
    TopicAssignment(Instance const * const instance,
            FeatureVector * const topicSequence);
    TopicAssignment(TopicAssignment const & orig);
    virtual ~TopicAssignment();
    /**
     * Gets the Instance that Topics are assigned to.
     * 
     * @return the Instance that Topics are assigned to.
     * 
     */
    Instance const * const getInstance() const;
    /**
     * Gets the Topic sequence.
     * 
     * @return the Topic sequence.
     * 
     */
    FeatureVector * const getTopicSequence() const;
private:
    Instance const * instance;
    FeatureVector * topicSequence;
};

#endif	/* TOPICASSIGNMENT_H */
