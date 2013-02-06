/**
 * @file Document.h
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

#ifndef DOCUMENT_H
#define	DOCUMENT_H
#define DOCUMENT_TYPE_BASIC 0

#include <string>

using std::string;

namespace mewt {

  namespace input {

    namespace corpus {

      /**
       * Document class for corpus files. Stores the name of the file.
       * 
       */
      class Document {
      public:
        /**
         * Default constructor.
         * 
         * @param name the name of the file.
         * 
         */
        Document(string const name);
        /**
         * Copy constructor.
         * 
         * @param orig the Document to copy.
         * 
         */
        Document(const Document& orig);
        /**
         * Default destructor.
         * 
         */
        virtual ~Document();
        /**
         * Checks if this Document is equal to the other Document.
         * 
         * @param other the Document to check against.
         * @return true if this Document is equal to the other Document,
         * false otherwise.
         * 
         */
        virtual bool const equals(Document const & other) const;
        /**
         * Checks if this Document is equal to the other Document.
         * 
         * @param other the Document to check against.
         * @return true if this Document is equal to the other Document,
         * false otherwise.
         * 
         */
        bool const operator==(Document const & other) const;
        /**
         * Checks if this Document is not equal to the other Document.
         * 
         * @param other the Document to check against.
         * @return true if this Document is not equal to the other Document,
         * false otherwise.
         * 
         */
        bool const operator!=(Document const & other) const;
        /**
         * Gets the name of this Document.
         * 
         * @return the name of this Document.
         * 
         */
        string const getName() const;
        /**
         * Gets the type of this Document.
         * 
         * @return the type of this Document.
         * 
         */
        virtual int const getType() const;
      private:
        string name;
      };

    };

  };

};

#endif	/* DOCUMENT_H */
