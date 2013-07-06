/**
 * @file Pipe.cpp
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

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "tact/input/pipe/Pipe.h"

Pipe::Pipe() {
  Pipe::compatibleDocumentTypes = new vector< int >();
}

Pipe::Pipe(const int compatibleType) {
  Pipe::compatibleDocumentTypes = new vector< int >();
  compatibleDocumentTypes->push_back(compatibleType);
}

Pipe::Pipe(vector<int> const & compatibleTypes) {
  Pipe::compatibleDocumentTypes = new vector< int >(compatibleTypes);
}

Pipe::~Pipe() {
  delete compatibleDocumentTypes;
}

vector< int > const * const Pipe::getCompatibleTypes() const {
  return compatibleDocumentTypes;
}

Pipe const * const Pipe::getNextPipe() const {
  return nextPipe.get();
}

void Pipe::attachPipe(auto_ptr<Pipe> nextPipe) {
  if (NULL == Pipe::nextPipe.get()) {
    Pipe::nextPipe = nextPipe;
  } else {
    Pipe::nextPipe->attachPipe(nextPipe);
  }
}

auto_ptr< Corpus > Pipe::pipe(auto_ptr<Corpus> corpus) const
throw (IncompatibleCorpusException) {
  if (!checkCorpusCompatible(corpus.get())) {
    throw IncompatibleCorpusException(
      corpus->getDocumentsType(), getCompatibleTypes(), "Pipe::pipe");
  }
  if (NULL == nextPipe.get()) {
    return process(corpus);
  } else {
    return nextPipe->pipe(process(corpus));
  }
}

bool const Pipe::checkCorpusCompatible(Corpus const * const corpus) const {
  if (0 == getCompatibleTypes()->size()) {
    return true;
  }
  for (vector< int >::const_iterator iter = getCompatibleTypes()->begin();
       getCompatibleTypes()->end() != iter; iter++) {
    if (corpus->getDocumentsType() == (*iter)) {
      return true;
    }
  }
  return false;
}
