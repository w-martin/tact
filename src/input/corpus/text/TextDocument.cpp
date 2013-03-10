/**
 * @file TextDocument.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 *
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "teflon/input/corpus/text/TextDocument.h"

TextDocument::TextDocument(const string name, auto_ptr< string > text)
  : Document(name) {
  TextDocument::text = text;
}

TextDocument::TextDocument(const TextDocument& orig) : Document(orig) {
  text = auto_ptr< string > (new string(*orig.getText()));
}

TextDocument::~TextDocument() {
}

string const * const TextDocument::getText() const {
  return text.get();
}

int const TextDocument::getType() const {
  return DOCUMENT_TYPE_TEXT;
}
