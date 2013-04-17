/**
 * @file InputPipe.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
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

#ifndef INPUTPIPE_H
#define	INPUTPIPE_H

#include "teflon/input/pipe/Pipe.h"

/**
 * InputPipe class for transforming Corpus objects.
 *
 */
class InputPipe : public Pipe {
public:
  /**
   * Default constructor.
   *
   */
  InputPipe();
  /**
   * Default destructor.
   *
   */
  virtual ~InputPipe();
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

#endif	/* INPUTPIPE_H */