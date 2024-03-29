/**
 * @file InputPipe.cpp
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

#include "tact/input/corpus/text/TextCorpus.h"
#include "tact/input/pipe/InputPipe.h"
#include "tact/util/Files.h"

using tact::util::files::readFile;

InputPipe::InputPipe() {
}

InputPipe::~InputPipe() {
}

auto_ptr< Corpus > InputPipe::process(
  auto_ptr<Corpus> originalCorpus) const {

  string const location = originalCorpus->getLocation();
  vector< Document * > const * const originalDocuments =
    originalCorpus->getDocuments();
  auto_ptr< TextCorpus > corpus =
    auto_ptr< TextCorpus > (new TextCorpus(location));

  for (vector< Document * >::const_iterator iter = originalDocuments->begin();
       originalDocuments->end() != iter; iter++) {

    string const name = (*iter)->getName();
    auto_ptr< string > text = readFile(name);

    auto_ptr< Document > doc = auto_ptr< Document > (
                                 new TextDocument(name, text));
    corpus->addDocument(doc);

  }
  return (auto_ptr< Corpus >) corpus;
}
