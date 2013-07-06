/**
 * @file TopicModel.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Represents an abstract Topic Model.
 * <br> Call estimate() to run the model on the given corpus.
 *
 */

#ifndef TOPICMODEL_H
#define	TOPICMODEL_H

#define ALPHA_NUMERATOR_DEFAULT 50
#define BETA_DEFAULT 0.1
#define NO_ITERATIONS_DEFAULT 2000
#define NO_TOPICS_DEFAULT 100
#define SAVE_INTERVAL_DEFAULT 100

#include "tact/input/corpus/feature/FeatureCorpus.h"
#include "tact/input/exceptions/IncompatibleCorpusException.h"
#include "tact/model/ProbabilityMatrix.h"
#include "tact/util/exceptions/OutOfBoundsException.h"
#include <memory>
#include <vector>

using std::auto_ptr;
using std::vector;

class TopicModel {
public:
  /**
   * Default constructor.
   *
   * @param alpha the dirichlet parameter for each topic.
   * Dirichlet(alpha,alpha,...) is the distribution over topics.
   * @param beta the prior on the per-topic multinomial distribution
   * over words.
   * @param corpus the Corpus that this model will run on.
   * @param noTopics the number of topics that this TopicModel should have.
   * @throw IncompatibleCorpusException if the given Corpus was not of
   * a compatible type. The default required type is FeatureCorpus.
   *
   */
  TopicModel(double const alpha, double const beta,
             auto_ptr< Corpus > corpus, int const noTopics)
  throw (IncompatibleCorpusException);
  /**
   * Default destructor.
   *
   */
  virtual ~TopicModel();
  /**
   * Estimates this TopicModel, saving the results every <interval>
   * iterations.
   *
   * @param noIterations the number of iterations to estimate over.
   * @param outputDirectory the directory to save results to.
   * @param saveInterval saves the results every <interval> iterations.
   *
   */
  virtual void estimate(int const & noIterations,
                        string const & outputDirectory, int const & saveInterval) = 0;
  /**
   * Gets the array of alpha values.
   *
   * @return the array of alpha values.
   *
   */
  double const getAlpha() const;
  /**
   * Gets the beta value.
   *
   * @return the beta value.
   *
   */
  double const getBeta() const;
  /**
   * Gets the Corpus that this TopicModel runs on.
   *
   * @return the Corpus that this TopicModel runs on.
   *
   */
  FeatureCorpus const * const getCorpus() const;
  /**
   * Gets the number of documents in this Topic Model.
   *
   * @return  the number of documents in this Topic Model.
   *
   */
  int const getNoDocuments() const;
  /**
   * Gets the number of iterations that have been completed.
   *
   * @return the number of iterations that have been completed.
   *
   */
  int const getNoIterationsCompleted() const;
  /**
   * Gets the number of Topics.
   *
   * @return the number of Topics.
   *
   */
  int const getNoTopics() const;
  /**
   * Gets the term-topic probability matrix, indexed by [topic][term].
   *
   * @return the term-topic probability matrix.
   *
   */
  ProbabilityMatrix const * const getTermTopicMatrix() const;
  /**
   * Gets the topic-document probability matrix, indexed by
   * [document][topic].
   *
   * @return the topic-document probability matrix.
   *
   */
  ProbabilityMatrix const * const getTopicDocumentMatrix() const;
protected:
  /**
   * Dirichlet(alpha,alpha,...) is the distribution over topics.
   *
   */
  double alpha;
  /**
   * Prior on per-topic multinomial distribution over words.
   *
   */
  double beta;
  /**
   * The corpus that this model runs on.
   *
   */
  FeatureCorpus * corpus;
  /**
   * The number of iterations that have been completed.
   *
   */
  int noIterationsCompleted;
  /**
   * The number of Topics to train over.
   *
   */
  int noTopics;
  /**
   * Term-Topic probability matrix.
   * Indexed by [topic][term].
   *
   */
  ProbabilityMatrix * termTopicMatrix;
  /**
   * Topic-Document probability matrix.
   * Indexed by [document][topic].
   *
   */
  ProbabilityMatrix * topicDocumentMatrix;
};

#endif	/* TOPICMODEL_H */
