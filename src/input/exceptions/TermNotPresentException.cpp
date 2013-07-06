/**
 * @file TermNotPresentException.cpp
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

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "tact/input/exceptions/TermNotPresentException.h"
#include <sstream>

using std::stringstream;

TermNotPresentException::TermNotPresentException()
  : Exception(TERM_NOT_PRESENT_MESSAGE) {
}

TermNotPresentException::TermNotPresentException(
  const string term, bool const & isMessage)
  : Exception(isMessage ? term : createErrorMessage(term)) {
}

TermNotPresentException::TermNotPresentException(const string message)
  : Exception(message) {
}

string const TermNotPresentException::createErrorMessage(
  string const & term) const {
  stringstream stream;
  stream << TERM_NOT_PRESENT_MESSAGE << " \nTerm: " << term;
  return stream.str();
}
