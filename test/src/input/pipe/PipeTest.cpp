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
#include "mewt/input/corpus/feature/FeatureDocument.h"
#include "mewt/input/corpus/text/TextDocument.h"

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

        Pipe * pipe1 = new MockPipe();
        Pipe * pipe2 = new MockPipe();
        pipe->attachPipe(auto_ptr< Pipe > (pipe1));
        pipe->attachPipe(auto_ptr< Pipe > (pipe2));
        EXPECT_EQ(pipe1, pipe->getNextPipe());
        EXPECT_EQ(pipe2, pipe1->getNextPipe());
    }

    /*
     * Tests whether the getDocumentTypes method works correctly.
     * 
     */
    TEST_F(PipeTest, GetDocumentTypesTest) {
        vector< int > const * compatibleTypes = pipe->getCompatibleTypes();
        EXPECT_EQ(0, compatibleTypes->size());
        
        delete pipe;
        vector< int > types;
        types.push_back(DOCUMENT_TYPE_BASIC);
        types.push_back(DOCUMENT_TYPE_FEATURE);
        pipe = new MockPipe(types);
        compatibleTypes = pipe->getCompatibleTypes();
        EXPECT_EQ(2, compatibleTypes->size());
        EXPECT_EQ(DOCUMENT_TYPE_BASIC, compatibleTypes->at(0));
        EXPECT_EQ(DOCUMENT_TYPE_FEATURE, compatibleTypes->at(1));
        
        delete pipe;
        pipe = new MockPipe(DOCUMENT_TYPE_TEXT);
        compatibleTypes = pipe->getCompatibleTypes();
        EXPECT_EQ(1, compatibleTypes->size());
        EXPECT_EQ(DOCUMENT_TYPE_TEXT, compatibleTypes->at(0));
    }
}
