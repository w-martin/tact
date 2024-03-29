/**
 * @file TextCorpus.h
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

 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef TEXTCORPUS_H
#define	TEXTCORPUS_H

#include "tact/input/corpus/Corpus.h"
#include "tact/input/corpus/text/TextDocument.h"

/**
 * Store of TextDocument objects.
 *
 */
class TextCorpus : public Corpus {
public:
  /**
   * Default constructor.
   *
   * @param location the location of the corpus on disk.
   *
   */
  TextCorpus(string const location);
  /**
   * Default destructor.
   *
   */
  virtual ~TextCorpus();
};

#endif	/* TEXTCORPUS_H */
