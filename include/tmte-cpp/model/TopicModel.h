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

#include "tmte-cpp/output/TopicAssignment.h"
#include "tmte-cpp/util/exceptions/OutOfBoundsException.h"
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
     * Gets the histogram of tokens per topic. Indexed by Topic.
     * 
     * @return the histogram of tokens per topic.
     * 
     */
    vector<int> const * const getTokensPerTopic() const;
    /**
     * Gets the list of TopicAssignments.
     * 
     * @return the list of TopicAssignments.
     * 
     */
    vector<TopicAssignment*> * const getTopicAssignments() const;
    /**
     * Gets the type/topic counts.
     * Indexed by [feature index, topic index].
     * 
     * @return the type/topic counts.
     * 
     */
    vector<vector<int> > const * const getTypeTopicCounts() const;
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
    int noTopics;
    /**
     * Indexed by topic.
     * 
     */
    vector<int> * tokensPerTopic;
    vector<TopicAssignment*> * topicAssignments;
    /**
     * Indexed by [feature index, topic index].
     * 
     */
    vector<vector<int> > * typeTopicCounts;
    /**
     * Copies the given tokensPerTopic.
     * 
     * @param orig The tokensPerTopic to copy.
     * 
     */
    void copyTokensPerTopic(vector<int> const * const orig);
    /**
     * Copies the TopicAssignments from the given TopicModel.
     * 
     * @param orig The TopicModel to copy the TopicAssignments from.
     * 
     */
    void copyTopicAssignments(vector<TopicAssignment*> const * const orig);
    /**
     * Copies the given typeTopicCounts.
     * 
     * @param orig the typeTopicCounts to copy.
     * 
     */
    void copyTypeTopicCounts(vector<vector<int> > const * const orig);
    /**
     * Deletes the TopicAssignments.
     * 
     */
    void deleteAssignments();
};

#endif	/* TOPICMODEL_H */
