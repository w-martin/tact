/**
 * @file TopicAssignment.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef TOPICASSIGNMENT_H
#define	TOPICASSIGNMENT_H

#include "mewt/input/Instance.h"
#include "mewt/output/Assignment.h"

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
