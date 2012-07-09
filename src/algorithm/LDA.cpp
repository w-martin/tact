/**
 * @file LDA.cpp
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

#include "mewt/algorithm/LDA.h"

LDA::LDA(double const alpha, double const beta,
        auto_ptr< Corpus > corpus, int const noTopics)
throw (IncompatibleCorpusException)
: TopicModel(alpha, beta, corpus, noTopics) {
    K = noTopics;
    Kalpha = K * alpha;
    V = TopicModel::corpus->getAlphabet()->getSize();
    Vbeta = V * beta;
    M = TopicModel::corpus->getSize();

    random = new RandomNumberGenerator();
    p = new double[K];
    Nwz = new int*[K];
    Nwzsums = new int[K];
    for (int i = 0; i < K; i++) {
        Nwz[i] = new int[V];
        for (int j = 0; j < V; j++) {
            Nwz[i][j] = 0;
        }
        Nwzsums[i] = 0;
    }
    Nzd = new int*[M];
    Nwdsums = new int[M];
    for (int i = 0; i < M; i++) {
        Nzd[i] = new int[K];
        for (int j = 0; j < K; j++) {
            Nzd[i][j] = 0;
        }
    }

    z = new int*[M];
    vector< Document * > const * const documents =
            TopicModel::corpus->getDocuments();
    TopicModel::corpus->squash();
    FeatureMap const * featureMap;
    for (int i = 0; i < M; i++) {
        featureMap = ((FeatureDocument *) documents->at(i))->getFeatureMap();
        int const N = featureMap->getSize();
        z[i] = new int[N];
        int j = 0;

        for (FeatureMapIterator iter = featureMap->begin();
                featureMap->end() != iter; iter++) {
            int const term = iter.getFeature();
            for (int n = j + iter.getCount(); j < n; j++) {
                // assign random Topic for term j in document i
                int const topic = (int) (random->nextUniform() * K);
                z[i][j] = topic;
                Nwz[topic][term] += 1;
                Nzd[i][topic] += 1;
                Nwzsums[topic] += 1;
            }
        }
        Nwdsums[i] = N;
    }
}

LDA::~LDA() {
    delete random;
    delete [] p;
    for (int i = 0; i < K; i++) {
        delete [] Nwz[i];
    }
    delete [] Nwz;
    delete [] Nwzsums;
    for (int i = 0; i < M; i++) {
        delete [] Nzd[i];
        delete [] z[i];
    }
    delete [] Nzd;
    delete [] z;
    delete [] Nwdsums;
}

void LDA::estimate(int const & noIterations, string const & outputDirectory,
        int const & saveInterval) {
    vector< Document * > const * const documents = corpus->getDocuments();
    for (int i = 0; i < noIterations; i++) {

        // for all $d \in D$ do
        for (int docNo = 0; docNo < M; docNo++) {
            FeatureMap const * const featureMap =
                    ((FeatureDocument *) documents->at(docNo))->getFeatureMap();
            sampleTopics(featureMap, docNo);
        }
        noIterationsCompleted++;

        if (0.0 == ((double) i / saveInterval)) {
            computeTheta();
            computePhi();
            log();
        }
    }
    computeTheta();
    computePhi();
    log();
}

void LDA::sampleTopics(FeatureMap const * const featureMap,
        int const & docNo) {
    int const N = featureMap->getSize();
    int const i = docNo;
    int j = 0;

    // for all $w_n \in w^{(d)}$ do
    for (FeatureMapIterator iter = featureMap->begin();
            featureMap->end() != iter; iter++) {
        int const term = iter.getFeature();
        for (int n = j + iter.getCount(); j < n; j++) {
            int topic = z[i][j];

            // $N_{z_i | d_i} \leftarrow N_{z_i | d_i} - 1$
            Nzd[i][topic] -= 1;
            Nwdsums[i] -= 1;
            // $N_{w_i | z_i} \leftarrow N_{w_i | z_i} - 1$
            Nwz[topic][term] -= 1;
            Nwzsums[topic] -= 1;

            /* $z_i \prop (N_{z | d_i} + \alpha_z)\frac{N_{w_i | z} 
            + \beta}{\sum_{z^'}(N_{w_i | z^'} + \beta)}$ */

            int k;
            for (k = 0; k < K; k++) {
                double const lhs =
                        (Nzd[i][k] + alpha);
                double const rhs =
                        (Nwz[k][term] + beta)
                        / (Nwzsums[k] + Vbeta);
                p[k] = lhs * rhs;
            }
            // cumulative method
            for (k = 1; k < K; k++) {
                p[k] += p[k - 1];
            }
            // sample
            double const u = random->nextUniform() * p[K - 1];
            for (k = 0; k < K; k++) {
                if (p[k] > u) {
                    topic = k;
                    break;
                }
            }

            // $N_{z_i | d_i} \leftarrow N_{z_i | d_i} + 1$
            Nzd[i][topic] += 1;
            Nwdsums[i] += 1;
            // $N_{w_i | z_i} \leftarrow N_{w_i | z_i} + 1$
            Nwz[topic][term] += 1;
            Nwzsums[topic] += 1;
        }
    }
}

void LDA::computePhi() {
    for (int k = 0; k < K; k++) {
        for (int w = 0; w < V; w++) {
            double const result =
                    (Nwz[k][w] + beta)
                    / (Nwzsums[k] + Vbeta);
            termTopicMatrix->setElement(k, w, result);
        }
    }
}

void LDA::computeTheta() {
    for (int m = 0; m < M; m++) {
        for (int k = 0; k < K; k++) {
            double const result =
                    (Nzd[m][k] + alpha)
                    / (Nwdsums[m] + Kalpha);
            topicDocumentMatrix->setElement(m, k, result);
        }
    }
}

void LDA::log() const {

}
