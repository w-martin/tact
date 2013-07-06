/**
 * @file FileNotFoundException.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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

#include "tact/util/exceptions/FileNotFoundException.h"
#include <sstream>

using std::stringstream;

FileNotFoundException::FileNotFoundException()
  : Exception(FILE_NOT_FOUND_MESSAGE) {
}

FileNotFoundException::FileNotFoundException(string const & fileName,
    bool const & isMessage)
  : Exception(isMessage ? fileName : createErrorMessage(fileName)) {
}

FileNotFoundException::FileNotFoundException(string const & message)
  : Exception(message) {
}

FileNotFoundException::~FileNotFoundException() throw () {
}

string const FileNotFoundException::createErrorMessage(
  string const & fileName) {
  stringstream stream;
  stream << FILE_NOT_FOUND_MESSAGE << " \nFile name: " << fileName;
  return stream.str();
}
