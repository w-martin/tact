/**
 * @file IncompatibleCorpusException.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "mewt/input/pipe/exceptions/IncompatibleCorpusException.h"
#include <sstream>

using std::stringstream;

IncompatibleCorpusException::IncompatibleCorpusException()
: Exception(INCOMPATIBLE_CORPUS_MESSAGE) {
}

IncompatibleCorpusException::IncompatibleCorpusException(
        const string & message)
: Exception(message) {
}

IncompatibleCorpusException::IncompatibleCorpusException(
        int const & corpusType, int const & requiredType)
: Exception(createErrorMessage(corpusType, requiredType)) {
}

string const IncompatibleCorpusException::createErrorMessage(
        int const & corpusType, int const & requiredType) const {
    stringstream stream;
    stream << INCOMPATIBLE_CORPUS_MESSAGE << " \nCorpus type: " << corpusType
            << " \nPipe type: " << requiredType
            << ".";
    return stream.str();
}
