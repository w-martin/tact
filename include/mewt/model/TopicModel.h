/**
 * @file TopicModel.h
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

#ifndef TOPICMODEL_H
#define	TOPICMODEL_H

#include "mewt/model/ProbabilityMatrix.h"
#include "mewt/util/exceptions/OutOfBoundsException.h"
#include <vector>

using std::vector;

/**
 * Represents an abstract Topic Model.
 * 
 */
class TopicModel {
public:
    TopicModel();
    TopicModel(const TopicModel& orig);
    virtual ~TopicModel();
    /**
     * Gets the number of documents in this Topic Model.
     * 
     * @return  the number of documents in this Topic Model.
     * 
     */
    int const getNoDocuments() const;
    /**
     * Gets the number of Topics.
     * 
     * @return the number of Topics.
     * 
     */
    int const getNoTopics() const;
    /**
     * Gets the array of alpha values.
     * 
     * @return the array of alpha values.
     * 
     */
    double const * const getAlpha() const;
    /**
     * Sets alpha at the specified index.
     * 
     * @param index the index to set.
     * @param value the value to set.
     * @throws OutOfBoundsException if the index is out of bounds.
     * 
     */
    void setAlpha(int const & index, double const value)
    throw (OutOfBoundsException);
    /**
     * Gets the alpha sum.
     * 
     * @return the alpha sum.
     * 
     */
    double const getAlphaSum() const;
    /**
     * Gets the beta value.
     * 
     * @return the beta value.
     * 
     */
    double const getBeta() const;
    /**
     * Sets the beta value.
     * 
     * @param beta the beta value.
     * 
     */
    void setBeta(double const beta);
    /**
     * Gets the beta sum.
     * 
     * @return the beta sum.
     *  
     */
    double const getBetaSum() const;
    /**
     * Gets the topic-document probability matrix, indexed by 
     * [document][topic].
     * 
     * @return the topic-document probability matrix.
     * 
     */
    ProbabilityMatrix const * const getTopicDocumentMatrix() const;
    /**
     * Gets the term-topic probability matrix, indexed by [topic][term].
     * 
     * @return the term-topic probability matrix.
     * 
     */
    ProbabilityMatrix const * const getTermTopicMatrix() const;
protected:
    /**
     * Dirichlet(alpha,alpha,...) is the distribution over topics.
     * 
     */
    double * alpha;
    double alphaSum;
    /**
     * Prior on per-topic multinomial distribution over words.
     * 
     */
    double beta;
    double betaSum;
    int noDocuments;
    int noTopics;
    /**
     * Topic-Document probability matrix.
     * Indexed by [document][topic].
     * 
     */
    ProbabilityMatrix * topicDocumentMatrix;
    /**
     * Term-Topic probability matrix.
     * Indexed by [topic][term].
     * 
     */
    ProbabilityMatrix * termTopicMatrix;
};

#endif	/* TOPICMODEL_H */
