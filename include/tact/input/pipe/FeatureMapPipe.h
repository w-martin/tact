/**
 * @file FeatureMapPipe.h
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

#ifndef FEATUREMAPPIPE_H
#define	FEATUREMAPPIPE_H

#include "tact/input/pipe/Pipe.h"

/**
 * FeatureMapPipe class for transforming TextCorpus objects into
 * FeatureMapCorpus objects.  A static assert is used to check that the
 * correct corpus types are used as input.
 *
 */
class FeatureMapPipe : public Pipe {
public:
  /**
   * Default constructor.
   *
   */
  FeatureMapPipe();
  /**
   * Default destructor.
   *
   */
  virtual ~FeatureMapPipe();
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

#endif	/* FEATUREMAPPIPE_H */
