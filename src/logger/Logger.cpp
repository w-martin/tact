/**
 * @file Logger.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <boost/date_time/posix_time/posix_time.hpp>
#include "tact/logger/Logger.h"
#include "tact/util/Files.h"
#include <ctime>
#include <iostream>
#include <sstream>

using std::endl;
using std::stringstream;

tact::logger::Logger::Logger(const string name,
                               bool const logToConsole, bool const logToFile) {
  Logger::name = name;
  Logger::logToConsole = logToConsole;
  Logger::logToFile = logToFile;
}

tact::logger::Logger::Logger(Logger const & orig) {
  name = orig.getName();
  logToConsole = orig.isLogToConsoleEnabled();
  logToFile = orig.isLogToFileEnabled();
}

tact::logger::Logger::~Logger() {
}

string const tact::logger::Logger::getName() const {
  return name;
}

bool const tact::logger::Logger::isLogToConsoleEnabled() const {
  return logToConsole;
}

bool const tact::logger::Logger::isLogToFileEnabled() const {
  return logToFile;
}

string const tact::logger::Logger::log(Level const & level,
    string const & message) const {
  stringstream stream;
  stream << tact::logger::getCurrentTimeDate() << " - Level ";
  switch (level) {
  case ERROR: {
    stream << "ERROR" << endl;
    break;
  }
  case INFO: {
    stream << "INFO" << endl;
    break;
  }
  case SEVERE: {
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
    tact::util::files::appendFile(logMessage, LOG_FILE_NAME);
  }
  return logMessage;
}

string const tact::logger::getCurrentTimeDate() {
  return boost::posix_time::to_simple_string(
           boost::posix_time::microsec_clock::universal_time());
}
