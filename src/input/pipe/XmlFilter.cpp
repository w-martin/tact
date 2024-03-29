/**
 * @file XmlFilter.cpp
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

#include "tact/input/corpus/text/TextCorpus.h"
#include "tact/input/pipe/XmlFilter.h"
#include "tact/util/Strings.h"

using tact::util::strings::replace;

XmlFilter::XmlFilter() : Pipe(DOCUMENT_TYPE_TEXT) {
}

XmlFilter::~XmlFilter() {
}

auto_ptr< Corpus > XmlFilter::process(auto_ptr<Corpus> corpus) const {
  vector< Document * > const * const documents = corpus->getDocuments();
  for (vector< Document * >::const_iterator iter = documents->begin();
       documents->end() != iter; iter++) {
    TextDocument const * const original = ((TextDocument *) (*iter));
    string const name = original->getName();
    auto_ptr< string > text = removeXml(*original->getText());
    corpus->removeDocument(original);
    corpus->addDocument(auto_ptr< Document > (
                          new TextDocument(name, text)));
  }
  return corpus;
}

auto_ptr< string > XmlFilter::removeXml(string const & text) {
  return auto_ptr< string > (new string(replace(text, "<[^>]*>", " ")));
}
