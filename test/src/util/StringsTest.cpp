/**
 * @file StringsTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 * 
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"
#include "teflon/util/Strings.h"

using namespace teflon::util::strings;

namespace {

    /**
     * Tests Strings.
     * 
     */
    class StringsTest : public ::testing::Test {
    protected:

        StringsTest() {
        }

        virtual ~StringsTest() {
        }
    };

};

/*
 * Tests whether the contains function works correctly.
 * 
 */
TEST_F(StringsTest, ContainsTest) {
    string const big = "hello WORLD";
    EXPECT_TRUE(contains(big, "hello", false));
    EXPECT_TRUE(contains(big, "hello", true));
    EXPECT_TRUE(contains(big, "hello"));
    EXPECT_TRUE(contains(big, "HELLO", false));
    EXPECT_FALSE(contains(big, "HELLO", true));
    EXPECT_FALSE(contains(big, "HELLO"));

    EXPECT_TRUE(contains(big, "hello WORLD", false));
    EXPECT_TRUE(contains(big, "hello WORLD", true));
    EXPECT_TRUE(contains(big, "hello WORLD"));
    EXPECT_FALSE(contains(big, "HELLO world", true));
    EXPECT_FALSE(contains(big, "HELLO world"));
    EXPECT_TRUE(contains(big, "HELLO world", false));

    EXPECT_FALSE(contains(big, "z", true));
    EXPECT_FALSE(contains(big, "z"));
    EXPECT_FALSE(contains(big, "z", false));
}

/*
 * Tests whether the constainsPunctuation function work correctly.
 * 
 */
TEST_F(StringsTest, ConstainsPunctuationTest) {
    EXPECT_TRUE(containsPunctuation("hello,world"));
    EXPECT_TRUE(containsPunctuation("hellowor!ld"));
    EXPECT_TRUE(containsPunctuation("he'lloworld"));
    EXPECT_TRUE(containsPunctuation("hello;worl/\\d"));
    EXPECT_TRUE(containsPunctuation("hello)world"));
    EXPECT_TRUE(containsPunctuation("(helloworld"));
    EXPECT_TRUE(containsPunctuation("hello world"));
    EXPECT_TRUE(containsPunctuation("({hello&£$%^world\\/()})"));
    EXPECT_FALSE(containsPunctuation("helloworld"));
    EXPECT_FALSE(containsPunctuation(""));
    EXPECT_FALSE(containsPunctuation("9"));
}

/*
 * Tests whether the containsUpper function works correctly.
 * 
 */
TEST_F(StringsTest, ContainsUpperTest) {
    string const upper = "has One upper case character";
    string const lower = "has no upper case characters";
    EXPECT_TRUE(containsUpper(upper));
    EXPECT_FALSE(containsUpper(lower));
}

/*
 * Tests whether the matches function works correctly.
 * 
 */
TEST_F(StringsTest, MatchesTest) {
    string const hello = "helLo";
    string const world = "!world!!";
    EXPECT_TRUE(matches(hello, "h.*"));
    EXPECT_TRUE(matches(hello, ".*\\w+.*"));
    EXPECT_FALSE(matches(hello, "hello"));
    EXPECT_FALSE(matches(hello, ".*\\W+.*"));
    EXPECT_TRUE(matches(world, ".*\\w+.*"));
    EXPECT_TRUE(matches(world, ".*\\W+.*"));
}

/*
 * Tests whether the replace function works correctly.
 * 
 */
TEST_F(StringsTest, ReplaceTest) {
    EXPECT_STREQ("hllo", replace("hello", "e", "").c_str());
    EXPECT_STREQ("helloworld", replace("hello world", "\\s", "").c_str());
    EXPECT_STREQ("hello woRLD",
            replace("h'e''ll,.£$%^&*(o\\ woRLD", "[^\\w\\s]", "").c_str());
    EXPECT_STREQ("hello world", replace("hello-world", "\\W", " ").c_str());
}

/*
 * Tests whether the split on whitespace function works correctly.
 * 
 */
TEST_F(StringsTest, SplitWhitespaceTest) {
    string text = " this is my text. .";
    auto_ptr< vector < string > > strings = split(text);
    EXPECT_EQ(5, strings->size());

    text = "this is some text";
    strings = split(text);
    EXPECT_EQ(4, strings->size());
    EXPECT_STREQ("this", strings->at(0).c_str());
    EXPECT_STREQ("is", strings->at(1).c_str());
    EXPECT_STREQ("some", strings->at(2).c_str());
    EXPECT_STREQ("text", strings->at(3).c_str());
}

/*
 * Tests whether the split on delimiter function works correctly.
 * 
 */
TEST_F(StringsTest, SplitTest) {
    string text = "000000s0o0m0e0 te0x0t0";
    auto_ptr< vector < string > > strings = split(text, "0");
    EXPECT_EQ(7, strings->size());
}

/*
 * Tests whether the splitLines function works correctly.
 * 
 */
TEST_F(StringsTest, SplitLinesTest) {
    EXPECT_EQ(0, splitLines("\n\n\n\n\n\n\n\n\n\n\n")->size());
    EXPECT_EQ(2, splitLines("hello\n\n\n\n\nworld\n\n\n\n\n\n")->size());
    EXPECT_EQ(5, splitLines("1\n2\n3\n4\n5")->size());
}

/*
 * Tests whether the toInteger function works correctly.
 * 
 */
TEST_F(StringsTest, ToIntegerTest) {
    EXPECT_EQ(1534, toInteger("1534"));
    EXPECT_THROW(toInteger("15hello0"), BadCastException);
}

/*
 * Tests whether the toLower function works correctly.
 * 
 */
TEST_F(StringsTest, ToLowerTest) {
    string const upper = "has One upper case character";
    EXPECT_TRUE(containsUpper(upper));
    string const lower = transformToLower(upper);
    EXPECT_FALSE(containsUpper(lower));
}
