/**
 * @file IdentifierTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
 *
 * @section LICENSE
 *
 * This program is licensed under the MIT license, please see COPYING for a 
 * copy of the license.
 * 
 */

#define testWord "testWord"

#include "gtest/gtest.h"
#include "tmte-cpp/main/output/Identifier.h"

namespace {

    /**
     * Tests Identifier.
     * 
     */
    class IdentifierTest : public ::testing::Test {
    protected:

        IdentifierTest() {
            identifier = new Identifier(testWord);
        }

        virtual ~IdentifierTest() {
            delete identifier;
        }
        Identifier * identifier;
    };

    /*
     * Tests whether the getName method works correctly.
     * 
     */
    TEST_F(IdentifierTest, GetNameTest) {
        EXPECT_STREQ(testWord, identifier->getName().c_str());
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(IdentifierTest, CopyConstructorTest) {
        Identifier * tmp = new Identifier(*identifier);
        EXPECT_STREQ(testWord, tmp->getName().c_str());
        delete tmp;
    }
}
