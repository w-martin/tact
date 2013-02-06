/**
 * @file Alphabet.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#include "mewt/input/corpus/feature/Alphabet.h"
#include <sstream>
#include <vector>

using std::endl;
using std::stringstream;
using std::make_pair;
using std::vector;

using namespace mewt::input::corpus::feature;

Alphabet::Alphabet() {
  data = new bmType();
  nextIndex = 0;
}

Alphabet::Alphabet(Alphabet const & orig) {
  data = new bmType(*orig.getData());
  nextIndex = orig.getNextIndex();
}

Alphabet::~Alphabet() {
  delete data;
}

int const Alphabet::addTerm(string const term) {
  try {
    return getIndex(term);
  } catch (TermNotPresentException const &) {
    int index;
    while (hasIndex(index = nextIndex++));
    while (hasIndex(nextIndex)) {
      nextIndex++;
    }
    data->insert(bmType::value_type(term, index));
    return index;
  }
}

int const Alphabet::addTerm(string const term, int const index)
throw (DuplicateException) {
  if (hasTerm(term)) {
    stringstream stream;
    stream << "Error. Term '" << term
            << "' already present in this Alphabet." << endl;
    throw DuplicateException(stream.str());
  }
  if (hasIndex(index)) {
    stringstream stream;
    stream << "Error. Index '" << index
            << "' already present in this Alphabet." << endl;
    throw DuplicateException(stream.str());
  }
  if (index == nextIndex) {
    nextIndex++;
  }
  while (hasIndex(nextIndex)) {
    nextIndex++;
  }
  data->insert(bmType::value_type(term, index));
  return index;
}

AlphabetIterator const Alphabet::begin() const {
  return AlphabetIterator(data->left.begin());
}

AlphabetIterator const Alphabet::end() const {
  return AlphabetIterator(data->left.end());
}

bool const Alphabet::equals(Alphabet const & other) const {
  if (getSize() == other.getSize()) {
    AlphabetIterator iter2 = other.begin();
    AlphabetIterator iter1 = begin();
    while (end() != iter1
            && other.end() != iter2) {
      if (iter1.getIndex() != iter2.getIndex()
              || iter1.getTerm() != iter2.getTerm()) {
        return false;
      }
      iter1++;
      iter2++;
    }
  } else {
    return false;
  }
  return true;
}

bool const Alphabet::operator ==(Alphabet const & other) const {
  return equals(other);
}

bool const Alphabet::operator !=(Alphabet const & other) const {
  return !equals(other);
}

int const Alphabet::getIndex(const string & term) const
throw (TermNotPresentException) {
  bmType::left_const_iterator result = data->left.find(term);
  if (data->left.end() != result) {
    return result->second;
  } else {
    throw TermNotPresentException(term, false);
  }
}

int const Alphabet::getNextIndex() const {

  return nextIndex;
}

int const Alphabet::getSize() const {

  return data->size();
}

string const Alphabet::getTerm(const int & index) const
throw (TermNotPresentException) {
  bmType::right_const_iterator result = data->right.find(index);
  if (data->right.end() != result) {
    return result->second;
  }
  throw createExceptionWithIndex(index);
}

bool const Alphabet::hasIndex(int const & id) const {
  try {
    getTerm(id);
    return true;
  } catch (TermNotPresentException const &) {
    return false;
  }
}

bool const Alphabet::hasTerm(const string & term) const {
  try {
    getIndex(term);
    return true;
  } catch (TermNotPresentException const &) {
    return false;
  }
}

string const Alphabet::removeTerm(const int & index)
throw (TermNotPresentException) {
  string const term = getTerm(index);
  data->right.erase(index);
  return term;
}

int const Alphabet::removeTerm(const string & term)
throw (TermNotPresentException) {
  int const index = getIndex(term);
  data->left.erase(term);

  return index;
}

map< int, int > Alphabet::squash() {
  bool indices[getSize()];
  for (int i = 0; i < getSize(); i++) {
    indices[i] = false;
  }
  vector< int > indicesToReplace;
  for (AlphabetIterator iter = begin();
          end() != iter; iter++) {
    int const index = iter.getIndex();
    if (getSize() <= index) {
      indicesToReplace.push_back(index);
    } else {
      indices[index] = true;
    }
  }
  vector< int >::const_iterator iter = indicesToReplace.begin();
  map< int, int > replacements;
  for (int i = 0; i < getSize(); i++) {
    if (!indices[i]) {
      int const original = *iter;
      string const term = getTerm(original);
      data->right.erase(original);
      data->insert(bmType::value_type(term, i));
      replacements.insert(make_pair(original, i));
      iter++;
    }
  }
  nextIndex = getSize();
  return replacements;
}

bmType const * const Alphabet::getData() const {
  return data;
}

TermNotPresentException const Alphabet::createExceptionWithIndex(
        const int index) const {
  stringstream stream;
  stream << "has index " << index;
  return TermNotPresentException(stream.str(), false);
}
