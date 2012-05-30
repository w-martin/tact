/**
 * @file TextDocumentTest.cpp
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

#include "gtest/gtest.h"
#include "mewt/input/corpus/text/TextDocument.h"

namespace {

    /**
     * Tests TextDocument.
     * 
     */
    class TextDocumentTest : public ::testing::Test {
    protected:

        TextDocumentTest() {
            name = "test name";
            text = "this is\nsome text!\t\n\t";
            document = new TextDocument(
                    name, auto_ptr< string > (new string(text)));
        }

        virtual ~TextDocumentTest() {
            delete document;
        }
        TextDocument * document;
        string name;
        string text;
    };

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(TextDocumentTest, GetNameTest) {
        EXPECT_EQ(0, strcmp(name.c_str(), document->getName().c_str()));
    }

    /*
     * Tests whether the getText method works correctly.
     * 
     */
    TEST_F(TextDocumentTest, GetTextTest) {
        EXPECT_EQ(0, strcmp(text.c_str(), document->getText()->c_str()));
    }

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(TextDocumentTest, GetTypeTest) {
        EXPECT_EQ(DOCUMENT_TYPE_TEXT, document->getType());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(TextDocumentTest, CopyConstructorTest) {
        TextDocument tmp(*document);
        EXPECT_EQ(0, strcmp(name.c_str(), tmp.getName().c_str()));
        EXPECT_EQ(0, strcmp(text.c_str(), tmp.getText()->c_str()));
    }
}
