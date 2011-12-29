/**
 * @file ParallelTopicModelWorker.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#include <iostream>

#include "tmte-cpp/algorithm/ParallelTopicModelWorker.h"
#include "tmte-cpp/algorithm/ParallelTopicModel.h"
#include <assert.h>

using std::cout;

ParallelTopicModelWorker::ParallelTopicModelWorker(
        double * const alpha,
        double alphaSum,
        double beta,
        int const noDocuments,
        int const noTopics,
        int const noTypes,
        int const startDocument,
        int const * const tokensPerTopic,
        vector<TopicAssignment*> * topicAssignments,
        vector<vector<int> > const * const typeTopicCounts) {

    ParallelTopicModelWorker::alpha = alpha;
    ParallelTopicModelWorker::alphaSum = alphaSum;
    ParallelTopicModelWorker::beta = beta;
    ParallelTopicModelWorker::noDocuments = noDocuments;
    ParallelTopicModelWorker::noTopics = noTopics;
    ParallelTopicModelWorker::noTypes = noTypes;
    ParallelTopicModelWorker::startDocument = startDocument;
    copyTokensPerTopic(tokensPerTopic);
    copyTopicAssignments(topicAssignments);
    copyTypeTopicCounts(typeTopicCounts);

    betaSum = beta * noTypes;
    documentLengthCounts = new int[noDocuments];
    for (int i = 0; i < noDocuments; i++) {
        documentLengthCounts[i] = 0;
    }
    topicBits = 0;
    topicDocumentCounts = new int*[noTopics];
    for (int i = 0; i < noTopics; i++) {
        topicDocumentCounts[i] = new int[noDocuments];
        for (int j = 0; j < noDocuments; j++) {
            topicDocumentCounts[i][j] = 0;
        }
    }
    topicMask = 0;

    // needed for estimation
    cachedCoefficients = new double[noTopics];
    isFinished = false;
    shouldSaveState = false;
}

ParallelTopicModelWorker::ParallelTopicModelWorker(
        const ParallelTopicModelWorker& orig)
: TopicModel(orig) {
    noDocuments = orig.getNoDocuments();
    startDocument = orig.getStartDocument();
    copyTokensPerTopic(orig.getTokensPerTopic());
    copyTopicAssignments(orig.getTopicAssignments());
    copyTypeTopicCounts(orig.getTypeTopicCounts());

    noTypes = sizeof (typeTopicCounts) / sizeof (int*);
    int const * const originalDocumentLengthCounts =
            orig.getDocumentLengthCounts();
    documentLengthCounts = new int[noDocuments];
    for (int i = 0; i < noDocuments; i++) {
        documentLengthCounts[i] = originalDocumentLengthCounts[i];
    }
    topicBits = orig.getTopicBits();
    int const * const * const originalTopicDocumentCounts =
            orig.getTopicDocumentCounts();
    topicDocumentCounts = new int*[noTopics];
    for (int i = 0; i < noTopics; i++) {
        topicDocumentCounts[i] = new int[noDocuments];
        for (int j = 0; j < noDocuments; j++) {
            topicDocumentCounts[i][j] = originalTopicDocumentCounts[i][j];
        }
    }
    topicMask = orig.getTopicMask();

    // needed for estimation
    cachedCoefficients = new double[noTopics];
    isFinished = true;
    shouldSaveState = false;
}

ParallelTopicModelWorker::~ParallelTopicModelWorker() {
    delete [] documentLengthCounts;
    for (int i = 0; i < noTopics; i++) {
        delete [] topicDocumentCounts[i];
    }
    delete [] topicDocumentCounts;
    delete typeTopicCounts;
}

int const * const ParallelTopicModelWorker::getDocumentLengthCounts() const {
    return documentLengthCounts;
}

int const ParallelTopicModelWorker::getNoDocuments() const {
    return noDocuments;
}

int const ParallelTopicModelWorker::getStartDocument() const {
    return startDocument;
}

int const ParallelTopicModelWorker::getTopicBits() const {
    return topicBits;
}

int const * const * const ParallelTopicModelWorker::getTopicDocumentCounts()
const {
    return topicDocumentCounts;
}

int const ParallelTopicModelWorker::getTopicMask() const {
    return topicMask;
}

void ParallelTopicModelWorker::collectAlphaStatistics() {
    shouldSaveState = true;
}

void ParallelTopicModelWorker::run() {

    //    try {
    //
    //        if (!isFinished) {
    //            System.out.println("already running!");
    //            return;
    //        }
    if (!isFinished) {
        std::cout << "already running!";
        return;
    }

    //        isFinished = false;
    isFinished = false;

    //        // Initialize the smoothing-only sampling bucket
    //        smoothingOnlyMass = 0;
    smoothingOnlyMass = 0;

    //        // Initialize the cached coefficients, using only smoothing.
    //        //  These values will be selectively replaced in documents with
    //        //  non-zero counts in particular topics.
    //
    //        for (int topic = 0; topic < numTopics; topic++) {
    //            smoothingOnlyMass += alpha[topic] * beta / (tokensPerTopic[topic] + betaSum);
    //            cachedCoefficients[topic] = alpha[topic] / (tokensPerTopic[topic] + betaSum);
    //        }
    for (int topic = 0; topic < noTopics; topic++) {
        smoothingOnlyMass += alpha[topic] * beta /
                (tokensPerTopic[topic] + betaSum);
        cachedCoefficients[topic] = alpha[topic] /
                (tokensPerTopic[topic] + betaSum);
    }

    //        for (int doc = startDoc;
    //                doc < data.size() && doc < startDoc + numDocs;
    //                doc++) {
    //
    //            /*
    //            if (doc % 10000 == 0) {
    //            System.out.println("processing doc " + doc);
    //            }
    //             */
    //
    //            FeatureSequence tokenSequence =
    //                    (FeatureSequence) data.get(doc).instance.getData();
    //            LabelSequence topicSequence =
    //                    (LabelSequence) data.get(doc).topicSequence;
    //
    //            sampleTopicsForOneDoc(tokenSequence, topicSequence,
    //                    true);
    //        }
    for (int doc = startDocument;
            doc < noDocuments && doc < (startDocument + noDocuments);
            doc++) {
        FeatureVector * const tokenSequence =
                topicAssignments->at(doc)->getInstance()->getData();
        FeatureVector * const topicSequence =
                topicAssignments->at(doc)->getTopicSequence();
        sampleTopics(tokenSequence, topicSequence);
    }

    //        if (shouldBuildLocalCounts) {
    //            buildLocalTypeTopicCounts();
    //        }
    //
    //        shouldSaveState = false;
    //        isFinished = true;
    shouldSaveState = false;
    isFinished = true;

    //    } catch (Exception e) {
    //        e.printStackTrace();
    //    }
}

void ParallelTopicModelWorker::sampleTopics(
        FeatureVector * const tokenSequence,
        FeatureVector * const topicSequence) {
    //		int[] oneDocTopics = topicSequence.getFeatures();
    vector<int> const * const oneDocTopics = topicSequence->getFeatures();

    //		int[] currentTypeTopicCounts;
    //		int type, oldTopic, newTopic;
    //		double topicWeightsSum;
    //		int docLength = tokenSequence.getLength();
    vector<int> currentTypeTopicCounts;
    int type;
    int oldTopic;
    int newTopic;
    double topicWeightsSum;
    int documentLength = tokenSequence->getSize();

    //		int[] localTopicCounts = new int[numTopics];
    //		int[] localTopicIndex = new int[numTopics];
    int * localTopicCounts = new int[noTopics];
    int * localTopicIndex = new int[noTopics];

    //		//		populate topic counts
    //		for (int position = 0; position < docLength; position++) {
    //			if (oneDocTopics[position] == ParallelTopicModel.UNASSIGNED_TOPIC) { continue; }
    //			localTopicCounts[oneDocTopics[position]]++;
    //		}
    for (int position = 0; position < documentLength; position++) {
        if (oneDocTopics->at(position) == UNASSIGNED_TOPIC) {
            continue;
        } else {
            localTopicCounts[oneDocTopics->at(position)]++;
        }
    }

    //		// Build an array that densely lists the topics that
    //		//  have non-zero counts.
    //		int denseIndex = 0;
    //		for (int topic = 0; topic < numTopics; topic++) {
    //			if (localTopicCounts[topic] != 0) {
    //				localTopicIndex[denseIndex] = topic;
    //				denseIndex++;
    //			}
    //		}
    int denseIndex = 0;
    for (int topic = 0; topic < noTopics; topic++) {
        if (0 != localTopicCounts[topic]) {
            localTopicIndex[denseIndex] = topic;
            denseIndex++;
        }
    }

    //		// Record the total number of non-zero topics
    //		int nonZeroTopics = denseIndex;
    int nonZeroTopics = denseIndex;

    //		//		Initialize the topic count/beta sampling bucket
    //		double topicBetaMass = 0.0;
    double topicBetaMass = 0.0;

    //		// Initialize cached coefficients and the topic/beta 
    //		//  normalizing constant.
    //		for (denseIndex = 0; denseIndex < nonZeroTopics; denseIndex++) {
    //			int topic = localTopicIndex[denseIndex];
    //			int n = localTopicCounts[topic];
    //
    //			//	initialize the normalization constant for the (B * n_{t|d}) term
    //			topicBetaMass += beta * n /	(tokensPerTopic[topic] + betaSum);	
    //
    //			//	update the coefficients for the non-zero topics
    //			cachedCoefficients[topic] =	(alpha[topic] + n) / (tokensPerTopic[topic] + betaSum);
    //		}
    for (denseIndex = 0; denseIndex < nonZeroTopics; denseIndex++) {
        int topic = localTopicIndex[denseIndex];
        int n = localTopicCounts[topic];
        topicBetaMass += (beta * n) / (tokensPerTopic[topic] + betaSum);
        cachedCoefficients[topic] =
                (alpha[topic] + n) / (tokensPerTopic[topic] + betaSum);
    }

    //		double topicTermMass = 0.0;
    //		double[] topicTermScores = new double[numTopics];
    //		int[] topicTermIndices;
    //		int[] topicTermValues;
    //		int i;
    //		double score;
    double topicTermMass = 0.0;
    double * topicTermScores = new double[noTopics];
    int * topicTermIndices;
    int * topicTermValues;
    int i;
    double score;

    //		//	Iterate over the positions (words) in the document 
    //		for (int position = 0; position < docLength; position++) {
    //			type = tokenSequence.getIndexAtPosition(position);
    //			oldTopic = oneDocTopics[position];
    for (int position = 0; position < documentLength; position++) {
        type = tokenSequence->getFeatures()->at(position);
        oldTopic = oneDocTopics->at(position);

        //			currentTypeTopicCounts = typeTopicCounts[type];
        currentTypeTopicCounts = typeTopicCounts->at(type);

        //			if (oldTopic != ParallelTopicModel.UNASSIGNED_TOPIC) {
        //				//	Remove this token from all counts. 
        if (oldTopic != UNASSIGNED_TOPIC) {

            //				// Remove this topic's contribution to the 
            //				//  normalizing constants
            //				smoothingOnlyMass -= alpha[oldTopic] * beta / 
            //					(tokensPerTopic[oldTopic] + betaSum);
            //				topicBetaMass -= beta * localTopicCounts[oldTopic] /
            //					(tokensPerTopic[oldTopic] + betaSum);
            smoothingOnlyMass -= (alpha[oldTopic] * beta)
                    / (tokensPerTopic[oldTopic] + betaSum);
            topicBetaMass -= (beta * localTopicCounts[oldTopic])
                    / (tokensPerTopic[oldTopic] + betaSum);

            //				// Decrement the local doc/topic counts
            //				localTopicCounts[oldTopic]--;
            localTopicCounts[oldTopic]--;

            //				// Maintain the dense index, if we are deleting
            //				//  the old topic
            //				if (localTopicCounts[oldTopic] == 0) {
            if (0 == localTopicCounts[oldTopic]) {

                //					// First get to the dense location associated with
                //					//  the old topic.
                //					
                //					denseIndex = 0;
                denseIndex = 0;

                //					// We know it's in there somewhere, so we don't 
                //					//  need bounds checking.
                //					while (localTopicIndex[denseIndex] != oldTopic) {
                //						denseIndex++;
                //					}
                while (localTopicIndex[denseIndex] != oldTopic) {
                    denseIndex++;
                }

                //					// shift all remaining dense indices to the left.
                //					while (denseIndex < nonZeroTopics) {
                //						if (denseIndex < localTopicIndex.length - 1) {
                //							localTopicIndex[denseIndex] = 
                //								localTopicIndex[denseIndex + 1];
                //						}
                //						denseIndex++;
                //					}
                //					nonZeroTopics --;
                //				}
                while (denseIndex < nonZeroTopics) {
                    if (denseIndex < noTopics - 1) {
                        localTopicIndex[denseIndex] =
                                localTopicIndex[denseIndex + 1];
                    }
                    denseIndex++;
                }
                nonZeroTopics--;
            }

            //				// Decrement the global topic count totals
            //				tokensPerTopic[oldTopic]--;
            //				assert(tokensPerTopic[oldTopic] >= 0) : "old Topic " + oldTopic + " below 0";
            tokensPerTopic[oldTopic]--;
            if (0 <= tokensPerTopic[oldTopic]) {
                cout << "old Topic " << oldTopic << " below 0";
                assert(0 <= tokensPerTopic[oldTopic]);
            }

            //				// Add the old topic's contribution back into the
            //				//  normalizing constants.
            //				smoothingOnlyMass += alpha[oldTopic] * beta / 
            //					(tokensPerTopic[oldTopic] + betaSum);
            //				topicBetaMass += beta * localTopicCounts[oldTopic] /
            //					(tokensPerTopic[oldTopic] + betaSum);
            smoothingOnlyMass += (alpha[oldTopic] * beta) /
                    (tokensPerTopic[oldTopic] + betaSum);
            topicBetaMass += (beta * localTopicCounts[oldTopic]) /
                    (tokensPerTopic[oldTopic] + betaSum);

            //				// Reset the cached coefficient for this topic
            //				cachedCoefficients[oldTopic] = 
            //					(alpha[oldTopic] + localTopicCounts[oldTopic]) /
            //					(tokensPerTopic[oldTopic] + betaSum);
            //			}
            cachedCoefficients[oldTopic] =
                    (alpha[oldTopic] + localTopicCounts[oldTopic]) /
                    (tokensPerTopic[oldTopic] + betaSum);
        }

        //
        //
        //			// Now go over the type/topic counts, decrementing
        //			//  where appropriate, and calculating the score
        //			//  for each topic at the same time.
        //
        //			int index = 0;
        //			int currentTopic, currentValue;
        //
        //			boolean alreadyDecremented = (oldTopic == ParallelTopicModel.UNASSIGNED_TOPIC);
        //
        //			topicTermMass = 0.0;
        //
        //			while (index < currentTypeTopicCounts.length && 
        //				   currentTypeTopicCounts[index] > 0) {
        //				currentTopic = currentTypeTopicCounts[index] & topicMask;
        //				currentValue = currentTypeTopicCounts[index] >> topicBits;
        //
        //				if (! alreadyDecremented && 
        //					currentTopic == oldTopic) {
        //
        //					// We're decrementing and adding up the 
        //					//  sampling weights at the same time, but
        //					//  decrementing may require us to reorder
        //					//  the topics, so after we're done here,
        //					//  look at this cell in the array again.
        //
        //					currentValue --;
        //					if (currentValue == 0) {
        //						currentTypeTopicCounts[index] = 0;
        //					}
        //					else {
        //						currentTypeTopicCounts[index] =
        //							(currentValue << topicBits) + oldTopic;
        //					}
        //					
        //					// Shift the reduced value to the right, if necessary.
        //
        //					int subIndex = index;
        //					while (subIndex < currentTypeTopicCounts.length - 1 && 
        //						   currentTypeTopicCounts[subIndex] < currentTypeTopicCounts[subIndex + 1]) {
        //						int temp = currentTypeTopicCounts[subIndex];
        //						currentTypeTopicCounts[subIndex] = currentTypeTopicCounts[subIndex + 1];
        //						currentTypeTopicCounts[subIndex + 1] = temp;
        //						
        //						subIndex++;
        //					}
        //
        //					alreadyDecremented = true;
        //				}
        //				else {
        //					score = 
        //						cachedCoefficients[currentTopic] * currentValue;
        //					topicTermMass += score;
        //					topicTermScores[index] = score;
        //
        //					index++;
        //				}
        //			}
        //			
        //			double sample = random.nextUniform() * (smoothingOnlyMass + topicBetaMass + topicTermMass);
        //			double origSample = sample;
        //
        //			//	Make sure it actually gets set
        //			newTopic = -1;
        //
        //			if (sample < topicTermMass) {
        //				//topicTermCount++;
        //
        //				i = -1;
        //				while (sample > 0) {
        //					i++;
        //					sample -= topicTermScores[i];
        //				}
        //
        //				newTopic = currentTypeTopicCounts[i] & topicMask;
        //				currentValue = currentTypeTopicCounts[i] >> topicBits;
        //				
        //				currentTypeTopicCounts[i] = ((currentValue + 1) << topicBits) + newTopic;
        //
        //				// Bubble the new value up, if necessary
        //				
        //				while (i > 0 &&
        //					   currentTypeTopicCounts[i] > currentTypeTopicCounts[i - 1]) {
        //					int temp = currentTypeTopicCounts[i];
        //					currentTypeTopicCounts[i] = currentTypeTopicCounts[i - 1];
        //					currentTypeTopicCounts[i - 1] = temp;
        //
        //					i--;
        //				}
        //
        //			}
        //			else {
        //				sample -= topicTermMass;
        //
        //				if (sample < topicBetaMass) {
        //					//betaTopicCount++;
        //
        //					sample /= beta;
        //
        //					for (denseIndex = 0; denseIndex < nonZeroTopics; denseIndex++) {
        //						int topic = localTopicIndex[denseIndex];
        //
        //						sample -= localTopicCounts[topic] /
        //							(tokensPerTopic[topic] + betaSum);
        //
        //						if (sample <= 0.0) {
        //							newTopic = topic;
        //							break;
        //						}
        //					}
        //
        //				}
        //				else {
        //					//smoothingOnlyCount++;
        //
        //					sample -= topicBetaMass;
        //
        //					sample /= beta;
        //
        //					newTopic = 0;
        //					sample -= alpha[newTopic] /
        //						(tokensPerTopic[newTopic] + betaSum);
        //
        //					while (sample > 0.0) {
        //						newTopic++;
        //						sample -= alpha[newTopic] / 
        //							(tokensPerTopic[newTopic] + betaSum);
        //					}
        //					
        //				}
        //
        //				// Move to the position for the new topic,
        //				//  which may be the first empty position if this
        //				//  is a new topic for this word.
        //				
        //				index = 0;
        //				while (currentTypeTopicCounts[index] > 0 &&
        //					   (currentTypeTopicCounts[index] & topicMask) != newTopic) {
        //					index++;
        //					if (index == currentTypeTopicCounts.length) {
        //						System.err.println("type: " + type + " new topic: " + newTopic);
        //						for (int k=0; k<currentTypeTopicCounts.length; k++) {
        //							System.err.print((currentTypeTopicCounts[k] & topicMask) + ":" + 
        //											 (currentTypeTopicCounts[k] >> topicBits) + " ");
        //						}
        //						System.err.println();
        //
        //					}
        //				}
        //
        //
        //				// index should now be set to the position of the new topic,
        //				//  which may be an empty cell at the end of the list.
        //
        //				if (currentTypeTopicCounts[index] == 0) {
        //					// inserting a new topic, guaranteed to be in
        //					//  order w.r.t. count, if not topic.
        //					currentTypeTopicCounts[index] = (1 << topicBits) + newTopic;
        //				}
        //				else {
        //					currentValue = currentTypeTopicCounts[index] >> topicBits;
        //					currentTypeTopicCounts[index] = ((currentValue + 1) << topicBits) + newTopic;
        //
        //					// Bubble the increased value left, if necessary
        //					while (index > 0 &&
        //						   currentTypeTopicCounts[index] > currentTypeTopicCounts[index - 1]) {
        //						int temp = currentTypeTopicCounts[index];
        //						currentTypeTopicCounts[index] = currentTypeTopicCounts[index - 1];
        //						currentTypeTopicCounts[index - 1] = temp;
        //
        //						index--;
        //					}
        //				}
        //
        //			}
        //
        //			if (newTopic == -1) {
        //				System.err.println("WorkerRunnable sampling error: "+ origSample + " " + sample + " " + smoothingOnlyMass + " " + 
        //						topicBetaMass + " " + topicTermMass);
        //				newTopic = numTopics-1; // TODO is this appropriate
        //				//throw new IllegalStateException ("WorkerRunnable: New topic not sampled.");
        //			}
        //			//assert(newTopic != -1);
        //
        //			//			Put that new topic into the counts
        //			oneDocTopics[position] = newTopic;
        //
        //			smoothingOnlyMass -= alpha[newTopic] * beta / 
        //				(tokensPerTopic[newTopic] + betaSum);
        //			topicBetaMass -= beta * localTopicCounts[newTopic] /
        //				(tokensPerTopic[newTopic] + betaSum);
        //
        //			localTopicCounts[newTopic]++;
        //
        //			// If this is a new topic for this document,
        //			//  add the topic to the dense index.
        //			if (localTopicCounts[newTopic] == 1) {
        //				
        //				// First find the point where we 
        //				//  should insert the new topic by going to
        //				//  the end (which is the only reason we're keeping
        //				//  track of the number of non-zero
        //				//  topics) and working backwards
        //
        //				denseIndex = nonZeroTopics;
        //
        //				while (denseIndex > 0 &&
        //					   localTopicIndex[denseIndex - 1] > newTopic) {
        //
        //					localTopicIndex[denseIndex] =
        //						localTopicIndex[denseIndex - 1];
        //					denseIndex--;
        //				}
        //				
        //				localTopicIndex[denseIndex] = newTopic;
        //				nonZeroTopics++;
        //			}
        //
        //			tokensPerTopic[newTopic]++;
        //
        //			//	update the coefficients for the non-zero topics
        //			cachedCoefficients[newTopic] =
        //				(alpha[newTopic] + localTopicCounts[newTopic]) /
        //				(tokensPerTopic[newTopic] + betaSum);
        //
        //			smoothingOnlyMass += alpha[newTopic] * beta / 
        //				(tokensPerTopic[newTopic] + betaSum);
        //			topicBetaMass += beta * localTopicCounts[newTopic] /
        //				(tokensPerTopic[newTopic] + betaSum);
        //
        //		}
    }

    //		if (shouldSaveState) {
    //			// Update the document-topic count histogram,
    //			//  for dirichlet estimation
    //			docLengthCounts[ docLength ]++;
    //
    //			for (denseIndex = 0; denseIndex < nonZeroTopics; denseIndex++) {
    //				int topic = localTopicIndex[denseIndex];
    //				
    //				topicDocCounts[topic][ localTopicCounts[topic] ]++;
    //			}
    //		}
    //
    //		//	Clean up our mess: reset the coefficients to values with only
    //		//	smoothing. The next doc will update its own non-zero topics...
    //
    //		for (denseIndex = 0; denseIndex < nonZeroTopics; denseIndex++) {
    //			int topic = localTopicIndex[denseIndex];
    //
    //			cachedCoefficients[topic] =
    //				alpha[topic] / (tokensPerTopic[topic] + betaSum);
    //		}

    delete localTopicCounts;
    delete localTopicIndex;
}
