/**
 * @file Strings.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
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

#include "teflon/util/Strings.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

namespace strings = teflon::util::strings;

bool const strings::contains(string const & first, string const & second,
                             bool const & caseSensitive) {
  if (caseSensitive) {
    return boost::algorithm::find_first(first, second);
  } else {
    return boost::algorithm::ifind_first(first, second);
  }
}

bool const strings::containsPunctuation(string const & term) {
  return matches(term, ".*\\W+.*");
}

bool const strings::containsUpper(string const & term) {
  return matches(term, ".*[A-Z]+.*");
}

bool const strings::matches(string const & term, string const & regex) {
  boost::regex test(regex, boost::regex::perl);
  return boost::regex_match(term.begin(), term.end(), test);
}

string const strings::replace(string const & text, string const & regex,
                              string const & replacement) {
  boost::regex re(regex);
  return boost::regex_replace(text, re, replacement);
}

auto_ptr< vector< string > > strings::split(
  string const & text, string const & delim) {
  vector< string > strings;
  boost::regex re(delim);
  boost::algorithm::split_regex(strings, text, re);

  auto_ptr< vector< string > > pruned =
    auto_ptr< vector< string > >(new vector< string > ());
  for (vector< string >::iterator iter = strings.begin();
       strings.end() != iter; iter++) {
    if (0 != iter->size()) {
      pruned->push_back(*iter);
    }
  }
  strings.clear();

  return pruned;
}

auto_ptr< vector< string > > strings::split(string const & text) {
  return split(text, "\\s");
}

auto_ptr< vector< string > > strings::splitLines(string const & text) {
  return split(text, "\n");
}

int const strings::toInteger(string const & text) throw (BadCastException) {
  try {
    return boost::lexical_cast< int >(text);
  } catch (boost::bad_lexical_cast const & blc) {
    throw (BadCastException(blc.what()));
  }
}

string const strings::transformToLower(string const & originalTerm) {
  string transformed = originalTerm;
  boost::algorithm::to_lower(transformed);
  return transformed;
}
