/**
 * @file BadCastException.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
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

#ifndef BADCASTEXCEPTION_H
#define BADCASTEXCEPTION_H

#define BAD_CAST_MESSAGE "Error. Bad cast."

#include "tact/util/exceptions/Exception.h"

/**
 * Exception class which indicates that bad cast occurred.
 *
 */
class BadCastException : public Exception {
public:
  /**
   * Default constructor.
   *
   */
  BadCastException();
  /**
   * Specific constructor.
   *
   * @param the message to given this Exception.
   *
   */
  BadCastException(string const & message);
  /**
   * Default destructor.
   *
   */
  virtual ~BadCastException() throw ();
};

#endif /* BADCASTEXCEPTION_H */
