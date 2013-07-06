/**
 * @file Files.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
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

#ifndef FILES_H
#define FILES_H

#include <memory>
#include <string>

using std::auto_ptr;
using std::string;

namespace tact {

namespace util {

/**
 * Namespace containing methods for manipulating files.
 *
 */
namespace files {
/**
 * Reads the given file directly into a string.
 *
 * @param location the location of the file on disk.
 * @return the string which was read.
 *
 */
auto_ptr< string > readFile(string const & location);
/**
 * Appends the given text to the file with the given name.
 *
 * @param text the text to append to the file.
 * @param filename the name of the file to append.
 *
 */
void appendFile(string const & text, string const & filename);
};

};

};

#endif /* FILES_H */
