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

#include "tmte-cpp/main/input/Instance.h"
#include "tmte-cpp/main/output/Assignment.h"

/**
 * Represents an assignment of Topics to an Instance.
 * 
 */
class TopicAssignment : Assignment {
public:
    TopicAssignment();
    TopicAssignment(TopicAssignment const & orig);
    virtual ~TopicAssignment();
private:
    Instance const * instance;
    
};

#endif	/* TOPICASSIGNMENT_H */
