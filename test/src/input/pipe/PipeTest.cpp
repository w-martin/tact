/**
 * @file PipeTest.cpp
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

#define testWord "testWord"

#include "gtest/gtest.h"
#include "mewt/input/pipe/Pipe.h"
#include "mewt/input/pipe/MockPipe.h"

using std::auto_ptr;

namespace {

    /**
     * Tests Pipe.
     * 
     */
    class PipeTest : public ::testing::Test {
    protected:

        PipeTest() {
            pipe = new MockPipe();
        }

        virtual ~PipeTest() {
            delete pipe;
        }
        Pipe * pipe;
    };

    /*
     * Tests whether the attachPipe method works correctly.
     * 
     */
    TEST_F(PipeTest, AttachPipeTest) {
        EXPECT_EQ(NULL, pipe->getNextPipe());
        
        Pipe * pipe1 = new Pipe();
        Pipe * pipe2 = new Pipe();
        pipe->attachPipe(auto_ptr< Pipe > (pipe1));
        pipe->attachPipe(auto_ptr< Pipe > (pipe2));
        EXPECT_EQ(pipe1, pipe->getNextPipe());
        EXPECT_EQ(pipe2, pipe1->getNextPipe());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(PipeTest, CopyConstructorTest) {
        Pipe * tmp = new Pipe(*pipe);
        delete tmp;
    }
}
