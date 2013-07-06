/**
 * @file Strings.h
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

#ifndef STRINGS_H
#define STRINGS_H

#include <memory>
#include <string>
#include <vector>

#include "tact/util/exceptions/BadCastException.h"

using std::auto_ptr;
using std::string;
using std::vector;

namespace tact {

namespace util {

/**
 * Namespace for string-manipulating methods.
 *
 */
namespace strings {
/**
 * Checks if the first string contains an instance of the second.
 *
 * @param first the string to check.
 * @param second the string to check for.
 * @param caseSensitive indicates whether the check should be case
 * sensitive, defaults to true for speed.
 * @return true if the first string contains an instance of the
 * second, false otherwise.
 *
 */
bool const contains(string const & first, string const & second,
                    bool const & caseSensitive = true);
/**
 * Checks if the given term contains punctuation.
 *
 * @param term the term to check.
 * @return true if the given term contains punctuation,
 * false otherwise.
 *
 */
bool const containsPunctuation(string const & term);
/**
 * Checks if the given term contains any upper case characters.
 *
 * @param term the term to check for upper case characters.
 * @return true if the given term contains any upper case
 * characters, false otherwise.
 *
 */
bool const containsUpper(string const & term);
/**
 * Checks if the given term matches the given regular expression.
 *
 * @param term the term to match.
 * @param regex the regular expression to match.
 * @return true if the given term matches the given regular
 * expression, false otherwise.
 *
 */
bool const matches(string const & term, string const & regex);
/**
 * Replaces any instances of the given regular expression in the
 * given text, with the given replacement.
 *
 * @param text the text to process.
 * @param regex the regular expression to detect.
 * @param replacement the replacement for any found instances
 * of the given regular expression.
 * @return the processed text.
 *
 */
string const replace(string const & text, string const & regex,
                     string const & replacement);
/**
 * Splits the given text on the given delimiter.
 *
 * @param text the string to split.
 * @param delim the delimiter to split the text on.
 * @return a vector of the subsections of the given text which were
 * separated by the given delimiter.
 *
 */
auto_ptr< vector< string > > split(string const & text,
                                   string const & delim);
/**
 * Splits the given text on whitespace.
 *
 * @param text the text to split.
 * @return a vector of the subsections of the given text which were
 * separated by whitespace.
 *
 */
auto_ptr< vector< string > > split(string const & text);
/**
 * Splits the given text into separate lines.
 *
 * @param text the text to split.
 * @return a vector of the lines from the given text.
 *
 */
auto_ptr< vector< string > > splitLines(string const & text);
/**
 * Converts the given text to an integer if possible.
 *
 * @param text the text to convert.
 * @return an integer representing the given text.
 * @throw BadCastException if the text does not represent an
 * integer.
 *
 */
int const toInteger(string const & text) throw (BadCastException);
/**
 * Transforms the given term to lower case.
 *
 * @param originalTerm the original term containing upper
 * case characters.
 * @return the transformed term.
 *
 */
string const transformToLower(string const & originalTerm);
};

};

};

#endif /* STRINGS_H */
