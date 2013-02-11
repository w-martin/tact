/**
 * @file TopicModel.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "teflon/model/TopicModel.h"

TopicModel::TopicModel(double const alpha, double const beta,
        auto_ptr<Corpus> corpus, int const noTopics)
throw (IncompatibleCorpusException) {
    if (DOCUMENT_TYPE_FEATURE == corpus->getDocumentsType()) {
        TopicModel::corpus = (FeatureCorpus *) corpus.release();
    } else {
        throw IncompatibleCorpusException(
                corpus->getDocumentsType(), DOCUMENT_TYPE_FEATURE,
                "TopicModel::TopicModel");
    }
    TopicModel::alpha = alpha;
    TopicModel::beta = beta;
    TopicModel::noIterationsCompleted = 0;
    TopicModel::noTopics = noTopics;
    TopicModel::termTopicMatrix = new ProbabilityMatrix(TopicModel::noTopics,
            TopicModel::corpus->getAlphabet()->getSize());
    TopicModel::topicDocumentMatrix = new ProbabilityMatrix(
            TopicModel::corpus->getSize(), TopicModel::noTopics);
}

TopicModel::~TopicModel() {
    delete corpus;
    delete termTopicMatrix;
    delete topicDocumentMatrix;
}

double const TopicModel::getAlpha() const {
    return alpha;
}

double const TopicModel::getBeta() const {
    return beta;
}

FeatureCorpus const * const TopicModel::getCorpus() const {
    return corpus;
}

int const TopicModel::getNoDocuments() const {
    return corpus->getSize();
}

int const TopicModel::getNoIterationsCompleted() const {
    return noIterationsCompleted;
}

int const TopicModel::getNoTopics() const {
    return noTopics;
}

ProbabilityMatrix const * const TopicModel::getTermTopicMatrix() const {
    return termTopicMatrix;
}

ProbabilityMatrix const * const TopicModel::getTopicDocumentMatrix() const {
    return topicDocumentMatrix;
}
