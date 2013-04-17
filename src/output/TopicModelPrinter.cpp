/**
 * @file TopicModelPrinter.cpp
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

#include "teflon/output/TopicModelPrinter.h"

using teflon::output::TopicModelPrinter;

TopicModelPrinter::TopicModelPrinter(TopicModel const * const topicModel, 
        Logger const * const logger) {
    TopicModelPrinter::topicModel = topicModel;
    TopicModelPrinter::logger = logger;
}

TopicModelPrinter::TopicModelPrinter(TopicModelPrinter const & orig) {
    topicModel = orig.getTopicModel();
    logger = orig.getLogger();
}

TopicModelPrinter::~TopicModelPrinter() {
}

Logger const * const TopicModelPrinter::getLogger() const {
    return logger;
}

TopicModel const * const TopicModelPrinter::getTopicModel() const {
    return topicModel;
}

void TopicModelPrinter::printDocumentTopTopics(int const & n) const {
    
}

void TopicModelPrinter::printDocumentTop5() const {
    
}

void TopicModelPrinter::printTopicTopWords(int const & n) const {
    
}

void TopicModelPrinter::printTopicTop10() const {
    
}

void TopicModelPrinter::printSingleDocumentTopics(int const & n, 
        int const & m) const {
    
}

void TopicModelPrinter::printSingleTopicWords(int const & n, 
        int const & k) const {
    
}
