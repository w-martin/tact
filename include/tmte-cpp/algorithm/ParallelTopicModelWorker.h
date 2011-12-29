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

#include "tmte-cpp/model/TopicModel.h"

class ParallelTopicModelWorker : public TopicModel {
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
            double * const alpha,
            double alphaSum,
            double beta,
            int const noDocuments,
            int const noTopics,
            int const noTypes,
            int const startDocument,
            int const * const tokensPerTopic,
            vector<TopicAssignment*> * topicAssignments,
            vector<vector<int> > const * const typeTopicCounts);
    ParallelTopicModelWorker(const ParallelTopicModelWorker& orig);
    virtual ~ParallelTopicModelWorker();
    /**
     * Gets the histogram of document lengths. Used for dirichlet estimation.
     * 
     * @return the histogram of document lengths.
     * 
     */
    int const * const getDocumentLengthCounts() const;
    /**
     * Gets the number of documents.
     * 
     * @return the number of documents.
     * 
     */
    int const getNoDocuments() const;
    /**
     * Gets the starting document.
     * 
     * @return the starting document.
     * 
     */
    int const getStartDocument() const;
    /**
     * Gets the topic bits encoding.
     * Used to encode type/topic counts as count/topic pairs in a single 
     * integer.
     * 
     * @return the topic bits encoding.
     * 
     */
    int const getTopicBits() const;
    /**
     * Gets the histogram of document/topic counts, indexed by: 
     * [topic index, sequence position index].
     * Used for dirichlet estimation.
     * 
     * @return the histogram of document/topic counts.
     * 
     */
    int const * const * const getTopicDocumentCounts() const;
    /**
     * Gets the topic encoding mask.
     * Used to encode type/topic counts as count/topic pairs in a single 
     * integer.
     * 
     * @return the topic encoding mask.
     * 
     */
    int const getTopicMask() const;
    /**
     * Collects alpha statistics.
     * 
     */
    virtual void collectAlphaStatistics();
    /**
     * Runs an iteration of the algorithm on the given data 
     * with the given parameters.
     * 
     */
    virtual void run();
    /**
     * Samples the topics for a single document whose tokenSequence and
     * topicSequence is given.
     * 
     * @param tokenSequence the tokenSequence for sampling.
     * @param topicSequence the topicSequence for sampling.
     * 
     */
    virtual void sampleTopics(FeatureVector * const tokenSequence,
            FeatureVector * const topicSequence);
protected:
    /**
     * Histogram of document lengths.
     * Used for dirichlet estimation.
     * 
     */
    int * documentLengthCounts;
    int noDocuments;
    int noTypes;
    int startDocument;
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
    // needed for estimation
    double * cachedCoefficients;
    bool isFinished;
    bool shouldSaveState;
    int smoothingOnlyMass;
};

#endif	/* PARALLELTOPICMODELWORKER_H */
