/**
 * @file FilesTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
 *
 * @section LICENSE
 *
 * This file is part of mewt.
 * 
 * mewt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mewt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mewt.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "mewt/util/Files.h"

using namespace mewt::util::files;

namespace {

    /**
     * Tests Files.
     * 
     */
    class FilesTest : public ::testing::Test {
    protected:

        FilesTest() {
        }

        virtual ~FilesTest() {
        }
    };

};

/*
 * Tests whether the readFile method works correctly.
 * 
 */
TEST_F(FilesTest, ReadFileTest) {
    auto_ptr< string > text = readFile("CMakeCache.txt");
    EXPECT_GT(text->size(), 0);
}
