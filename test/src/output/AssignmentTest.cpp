/**
 * @file AssignmentTest.cpp
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
#include "tmte-cpp/output/Assignment.h"

namespace {

    /**
     * Tests Assignment.
     * 
     */
    class AssignmentTest : public ::testing::Test {
    protected:

        AssignmentTest() {
            assignment = new Assignment();
            key = new Identifier(testWord);
            value = 80.7;
        }

        virtual ~AssignmentTest() {
            delete assignment;
            delete key;
        }
        Assignment * assignment;
        Identifier * key;
        double value;
    };

    /*
     * Tests whether the add method works correctly.
     * 
     */
    TEST_F(AssignmentTest, AddTest) {
        EXPECT_EQ(0, assignment->getSize());
        EXPECT_TRUE(assignment->add((*key), value));
        EXPECT_FALSE(assignment->add((*key), value));
        EXPECT_EQ(1, assignment->getSize());
    }

    /*
     * Tests whether the contains method works correctly.
     * 
     */
    TEST_F(AssignmentTest, ContainsTest) {
        EXPECT_FALSE(assignment->contains((*key)));
        assignment->add((*key), value);
        EXPECT_TRUE(assignment->contains((*key)));
    }

    /*
     * Tests whether the get method works correctly.
     * 
     */
    TEST_F(AssignmentTest, GetTest) {
        EXPECT_THROW(assignment->get((*key)), ElementNotPresentException);
        assignment->add((*key), value);
        EXPECT_EQ(value, assignment->get((*key)));
    }

    /*
     * Tests whether the get key method works correctly.
     * 
     */
    TEST_F(AssignmentTest, GetKeyTest) {
        EXPECT_THROW(assignment->getKey(0), OutOfBoundsException);
        assignment->add((*key), value);
        EXPECT_STREQ(testWord, assignment->getKey(0).getName().c_str());
        EXPECT_THROW(assignment->getKey(1), OutOfBoundsException);
        Identifier secondKey("2");
        assignment->add(secondKey, value);
        EXPECT_STREQ("2", assignment->getKey(1).getName().c_str());
        EXPECT_THROW(assignment->getKey(2), OutOfBoundsException);
    }

    /*
     * Tests whether the getSize method works correctly.
     * 
     */
    TEST_F(AssignmentTest, GetSizeTest) {
        EXPECT_EQ(0, assignment->getSize());
        assignment->add((*key), value);
        EXPECT_EQ(1, assignment->getSize());
        Identifier secondKey("2");
        assignment->add(secondKey, value);
        EXPECT_EQ(2, assignment->getSize());
    }

    /*
     * Tests whether the remove method works correctly.
     * 
     */
    TEST_F(AssignmentTest, RemoveTest) {
        EXPECT_THROW(assignment->remove((*key)), ElementNotPresentException);
        assignment->add((*key), value);
        EXPECT_EQ(1, assignment->getSize());
        EXPECT_EQ(value, assignment->remove((*key)));
        EXPECT_EQ(0, assignment->getSize());
        EXPECT_THROW(assignment->remove((*key)), ElementNotPresentException);
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(AssignmentTest, CopyConstructorTest) {
        assignment->add((*key), value);
        Assignment copy(*assignment);
        EXPECT_EQ(1, copy.getSize());
        EXPECT_EQ(value, copy.get((*key)));
        EXPECT_STREQ(testWord, copy.getKey(0).getName().c_str());
        EXPECT_EQ(value, copy.remove((*key)));
        EXPECT_EQ(0, copy.getSize());
    }
}
