/**
 * @file Exception.h
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <exception>
#include <string>

using std::string;

/**
 * Custom <code>Exception</code> class.
 * 
 * @param message the message that will be printed as the cause for this
 * <code>Exception</code>.
 * 
 */
class Exception : public std::exception {
public:

    /**
     * Default constructor.
     * 
     * @param message the message that will be printed as the cause for this
     * <code>Exception</code>.
     * 
     */
    Exception(string message) {
        Exception::message = message;
    }

    virtual ~Exception() throw () {
    }

    virtual const char * what() const throw () {
        return message.c_str();
    }
private:
    string message;
};

#endif	/* EXCEPTION_H */

