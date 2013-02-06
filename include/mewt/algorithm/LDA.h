/**
 * @file LDA.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef LDA_H
#define LDA_H

#include "mewt/algorithm/RandomNumberGenerator.h"
#include "mewt/model/TopicModel.h"

namespace mewt {

    namespace algorithm {

        /**
         * Basic Latent Dirichlet Allocation algorithm using Gibbs sampling.
         * 
         */
        class LDA : public TopicModel {
        public:
            /**
             * Default constructor.
             * 
             * @param alpha the Dirichlet parameter for each topic. 
             * Dirichlet(alpha,alpha,...) is the distribution over topics.
             * @param beta the prior on the per-topic multinomial distribution 
             * over words.
             * @param corpus the Corpus that this model will run on.
             * @param noTopics the number of topics that this TopicModel 
             * should have.
             * @throw IncompatibleCorpusException if the given Corpus was not 
             * of a compatible type. The default required type is FeatureCorpus.
             * 
             */
            LDA(double const alpha, double const beta,
                    auto_ptr< Corpus > corpus, int const noTopics)
            throw (IncompatibleCorpusException);
            /**
             * Default destructor.
             * 
             */
            virtual ~LDA();
            /**
             * Estimates this TopicModel, saving the results every <interval> 
             * iterations.
             * 
             * @param noIterations the number of iterations to estimate over.
             * @param outputDirectory the directory to save results to.
             * @param saveInterval saves the results every <interval> 
             * iterations.
             * 
             */
            virtual void estimate(int const & noIterations,
                    string const & outputDirectory, int const & saveInterval);
        protected:
            /**
             * Random number generator.
             * 
             */
            RandomNumberGenerator * random;
            /**
             * The number of topics. Stored again as K for convenience.
             * 
             */
            int K, Kalpha;
            /**
             * The number of documents in the training Corpus.
             * 
             */
            int M;
            /**
             * The size of the Alphabet.
             * 
             */
            int V, Vbeta;
            /**
             * Variable for sampling.
             * 
             */
            double * p;
            /**
             * Topic assignments for terms, size M x doc.size().
             * 
             */
            int ** z;
            /**
             * nw[i][j]: number of instances of term j assigned to topic i, 
             * size K x V
             * 
             */
            int ** Nwz;
            /**
             * nd[i][j]: number of terms in document i assigned to topic j, 
             * size M x K
             * 
             */
            int ** Nzd;
            /**
             * Nwzsums[i]: total number of terms assigned to topic i, size K
             * 
             */
            int * Nwzsums;
            /**
             * Nwdsums[i]: total number of terms in document i, size M
             * 
             */
            int * Nwdsums;
            /**
             * Computes phi, the termTopic probability matrix.
             * 
             */
            void computePhi();
            /**
             * Computes theta, the topicDocument probability matrix.
             * 
             */
            void computeTheta();
            /**
             * Logs the current state of this TopicModel.
             * 
             * @param noIterationsToGo the number of iterations yet to go.
             * 
             */
            void log(int const & noIterationsToGo) const;
            /**
             * Samples the Topics for the Document with the given FeatureMap and
             * document number.
             * 
             * @param featureMap the FeatureMap corresponding to the given 
             * Document.
             * @param docNo the document number corresponding to the given 
             * Document.
             * 
             */
            virtual void sampleTopics(FeatureMap const * const featureMap,
                    int const & docNo);
        };

    };

};

#endif /* LDA_H */
