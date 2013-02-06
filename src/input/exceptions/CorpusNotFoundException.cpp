/**
 * @file CorpusNotFoundException.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the locations of the GNU General Public License as published by
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

#include "mewt/input/exceptions/CorpusNotFoundException.h"
#include <sstream>

using std::stringstream;

using namespace mewt::input::exceptions;

CorpusNotFoundException::CorpusNotFoundException()
: Exception(CORPUS_NOT_FOUND_MESSAGE) {
}

CorpusNotFoundException::CorpusNotFoundException(
        const string location, bool const & isMessage)
: Exception(isMessage ? location : createErrorMessage(location)) {
}

CorpusNotFoundException::CorpusNotFoundException(const string message)
: Exception(message) {
}

string const CorpusNotFoundException::createErrorMessage(
        string const & location) const {
  stringstream stream;
  stream << CORPUS_NOT_FOUND_MESSAGE << " \nLocation: " << location << ".";
  return stream.str();
}
