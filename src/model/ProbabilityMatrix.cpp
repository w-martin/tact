/**
 * @file ProbabilityMatrix.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.1
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

#include "mewt/model/ProbabilityMatrix.h"
#include <cstdlib>

ProbabilityMatrix::ProbabilityMatrix(
        int const & noRows, int const & noColumns) {
    ProbabilityMatrix::noRows = noRows;
    ProbabilityMatrix::noColumns = noColumns;
    matrix = (double**) malloc(noRows * sizeof (double*));
    for (int i = 0; i < noRows; i++) {
        matrix[i] = (double*) calloc(noColumns, sizeof (double));
    }
}

ProbabilityMatrix::ProbabilityMatrix(const ProbabilityMatrix& orig) {
    noRows = orig.getNoRows();
    noColumns = orig.getNoColumns();
    matrix = (double**) malloc(noRows * sizeof (double*));
    for (int i = 0; i < noRows; i++) {
        matrix[i] = (double*) malloc(noColumns * sizeof (double));
        for (int j = 0; j < noColumns; j++) {
            matrix[i][j] = orig.getElement(i, j);
        }
    }
}

ProbabilityMatrix::~ProbabilityMatrix() {
    for (int i = 0; i < noRows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int const ProbabilityMatrix::getNoRows() const {
    return noRows;
}

int const ProbabilityMatrix::getNoColumns() const {
    return noColumns;
}

double const ProbabilityMatrix::getElement(
        int const & row, int const & column) const
throw (OutOfBoundsException) {
    if (0 > row
            || row >= noRows) {
        throw (OutOfBoundsException(row, noRows));
    } else if (0 > column
            || column >= noColumns) {
        throw (OutOfBoundsException(column, noColumns));
    }
    return matrix[row][column];
}

void ProbabilityMatrix::setElement(
        int const & row, int const & column, const double value)
throw (OutOfBoundsException) {
    if (0 > row
            || row >= noRows) {
        throw (OutOfBoundsException(row, noRows));
    } else if (0 > column
            || column >= noColumns) {
        throw (OutOfBoundsException(column, noColumns));
    }
    matrix[row][column] = value;
}
