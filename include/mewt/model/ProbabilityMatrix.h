/**
 * @file ProbabilityMatrix.h
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#ifndef PROBABILITYMATRIX_H
#define	PROBABILITYMATRIX_H

#include "teflon/util/exceptions/OutOfBoundsException.h"

/**
 * Represents an Probability Matrix.
 * 
 */
class ProbabilityMatrix {
public:
    /**
     * Default constructor.
     * 
     * @param noRows the number of rows in this matrix.
     * @param noColumns the number of columns in this matrix.
     * 
     */
    ProbabilityMatrix(int const & noRows, int const & noColumns);
    /**
     * Copy constructor.
     * 
     * @param orig the matrix to copy from.
     * 
     */
    ProbabilityMatrix(ProbabilityMatrix const & orig);
    /**
     * Default destructor.
     * 
     */
    virtual ~ProbabilityMatrix();
    /**
     * Gets the number of rows in this matrix.
     * 
     * @return the number of rows in this matrix.
     * 
     */
    int const getNoRows() const;
    /**
     * Gets the number of columns in this matrix.
     * 
     * @return the number of columns in this matrix.
     * 
     */
    int const getNoColumns() const;
    /**
     * Gets the specified element in this matrix.
     * 
     * @param row the row of the element to get.
     * @param column the column of the element to get.
     * @return the specified element in this matrix.
     * @throw OutOfBoundsException if the row or column exceeds this matrix's
     * dimensions.
     * 
     */
    double const getElement(int const & row, int const & column) const
    throw (OutOfBoundsException);
    /**
     * Sets the specified element in this matrix.
     * 
     * @param row the row of the element to set.
     * @param column the column of the element to set.
     * @param value the new value for the element.
     * @throw OutOfBoundsException if the row or column exceeds this matrix's
     * dimensions.
     * 
     */
    void setElement(int const & row, int const & column, double const value)
    throw (OutOfBoundsException);
private:
    int noRows;
    int noColumns;
    double * * matrix;
};

#endif	/* PROBABILITYMATRIX_H */
