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

#define DEFAULT_BETA 0.01

#include "tmte-cpp/main/model/Alphabet.h"
#include "tmte-cpp/main/model/Instance.h"
#include "tmte-cpp/main/util/exceptions/OutOfBoundsException.h"
#include <vector>

using std::vector;

/**
 * Represents a Topic Model.
 * 
 */
class TopicModel {
public:
    TopicModel(int const noIterations,
            int const noTopics);
    TopicModel(const TopicModel& orig);
    virtual ~TopicModel();
    /**
     * Gets the Alphabet.
     * 
     * @return the Alphabet.
     * 
     */
    virtual Alphabet const * const getAlphabet() const;
    /**
     * Gets the number of iterations of EM training to do.
     * 
     * @return the number of iterations of EM training to do.
     * 
     */
    int const getNoIterations() const;
    /**
     * Gets the number of Topics.
     * 
     * @return the number of Topics.
     * 
     */
    int const getNoTopics() const;
    /**
     * Adds the given Instances to this TopicModel.
     * 
     * @param instances the Instances to add to this TopicModel.
     * 
     */
    virtual void addInstances(vector<Instance*> const * const instances);
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
     * Estimates the topic model.
     * 
     */
    virtual void estimate();
private:
    int noIterations;
    int noTopics;
    double * alpha;
    double alphaSum;
    double beta;
    double betaSum;
};

#endif	/* TOPICMODEL_H */

