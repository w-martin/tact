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

namespace {

    /**
     * Tests TopicModelPrinter.
     * 
     */ 
    class TopicModelPrinterTest : public ::testing::Test {
    protected:

        TopicModelPrinterTest() {
            topicModel = new MockTopicModel();
            logger = new MockLogger();
            topicmodelprinter = new TopicModelPrinter(topicModel, logger);
        }

        virtual ~TopicModelPrinterTest() {
            delete topicmodelprinter;
        }
        TopicModelPrinter * topicmodelprinter;
        TopicModel * topicModel;
        Logger * logger;
    };

    /*
     * Tests whether the copy constructor work correctly.
     * 
     */
    TEST_F(TopicModelPrinterTest, CopyConstructorTest) {
        TopicModelPrinter tmp(*topicmodelprinter);
        EXPECT_EQ(topicModel, tmp.getTopicModel());
        EXPECT_EQ(logger, tmp.getLogger());
    }
}
