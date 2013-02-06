/**
 * @file DirectoryScannerPipe.cpp
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

#include "mewt/input/pipe/DirectoryScannerPipe.h"
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

using namespace mewt::input::pipe;

DirectoryScannerPipe::DirectoryScannerPipe(bool const recursive)
: Pipe() {
  DirectoryScannerPipe::recursive = recursive;
}

DirectoryScannerPipe::~DirectoryScannerPipe() {
}

bool const DirectoryScannerPipe::isRecursive() const {
  return recursive;
}

auto_ptr< Corpus > DirectoryScannerPipe::process(
        auto_ptr<Corpus> corpus) const {
  if (fs::is_directory(corpus->getLocation())) {
    addDocumentsInDirectory(corpus->getLocation(), corpus.get());
  }
  return corpus;
}

void DirectoryScannerPipe::addDocumentsInDirectory(
        string const & directory, Corpus * const corpus) const {
  for (fs::directory_iterator end, dir(directory);
          dir != end; ++dir) {
    string const location = (* dir).path().generic_string();
    if (fs::is_directory(*dir)) {
      if (isRecursive()) {
        addDocumentsInDirectory(location, corpus);
      }
    } else {
      addDocument(location, corpus);
    }
  }
}

void DirectoryScannerPipe::addDocument(
        const string location, Corpus * const corpus) const {
  auto_ptr< Document > document = auto_ptr< Document > (
          new Document(location));
  corpus->addDocument(document);
}
