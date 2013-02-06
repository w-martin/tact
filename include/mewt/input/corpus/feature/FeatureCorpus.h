/**
 * @file FeatureCorpus.h
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

 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef FEATURECORPUS_H
#define	FEATURECORPUS_H

#include "mewt/input/corpus/Corpus.h"
#include "mewt/input/corpus/feature/Alphabet.h"
#include "mewt/input/corpus/feature/FeatureDocument.h"

namespace mewt {

  namespace input {

    namespace corpus {

      namespace feature {

        /**
         * Store of TextDocument objects.
         * 
         */
        class FeatureCorpus : public Corpus {
        public:
          /**
           * Default constructor.
           * 
           * @param location the location of the Corpus on disk.
           * @param alphabet the Alphabet for this Corpus.
           * 
           */
          FeatureCorpus(string const location, auto_ptr< Alphabet > alphabet);
          /**
           * Default destructor.
           * 
           */
          virtual ~FeatureCorpus();
          /**
           * Gets the Alphabet for this Corpus.
           * 
           * @return the Alphabet for this Corpus.
           * 
           */
          Alphabet * const getAlphabet() const;
          /**
           * Replaces the given term with the set of replacement terms.
           * 
           * @param originalTerm the term to replace.
           * @param terms the terms to replace the given term with.
           * @throw TermNotPresentException if the originalTerm to replace is 
           * not present in the Alphabet.
           * 
           */
          void replaceTerm(string const & originalTerm,
                  vector< string > const & terms)
          throw (TermNotPresentException);
          /**
           * Squashes the Alphabet and FeatureMaps so that the maximum feature 
           * ID is equal to the number of features - 1.
           * 
           */
          void squash();
          /**
           * Creates an instance of FeatureCorpus with the given location and an
           * empty Alphabet.
           * 
           * @param location the location of the created FeatureCorpus.
           * @return an instance of FeatureCorpus with the given location and an
           * empty Alphabet.
           * 
           */
          static auto_ptr< FeatureCorpus > createInstance(
                  string const & location);
        private:
          Alphabet * alphabet;
        };

      };

    };

  };

};

#endif	/* FEATURECORPUS_H */
