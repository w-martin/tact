/**
 * @file TextDocument.h
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

#ifndef TEXTDOCUMENT_H
#define	TEXTDOCUMENT_H
#define DOCUMENT_TYPE_TEXT 1

#include "teflon/input/corpus/Document.h"
#include <memory>

using std::auto_ptr;

/**
 * TextDocument class for corpus files. Stores the name of the file.
 *
 */
class TextDocument : public Document {
public:
  /**
   * Default constructor.
   *
   * @param name the name of the file.
   *
   */
  TextDocument(string const name, auto_ptr< string > text);
  /**
   * Copy constructor.
   *
   * @param orig the TextDocument to copy.
   *
   */
  TextDocument(const TextDocument& orig);
  /**
   * Default destructor.
   *
   */
  virtual ~TextDocument();
  /**
   * Gets the text from this TextDocument.
   *
   * @return the text from this TextDocument.
   *
   */
  string const * const getText() const;
  /**
   * Gets the type of this Document.
   *
   * @return the type of this Document.
   *
   */
  virtual int const getType() const;
private:
  auto_ptr< string > text;
};

#endif	/* TEXTDOCUMENT_H */
