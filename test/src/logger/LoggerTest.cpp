/**
 * @file LoggerTest.cpp
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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/filesystem.hpp>
#include "gtest/gtest.h"
#include "mewt/logger/Logger.h"
#include "mewt/util/Files.h"
#include "mewt/util/Strings.h"

using namespace mewt::logger;

namespace {

    /**
     * Tests Logger.
     * 
     */
    class LoggerTest : public ::testing::Test {
    protected:

        LoggerTest() {
            name = "LoggerTest";
            logger = new Logger(name, false, true);
        }

        virtual ~LoggerTest() {
            delete logger;
            boost::filesystem::remove(LOG_FILE_NAME);
        }
        Logger * logger;
        string name;
    };

    /*
     * Tests whether the copy constructor work correctly.
     * 
     */
    TEST_F(LoggerTest, CopyConstructorTest) {
        Logger tmp(*logger);
        EXPECT_EQ(name, tmp.getName());
        EXPECT_FALSE(tmp.isLogToConsoleEnabled());
        EXPECT_TRUE(tmp.isLogToFileEnabled());

        tmp = Logger(name, true, false);
        tmp = Logger(tmp);
        EXPECT_TRUE(tmp.isLogToConsoleEnabled());
        EXPECT_FALSE(tmp.isLogToFileEnabled());
    }

    /*
     * Tests whether the getCurrentTimeDate method works correctly.
     * 
     */
    TEST_F(LoggerTest, GetCurrentTimeDateTest) {
        string time1 = getCurrentTimeDate();
        EXPECT_LT(0, time1.size());

        boost::this_thread::sleep(boost::posix_time::millisec(1));
        string time2 = getCurrentTimeDate();
        EXPECT_NE(time1, time2);
    }

    /*
     * Tests whether the isLogToConsoleEnabled method works correctly.
     * 
     */
    TEST_F(LoggerTest, IsLogToConsoleEnabledTest) {
        EXPECT_FALSE(logger->isLogToConsoleEnabled());

        EXPECT_TRUE(Logger(name, true, false).isLogToConsoleEnabled());
    }

    /*
     * Tests whether the isLogToFileEnabled method works correctly.
     * 
     */
    TEST_F(LoggerTest, IsLogToFileEnabledTest) {
        EXPECT_TRUE(logger->isLogToFileEnabled());

        EXPECT_FALSE(Logger(name, true, false).isLogToFileEnabled());
    }

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(LoggerTest, GetNameTest) {
        EXPECT_EQ(name, logger->getName());
    }

    /*
     * Tests whether the log method works correctly.
     * 
     */
    TEST_F(LoggerTest, LogTest) {
        boost::filesystem::remove(LOG_FILE_NAME);

        string message = logger->log(ERROR, "first message");
        EXPECT_LT(0, message.size());
        EXPECT_TRUE(mewt::util::strings::contains(message, "ERROR"));
        EXPECT_FALSE(mewt::util::strings::contains(message, "INFO"));
        EXPECT_FALSE(mewt::util::strings::contains(message, "SEVERE"));

        message = logger->log(INFO, "second message");
        EXPECT_LT(0, message.size());
        EXPECT_FALSE(mewt::util::strings::contains(message, "ERROR"));
        EXPECT_TRUE(mewt::util::strings::contains(message, "INFO"));
        EXPECT_FALSE(mewt::util::strings::contains(message, "SEVERE"));

        message = logger->log(SEVERE, "third message");
        EXPECT_LT(0, message.size());
        EXPECT_FALSE(mewt::util::strings::contains(message, "ERROR"));
        EXPECT_FALSE(mewt::util::strings::contains(message, "INFO"));
        EXPECT_TRUE(mewt::util::strings::contains(message, "SEVERE"));

        auto_ptr< string > file = mewt::util::files::readFile(LOG_FILE_NAME);
        EXPECT_LT(0, file->size());
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "ERROR"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "INFO"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "SEVERE"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "first"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "second"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "third"));
        EXPECT_TRUE(mewt::util::strings::contains(*file.get(), "message"));
        EXPECT_FALSE(mewt::util::strings::contains(*file.get(), "fourth"));
    }
}
