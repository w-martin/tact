/**
 * @file AlphabetIterator.h
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

#ifndef ALPHABETITERATOR_H
#define ALPHABETITERATOR_H

#include <string>
#include <boost/bimap.hpp>

using std::string;
using boost::bimaps::bimap;

namespace mewt {

  namespace input {

    namespace corpus {

      namespace feature {

        typedef bimap< string, int > bmType;

        /**
         * Iterates of Alphabet terms.
         * 
         */
        class AlphabetIterator {
        public:
          /**
           * Default constructor.
           * 
           * @param iter the internal representation of data.
           * 
           */
          AlphabetIterator(bmType::left_const_iterator const iter);
          /**
           * Copy constructor.
           * 
           * @param orig the AlphabetIterator to copy from.
           * 
           */
          AlphabetIterator(AlphabetIterator const & orig);
          /**
           * Default destructor.
           * 
           */
          virtual ~AlphabetIterator();
          /**
           * Iterates to the next term.
           * 
           * @return the next term iterator.
           * 
           */
          AlphabetIterator operator++();
          /**
           * Iterates to the next term.
           * 
           * @return the next term iterator.
           * 
           */
          AlphabetIterator operator++(int);
          /**
           * Checks whether this AlphabetIterator is the same as the other
           * AlphabetIterator.
           * 
           * @param other the AlphabetIterator to compare against.
           * @return true if this AlphabetIterator is the same as the other
           * AlphabetIterator, false otherwise.
           * 
           */
          bool const operator==(AlphabetIterator const & other) const;
          /**
           * Checks whether this AlphabetIterator is the same as the other
           * AlphabetIterator.
           * 
           * @param other the AlphabetIterator to compare against.
           * @return true if this AlphabetIterator is the same as the other
           * AlphabetIterator, false otherwise.
           * 
           */
          bool const operator!=(AlphabetIterator const & other) const;
          /**
           * Checks if this AlphabetIterator doesn't equal another 
           * AlphabetIterator.
           * 
           * @param other the other AlphabetIterator.
           * @return false if this AlphabetIterator is the same as the other
           * AlphabetIterator, true otherwise.
           * 
           */
          bool const equals(AlphabetIterator const & other) const;
          /**
           * Gets the index of the term at this iterator position.
           * 
           * @return the index of the term at this iterator position.
           * 
           */
          int const getIndex() const;
          /**
           * Gets the term at this iterator position.
           * 
           * @return the term at this iterator position.
           * 
           */
          string const getTerm() const;
        protected:
          /**
           * Gets the internal representation of data.
           * 
           * @return the internal representation of data.
           * 
           */
          bmType::left_const_iterator const getIterator() const;
        private:
          /**
           * Internal representation of data.
           * 
           */
          bmType::left_const_iterator iter;
        };

      };

    };

  };

};

#endif /* ALPHABETITERATOR_H */
