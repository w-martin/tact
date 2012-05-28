/**
 * @file AbstractTopicModel.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#ifndef ABSTRACTTOPICMODEL_H
#define	ABSTRACTTOPICMODEL_H

#define DEFAULT_BETA 0.01

#include "mewt/input/InstanceList.h"
#include "mewt/input/Alphabet.h"
#include "mewt/model/TopicModel.h"

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
