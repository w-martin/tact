/**
 * @file FileNotFoundException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#define FILE_NOT_FOUND_MESSAGE "Error. File not found."

#include "teflon/util/exceptions/Exception.h"

/**
 * Exception class which indicates that a file was not found.
 *
 */
class FileNotFoundException : public Exception {
public:
  /**
   * Default constructor. Uses the default message for this Exception.
   *
   */
  FileNotFoundException();
  /**
   * Specific constructor. Generated an informative message
   * about the error.
   *
   * @param fileName the name of the file, or a message.
   * @param isMessage indicates whether the gien string is a message or the
   * name of the file that was not found.
   *
   */
  FileNotFoundException(string const & fileName, bool const & isMessage);
  /**
   * Uses the given message for this Exception.
   *
   * @param message the message to use for this Exception.
   *
   */
  FileNotFoundException(string const & message);
  /**
   * Default destructor.
   *
   */
  virtual ~FileNotFoundException() throw ();
private:
  /**
   * Creates an error message with the given file name.
   *
   * @param fileName the name of the file that was not found.
   * @return an error message with the given file name.
   *
   */
  static string const createErrorMessage(string const & fileName);
};

#endif /* FILENOTFOUNDEXCEPTION_H */
