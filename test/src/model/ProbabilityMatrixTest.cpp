/**
 * @file ProbabilityMatrixTest.cpp
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

#include "gtest/gtest.h"
#include "mewt/model/ProbabilityMatrix.h"
#include "gmock-1.6.0/gtest/fused-src/gtest/gtest.h"
#include "gmock-1.6.0/fused-src/gtest/gtest.h"

namespace {

    /**
     * Tests ProbabilityMatrix.
     * 
     */
    class ProbabilityMatrixTest : public ::testing::Test {
    protected:

        ProbabilityMatrixTest() {
            noRows = 5;
            noColumns = 15;
            matrix = new ProbabilityMatrix(noRows, noColumns);
        }

        virtual ~ProbabilityMatrixTest() {
            delete matrix;
        }
        ProbabilityMatrix * matrix;
        int noRows;
        int noColumns;
    };

    /*
     * Tests whether the getNoRows method works correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, GetNoRowsTest) {
        EXPECT_EQ(noRows, matrix->getNoRows());
    }

    /*
     * Tests whether the getNoColumns method works correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, GetNoColumnsTest) {
        EXPECT_EQ(noColumns, matrix->getNoColumns());
    }

    /*
     * Tests whether the initial values are set to zero.
     * 
     */
    TEST_F(ProbabilityMatrixTest, InitialValuesTest) {
        for (int i = 0; i < noRows; i++) {
            for (int j = 0; j < noColumns; j++) {
                EXPECT_EQ(0.0, matrix->getElement(i, j));
            }
        }
    }

    /*
     * Tests whether the getElement method throws an exception correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, GetElementExceptionTest) {
        EXPECT_THROW(matrix->getElement(-1, 0), OutOfBoundsException);
        EXPECT_THROW(matrix->getElement(noRows, 0), OutOfBoundsException);
        EXPECT_THROW(matrix->getElement(0, -1), OutOfBoundsException);
        EXPECT_THROW(matrix->getElement(0, noColumns), OutOfBoundsException);
    }

    /*
     * Tests whether the setElement method works correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, SetElementTest) {
        double x = 0.123456789;
        matrix->setElement(0, 0, x);
        EXPECT_EQ(x, matrix->getElement(0, 0));
    }

    /*
     * Tests whether the setElement method throws an exception correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, SetElementExceptionTest) {
        double x = 0.123456789;
        EXPECT_THROW(matrix->setElement(-1, 0, x), OutOfBoundsException);
        EXPECT_THROW(matrix->setElement(noRows, 0, x), OutOfBoundsException);
        EXPECT_THROW(matrix->setElement(0, -1, x), OutOfBoundsException);
        EXPECT_THROW(matrix->setElement(0, noColumns, x), OutOfBoundsException);
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(ProbabilityMatrixTest, CopyTest) {
        double x = 0.123456789;
        double y = x + 1;
        matrix->setElement(0, 0, x);
        matrix->setElement(noRows - 1, noColumns - 1, y);
        ProbabilityMatrix copy = (*matrix);
        EXPECT_EQ(noRows, copy.getNoRows());
        EXPECT_EQ(noColumns, copy.getNoColumns());
        EXPECT_EQ(x, copy.getElement(0, 0));
        EXPECT_EQ(y, copy.getElement(noRows - 1, noColumns - 1));
        for (int i = 0; i < noRows; i++) {
            for (int j = 0; j < noColumns; j++) {
                if (!((0 == i && 0 == j)
                        || ((noRows - 1) == i && (noColumns - 1) == j))) {
                    EXPECT_EQ(0.0, copy.getElement(i, j));
                }
            }
        }
    }
}
