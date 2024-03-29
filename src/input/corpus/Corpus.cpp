/**
 * @file Corpus.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#include "tact/input/corpus/Corpus.h"

Corpus::Corpus(const string location, const int documentsType) {
  Corpus::documents = new vector< Document * > ();
  Corpus::documentsType = documentsType;
  Corpus::location = location;
}

Corpus::~Corpus() {
  delete documents;
}

bool const Corpus::addDocument(auto_ptr<Document> document)
throw (IncompatibleCorpusException) {
  if (document->getType() != documentsType) {
    throw IncompatibleCorpusException(
      getDocumentsType(), document->getType(), "Corpus::addDocument");
  }
  if (!contains(document.get())) {
    documents->push_back(document.release());
    return true;
  } else {
    return false;
  }
}

bool const Corpus::contains(Document const * const document) const {
  if (document->getType() != documentsType) {
    return false;
  }
  for (int i = 0; i < getSize(); i++) {
    Document const * const other = documents->at(i);
    if (document->equals(*other)) {
      return true;
    }
  }
  return false;
}

bool const Corpus::equals(Corpus const & other) const {
  if (location != other.getLocation()
      || documentsType != other.getDocumentsType()
      || getSize() != other.getSize()) {
    return false;
  }
  for (vector< Document * >::const_iterator iter = documents->begin();
       documents->end() != iter; iter++) {
    if (!other.contains(*iter)) {
      return false;
    }
  }
  return true;
}

bool const Corpus::operator ==(Corpus const & other) const {
  return equals(other);
}

bool const Corpus::operator !=(Corpus const & other) const {
  return !equals(other);
}

vector< Document * > const * const Corpus::getDocuments() const {
  return documents;
}

int const Corpus::getDocumentsType() const {
  return documentsType;
}

string const Corpus::getLocation() const {
  return location;
}

int const Corpus::getSize() const {
  return documents->size();
}

bool const Corpus::removeDocument(Document const * const document) {
  if (document->getType() != getDocumentsType()) {
    return false;
  } else {
    for (vector< Document * >::iterator iter = documents->begin();
         documents->end() != iter; iter++) {
      if (document->equals(**iter)) {
        documents->erase(iter);
        return true;
      }
    }
  }
  return false;
}
