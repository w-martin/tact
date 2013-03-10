/**
 * @file DuplicateException.h
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
 *
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DUPLICATEEXCEPTION_H
#define DUPLICATEEXCEPTION_H

#define DUPLICATE_MESSAGE "Error. Duplicate."

#include "teflon/util/exceptions/Exception.h"

class DuplicateException : public Exception {
public:
  /**
   * Default constructor. Uses the default error message.
   *
   */
  DuplicateException();
  /**
   * Specific constructor. Uses the given error message.
   *
   * @param message the message to use.
   *
   */
  DuplicateException(string const & message);
  /**
   * Default destructor.
   *
   */
  virtual ~DuplicateException() throw ();
};

#endif /* DUPLICATEEXCEPTION_H */
