/**
 * @file TopicModelPrinterTest.cpp
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

#include "gtest/gtest.h"
#include "teflon/logger/MockLogger.h"
#include "teflon/model/MockTopicModel.h"
#include "teflon/output/TopicModelPrinter.h"

using teflon::output::TopicModelPrinter;
using ::testing::_;
using namespace teflon::logger;

namespace {

    /**
     * Tests TopicModelPrinter.
     * 
     */ 
    class TopicModelPrinterTest : public ::testing::Test {
    protected:

        TopicModelPrinterTest() {
            topicModel = new MockTopicModel();
            printer = new TopicModelPrinter(topicModel, &logger);
        }

        virtual ~TopicModelPrinterTest() {
            delete printer;
            delete topicModel;
        }
        TopicModelPrinter * printer;
        TopicModel * topicModel;
        MockLogger logger;
    };

    /*
     * Tests whether the copy constructor work correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, CopyConstructorTest) {
        TopicModelPrinter tmp(*printer);
        EXPECT_EQ(topicModel, tmp.getTopicModel());
        EXPECT_EQ(&logger, tmp.getLogger());
    }

    /*
     * Tests whether the logger getter works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, GetLoggerTest) {
        EXPECT_EQ(&logger, printer->getLogger());
    }

    /*
     * Tests whether the topic model getter works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, GetTopicModelTest) {
        EXPECT_EQ(topicModel, printer->getTopicModel());
    }

    /*
     * Tests whether the printDocumentTopTopics method works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, PrintDocumentTopTopicsTest) {
      int n = 2;
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoDocuments());
      printer->printDocumentTopTopics(n);
      
      n = 4;
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoDocuments());
      printer->printDocumentTopTopics(n);
    }

    /*
     * Tests whether the printDocumentTop5 method works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, PrintDocumentTop5Test) {
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoDocuments());
      printer->printDocumentTop5();
    }

    /*
     * Tests whether the printTopicTopWords method works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, PrintTopicTopWordsTest) {
      int n = 2;
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoTopics());
      printer->printTopicTopWords(n);
      
      n = 4;
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoTopics());
      printer->printTopicTopWords(n);
    }

    /*
     * Tests whether the printTopicTop10 method works correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, PrintTopicTop10Test) {
      EXPECT_CALL(logger, log(INFO, _)).Times(
              topicModel->getNoTopics());
      printer->printTopicTop10();
    }
}
