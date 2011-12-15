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

#define testWord "1"

#include "gtest/gtest.h"
#include "tmte-cpp/output/Identifier.h"

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
     * Tests whether the less than operator works correctly.
     * 
     */
    TEST_F(IdentifierTest, LessThanOperatorTest) {
        Identifier different("0");
        EXPECT_TRUE(different < (*identifier));
        EXPECT_FALSE((*identifier) < (*identifier));
    }

    /*
     * Tests whether the not equal to operator works correctly.
     * 
     */
    TEST_F(IdentifierTest, NotEqualToOperatorTest) {
        Identifier different("0");
        EXPECT_TRUE(different != (*identifier));
        EXPECT_FALSE((*identifier) != (*identifier));
    }

    /*
     * Tests whether the equal to operator works correctly.
     * 
     */
    TEST_F(IdentifierTest, EqualToOperatorTest) {
        Identifier different("0");
        EXPECT_FALSE(different == (*identifier));
        EXPECT_TRUE((*identifier) == (*identifier));
    }

    /*
     * Tests whether the equals method works correctly.
     * 
     */
    TEST_F(IdentifierTest, EqualsTest) {
        Identifier const same(testWord);
        Identifier const different("different");
        EXPECT_TRUE(identifier->equals(same));
        EXPECT_FALSE(identifier->equals(different));
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
