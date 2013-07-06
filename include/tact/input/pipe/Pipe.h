/**
 * @file Pipe.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#ifndef PIPE_H
#define	PIPE_H

#include "tact/input/corpus/Corpus.h"
#include "tact/input/exceptions/IncompatibleCorpusException.h"

/**
 * Pipe class for transforming Corpus objects.
 *
 */
class Pipe {
public:
  /**
   * Default constructor.
   *
   */
  Pipe();
  /**
   * Compatible type constructor.
   *
   * @param compatibleType the type of document that is compatible with
   * this Pipe.
   *
   */
  Pipe(int const compatibleType);
  /**
   * Compatible types constructor.
   *
   * @param compatibleTypes the types of documents that are compatible
   * with this Pipe.
   *
   */
  Pipe(vector< int > const & compatibleTypes);
  /**
   * Default destructor.
   *
   */
  virtual ~Pipe();
  /**
   * Gets the document types that are compatible with this Pipe.
   *
   * @return the document types that are compatible with this Pipe.
   *
   */
  vector< int > const * const getCompatibleTypes() const;
  /**
   * Gets the next Pipe in the sequence.
   *
   * @param nextPipe the next Pipe in the sequence.
   *
   */
  Pipe const * const getNextPipe() const;
  /**
   * Attaches a pipe that will process the output at the end of this
   * Pipe sequence.
   *
   * @param nextPipe the next Pipe in the sequence.
   *
   */
  void attachPipe(auto_ptr< Pipe > nextPipe);
  /**
   * Processes the given input and passes it to the next Pipe in the
   * sequence.
   *
   * @param corpus the Corpus to pipe.
   * @return the piped corpus.
   * @throw IncompatibleCorpusException if the given Corpus was of an
   * incompatible type with this Pipe.
   *
   */
  auto_ptr< Corpus > pipe(auto_ptr< Corpus > corpus) const
  throw (IncompatibleCorpusException);
private:
  /**
   * Vector of compatible document type identifiers. Empty indicates
   * that all documents are compatible.
   *
   */
  vector< int > * compatibleDocumentTypes;
  /**
   * The next Pipe in this sequence.
   *
   */
  auto_ptr< Pipe > nextPipe;
  /**
   * Checks whether the given Corpus is compatible with this Pipe.
   *
   * @param corpus the Corpus to check.
   * @return true if the given Corpus is compatible with this Pipe, false
   * otherwise.
   *
   */
  bool const checkCorpusCompatible(Corpus const * const corpus) const;
  /**
   * Process the given corpus.
   *
   * @param corpus the Corpus to process.
   * @return the processed Corpus.
   *
   */
  virtual auto_ptr< Corpus > process(auto_ptr< Corpus > corpus) const = 0;
};

#endif	/* PIPE_H */
