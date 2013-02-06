/**
 * @file DirectoryScannerPipe.h
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

#ifndef DIRECTORYSCANNERPIPE_H
#define DIRECTORYSCANNERPIPE_H

#include "mewt/input/pipe/Pipe.h"

namespace mewt {

  namespace input {

    namespace pipe {

      class DirectoryScannerPipe : public Pipe {
      public:
        /**
         * Default constructor.
         * 
         * @param recursive indicates whether this scanner is recursive or not.
         * 
         */
        DirectoryScannerPipe(bool const recursive);
        /**
         * Default destructor.
         * 
         */
        virtual ~DirectoryScannerPipe();
        /**
         * Checks whether this scanner is recursive or not.
         * 
         * @return true if this scanner is recursive, false otherwise.
         * 
         */
        bool const isRecursive() const;
      private:
        /**
         * Indicates whether this scanner is recursive or not.
         * 
         */
        bool recursive;
        /**
         * Adds the documents in the given directory to the given corpus.
         * 
         * @param corpus the corpus to add documents to.
         * @param directory the directory to add documents from.
         * 
         */
        void addDocumentsInDirectory(
                string const & directory, Corpus * const corpus) const;
        /**
         * Adds the given document to the given corpus.
         * 
         * @param location the location of the document relative to the corpus
         * directory.
         * @param corpus the corpus to add the document to.
         * 
         */
        void addDocument(string const location, Corpus * const corpus) const;
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

#endif /* DIRECTORYSCANNERPIPE_H */
