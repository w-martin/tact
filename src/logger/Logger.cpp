/**
 * @file Logger.cpp
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
 * 
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <boost/date_time/posix_time/posix_time.hpp>
#include "teflon/logger/Logger.h"
#include "teflon/util/Files.h"
#include <ctime>
#include <iostream>
#include <sstream>

using std::endl;
using std::stringstream;

teflon::logger::Logger::Logger(const string name,
        bool const logToConsole, bool const logToFile) {
    Logger::name = name;
    Logger::logToConsole = logToConsole;
    Logger::logToFile = logToFile;
}

teflon::logger::Logger::Logger(Logger const & orig) {
    name = orig.getName();
    logToConsole = orig.isLogToConsoleEnabled();
    logToFile = orig.isLogToFileEnabled();
}

teflon::logger::Logger::~Logger() {
}

string const teflon::logger::Logger::getName() const {
    return name;
}

bool const teflon::logger::Logger::isLogToConsoleEnabled() const {
    return logToConsole;
}

bool const teflon::logger::Logger::isLogToFileEnabled() const {
    return logToFile;
}

string const teflon::logger::Logger::log(Level const & level,
        string const & message) const {
    stringstream stream;
    stream << teflon::logger::getCurrentTimeDate() << " - Level ";
    switch (level) {
        case ERROR:
        {
            stream << "ERROR" << endl;
            break;
        }
        case INFO:
        {
            stream << "INFO" << endl;
            break;
        }
        case SEVERE:
        {
            stream << "SEVERE" << endl;
            break;
        }
    }
    stream << "    " << message << endl;
    string const logMessage = stream.str();
    stream.str(string());

    if (logToConsole) {
        std::cout << logMessage << endl;
    }
    if (logToFile) {
        teflon::util::files::appendFile(logMessage, LOG_FILE_NAME);
    }
    return logMessage;
}

string const teflon::logger::getCurrentTimeDate() {
    return boost::posix_time::to_simple_string(
            boost::posix_time::microsec_clock::universal_time());
}
