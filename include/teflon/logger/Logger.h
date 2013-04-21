/**
 * @file Logger.h
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

#ifndef LOGGER_H
#define LOGGER_H

#define LOG_FILE_NAME "teflon.log"

#include <string>

using std::string;

namespace teflon {

namespace logger {

/**
 * Enumerates the severity of a message to be logged.
 *
 */
enum Level {
  INFO,
  ERROR,
  SEVERE
};

/**
 * Gets the current time and date in string format.
 *
 * @return the current time and date in string format.
 *
 */
string const getCurrentTimeDate();

/**
 * Logs information.
 *
 */
class Logger {
public:
  /**
   * Default constructor.
   *
   * @param name the name of the source class or name-space
   * creating this Logger.
   * @param logToConsole whether this Logger should log to the
   * console.
   * @param logToFile whether this Logger should log to a file.
   *
   */
  Logger(string const name, bool const logToConsole,
         bool const logToFile);
  /**
   * Copy constructor.
   *
   * @param orig the Logger to copy.
   *
   */
  Logger(Logger const & orig);
  /**
   * Default destructor.
   *
   */
  virtual ~Logger();
  /**
   * Gets the name of this Logger.
   *
   * @return the name of this Logger.
   *
   */
  string const getName() const;
  /**
   * Checks whether log to console is enabled.
   *
   * @return true if log to console is enabled, false otherwise.
   *
   */
  bool const isLogToConsoleEnabled() const;
  /**
   * Checks whether log to file is enabled.
   *
   * @return true if log to file is enabled, false otherwise.
   *
   */
  bool const isLogToFileEnabled() const;
  /**
   * Logs the given message with given severity Level.
   *
   * @param level the severity of the message to be logged.
   * @param message the message to log.
   * @return the logged message.
   *
   */
  virtual string const log(Level const & level, string const & message) const;
private:
  /**
   * Whether this Logger should log to console or not.
   *
   */
  bool logToConsole;
  /**
   * Whether this Logger should log to a file or not.
   *
   */
  bool logToFile;
  /**
   * The name of the source class or name-space creating this
   * Logger.
   *
   */
  string name;
};

};

};

#endif /* LOGGER_H */
