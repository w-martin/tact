/**
 * @file InputPipeTest.cpp
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
 */

#define testWord "testWord"

#include "gtest/gtest.h"
#include "mewt/input/corpus/text/TextDocument.h"
#include "mewt/input/pipe/InputPipe.h"

namespace {

    /**
     * Tests InputPipe.
     * 
     */
    class InputPipeTest : public ::testing::Test {
    protected:

        InputPipeTest() {
            pipe = new InputPipe();
        }

        virtual ~InputPipeTest() {
            delete pipe;
        }
        InputPipe * pipe;
    };

    /*
     * Tests whether the computeFileName method works correctly.
     * 
     */
    TEST_F(InputPipeTest, ComputeFileNameTest) {
        string const filename =
                InputPipe::computeFileName(".", "CMakeCache.txt");
        EXPECT_STREQ("./CMakeCache.txt", filename.c_str());
    }

    /*
     * Tests whether the process method works correctly.
     * 
     */
    TEST_F(InputPipeTest, ProcessTest) {
        auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                new Corpus(".", DOCUMENT_TYPE_BASIC));
        corpus->addDocument(
                auto_ptr< Document > (new Document("CMakeCache.txt")));
        auto_ptr< Corpus > textCorpus = pipe->pipe(corpus);

        TextDocument const * const onlyDocument =
                (TextDocument const * const) textCorpus->getDocuments()->at(0);
        EXPECT_GT(onlyDocument->getText()->size(), 0);
    }

    /*
     * Tests whether the readFileIntoString method works correctly.
     * 
     */
    TEST_F(InputPipeTest, ReadFileIntoStringTest) {
        auto_ptr< string > text =
                InputPipe::readFileIntoString("CMakeCache.txt");
        EXPECT_GT(text->size(), 0);
    }

    /*
     * Tests whether the getDocumentTypes method works correctly.
     * 
     */
    TEST_F(InputPipeTest, GetDocumentTypesTest) {
        vector< int > const * compatibleTypes = pipe->getCompatibleTypes();
        EXPECT_EQ(0, compatibleTypes->size());
    }
}
