/**
 * @file IllegalArgumentException.cpp
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
 * @section DESCRIPTION
 *
 * This is the main entry point at runtime.
 * 
 */

#include "mewt/util/exceptions/IllegalArgumentException.h"

IllegalArgumentException::IllegalArgumentException()
: Exception(string(ILLEGAL_ARGUMENT_MESSAGE)) {
}

IllegalArgumentException::IllegalArgumentException(const string message)
: Exception(message) {
}
