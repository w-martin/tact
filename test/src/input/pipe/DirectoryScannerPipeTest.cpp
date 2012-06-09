/**
 * @file DirectoryScannerPipeTest.cpp
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
#include "mewt/input/pipe/DirectoryScannerPipe.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

    /**
     * Tests DirectoryScannerPipe.
     * 
     */
    class DirectoryScannerPipeTest : public ::testing::Test {
    protected:

        DirectoryScannerPipeTest() {
            recursivePipe = new DirectoryScannerPipe(true);
            pipe = new DirectoryScannerPipe(false);
        }

        virtual ~DirectoryScannerPipeTest() {
            delete recursivePipe;
            delete pipe;
        }
        DirectoryScannerPipe * recursivePipe;
        DirectoryScannerPipe * pipe;
    };

    /*
     * Tests whether the process method works correctly.
     * 
     */
    TEST_F(DirectoryScannerPipeTest, ProcessTest) {
        string const file1 = ".processTest/file1";
        string const file2 = ".processTest/dir/file2";
        fs::create_directories(".processTest/dir");
        fs::copy_file("CMakeCache.txt", file1);
        fs::copy_file("CMakeCache.txt", file2);

        auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                new Corpus(".processTest", DOCUMENT_TYPE_BASIC));
        corpus = pipe->pipe(corpus);
        EXPECT_EQ(1, corpus->getSize());
        vector< Document * > const * documents = corpus->getDocuments();
        EXPECT_TRUE(file1 == documents->at(0)->getName());

        corpus = auto_ptr< Corpus > (
                new Corpus(".processTest", DOCUMENT_TYPE_BASIC));
        corpus = recursivePipe->pipe(corpus);
        EXPECT_EQ(2, corpus->getSize());
        documents = corpus->getDocuments();
        EXPECT_TRUE(file1 == documents->at(0)->getName()
                || file1 == documents->at(1)->getName());
        EXPECT_TRUE(file2 == documents->at(0)->getName()
                || file2 == documents->at(1)->getName());

        fs::remove_all(".processTest");
    }

    /*
     * Tests whether the isRecursive method works correctly.
     * 
     */
    TEST_F(DirectoryScannerPipeTest, IsRecursiveTest) {
        EXPECT_TRUE(recursivePipe->isRecursive());
        EXPECT_FALSE(pipe->isRecursive());
    }
}
