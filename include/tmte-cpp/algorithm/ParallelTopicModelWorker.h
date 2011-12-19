/**
 * @file ParallelTopicModelWorker.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#ifndef PARALLELTOPICMODELWORKER_H
#define	PARALLELTOPICMODELWORKER_H

#include "tmte-cpp/output/TopicAssignment.h"
#include <vector>

using std::vector;

class ParallelTopicModelWorker {
public:
    /**
     * Default constructor.
     * 
     * @param noTopics The number of topics.
     * @param alpha The alpha distribution over topics.
     * @param alphaSum The sum of the alpha distribution.
     * @param beta The prior on the per-topic multinomial distribution over 
     * words.
     * @param topicAssignments The initial topic assignments.
     * @param typeTopicCounts The topic counts for each feature.
     * @param tokensPerTopic The array of tokens per topic.
     * @param startDocument The starting document for this Worker.
     * @param noDocuments The total number of documents in the input space.
     * 
     */
    ParallelTopicModelWorker(
            double * alpha,
            double alphaSum,
            double beta,
            int noDocuments,
            int noTopics,
            int startDocument,
            int * tokensPerTopic,
            vector<TopicAssignment*> * topicAssignments,
            int * * typeTopicCounts);
    ParallelTopicModelWorker(const ParallelTopicModelWorker& orig);
    virtual ~ParallelTopicModelWorker();
    
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
    /**
     * Histogram of document lengths.
     * Used for dirichlet estimation.
     * 
     */
    int * documentLengthCounts;
    int noDocuments;
    int noTopics;
    int noTypes;
    int startDocument;
    /**
     * Indexed by topic.
     * 
     */
    int * tokensPerTopic;
    vector<TopicAssignment*> * topicAssignments;
    /**
     * Used to encode type/topic counts as count/topic pairs in a single 
     * integer.
     * 
     */
    int topicBits;
    /**
     *  Histogram of document/topic counts, indexed by: 
     * [topic index, sequence position index].
     * Used for dirichlet estimation.
     * 
     */
    int * * topicDocumentCounts;
    /**
     * Used to encode type/topic counts as count/topic pairs in a single 
     * integer.
     * 
     */
    int topicMask;
    /**
     * Indexed by [feature index, topic index].
     * 
     */
    int * * typeTopicCounts;
};

#endif	/* PARALLELTOPICMODELWORKER_H */
