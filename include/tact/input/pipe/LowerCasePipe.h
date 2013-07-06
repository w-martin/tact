/**
 * @file LowerCasePipe.h
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

#ifndef LOWERCASEPIPE_H
#define	LOWERCASEPIPE_H

#include "tact/input/pipe/Pipe.h"

/**
 * LowerCasePipe class for transforming Corpus objects.
 *
 */
class LowerCasePipe : public Pipe {
public:
  /**
   * Default constructor.
   *
   */
  LowerCasePipe();
  /**
   * Default destructor.
   *
   */
  virtual ~LowerCasePipe();
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

#endif	/* LOWERCASEPIPE_H */
