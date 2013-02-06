/**
 * @file PunctuationFilter.h
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

#ifndef PUNCTUATIONFILTER_H
#define PUNCTUATIONFILTER_H

#include "mewt/input/pipe/Pipe.h"

namespace mewt {

  namespace input {

    namespace pipe {

      class PunctuationFilter : public Pipe {
      public:
        /**
         * Default constructor.
         * 
         */
        PunctuationFilter();
        /**
         * Default destructor.
         * 
         */
        virtual ~PunctuationFilter();
        /**
         * Removes punctuation form the given term.
         * 
         * @param term the term to remove punctuation from.
         * @return the set of terms that surrounded punctuation in the given
         * term.
         */
        static vector< string > const removePunctuation(string const & term);
      private:
        /**
         * Process the given corpus.
         * 
         * @param corpus the Corpus to process.
         * @return the processed Corpus.
         * 
         */
        auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const;
      };

    };

  };

};

#endif /* PUNCTUATIONFILTER_H */
