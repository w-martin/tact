/**
 * @file ParallelTopicModel.h
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

#ifndef PARALLELTOPICMODEL_H
#define	PARALLELTOPICMODEL_H

#define UNASSIGNED_TOPIC -1

#include "mewt/algorithm/AbstractTopicModel.h"

/**
 * Performs LDA on a corpus.
 * 
 */
class ParallelTopicModel : public AbstractTopicModel {
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
    // needed for estimation
    int burnInPeriod;
    int saveSampleInterval;
    int optimizeInterval;
    int temperingInterval;
    int showTopicsInterval;
    int wordsPerTopic;
    int saveStateInterval;
};

#endif	/* PARALLELTOPICMODEL_H */

