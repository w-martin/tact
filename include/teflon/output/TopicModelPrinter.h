/**
 * @file TopicModelPrinter.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 *
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#ifndef TOPICMODELPRINTER_H
#define TOPICMODELPRINTER_H

#include "teflon/logger/Logger.h"
#include "teflon/model/TopicModel.h"

using teflon::logger::Logger;

namespace teflon {
    namespace output {

        /**
         * Prints status information about a TopicModel.
         */
        class TopicModelPrinter {
        public:
            /**
             * Default constructor.
             * 
             * @param topicModel the TopicModel to print information about.
             * @param logger the Logger to use.
             */
            TopicModelPrinter(TopicModel const * const topicModel,
                    Logger const * const logger);
            /**
             * Copy constructor.
             * 
             * @param orig the TopicModelPrinter to copy.
             */
            TopicModelPrinter(TopicModelPrinter const & orig);
            /**
             * Default destructor.
             */
            virtual ~TopicModelPrinter();
            /**
             * Gets the Logger.
             * 
             * @return the Logger.
             */
            Logger const * const getLogger() const;
            /**
             * Gets the TopicModel.
             * 
             * @return the TopicModel.
             */
            TopicModel const * const getTopicModel() const;
            /**
             * Prints the top topics for all documents.
             * 
             * @param n the number of top topics to print.
             */
            void printDocumentTopTopics(int const & n) const;
            /**
             * Prints the top 5 topics for all documents.
             */
            void printDocumentTop5() const;
            /**
             * Prints the top words for all topics.
             * 
             * @param n the number of top words to print.
             */
            void printTopicTopWords(int const & n) const;
            /**
             * Prints the top 10 words for all topics.
             */
            void printTopicTop10() const;
        private:
            /**
             * Prints the top topics for a single document.
             * 
             * @param n the number of top topics to print.
             * @param m the identifier for the document to print.
             */
            void printSingleDocumentTopics(int const & n, int const & m) const;
            /**
             * Prints the top words for a single topic.
             * 
             * @param n the number of top words to print.
             * @param k the identifier for the topic to print.
             */
            void printSingleTopicWords(int const & n, int const & k) const;
            /**
             * The TopicModel to print information about.
             */
            TopicModel const * topicModel;
            /**
             * The Logger to use.
             */
            Logger const * logger;
        };

    }
}

#endif /* TOPICMODELPRINTER_H */
