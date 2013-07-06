/**
 * @file FilesTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.3
 *
 * @section LICENSE
 *
 * This file is part of tact.
 *
 * tact is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tact is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tact.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <boost/filesystem.hpp>
#include "gtest/gtest.h"
#include "tact/util/Files.h"

using namespace tact::util::files;

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

/*
 * Tests whether the appendFile method works correctly.
 *
 */
TEST_F(FilesTest, AppendFileTest) {
  string testMessage = "test message";
  std::stringstream stream;
  stream << testMessage << std::endl;
  string expectedMessage = stream.str();
  stream.str(string());

  string filename = "FilesTest.AppendFileTest";
  boost::filesystem::remove(filename);

  appendFile(testMessage, filename);
  EXPECT_TRUE(boost::filesystem::exists(filename));
  EXPECT_STREQ(expectedMessage.c_str(), readFile(filename)->c_str());

  appendFile(testMessage, filename);
  EXPECT_STREQ(expectedMessage.append(expectedMessage).c_str(),
               readFile(filename)->c_str());
  boost::filesystem::remove(filename);
}
