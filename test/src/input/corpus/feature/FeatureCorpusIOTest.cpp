/**
 * @file FeatureCorpusIOTest.cpp
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
#include "mewt/input/corpus/feature/FeatureCorpusIO.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

    /**
     * Tests FeatureCorpusIO.
     * 
     */
    class FeatureCorpusIOTest : public ::testing::Test {
    protected:

        FeatureCorpusIOTest() {
            location = "location";
            corpus = FeatureCorpus::createInstance(location).release();
            term1 = "hello";
            term2 = "world";
            index1 = corpus->getAlphabet()->addTerm(term1);
            index2 = corpus->getAlphabet()->addTerm(term2);
            auto_ptr< FeatureMap > fm =
                    auto_ptr< FeatureMap > (new FeatureMap());
            fm->incrementFeature(index1, 5);
            doc1 = location + "doc1";
            FeatureDocument * fd1 = new FeatureDocument(doc1, fm);
            fm = auto_ptr< FeatureMap > (new FeatureMap());
            fm->incrementFeature(index1, 10);
            fm->incrementFeature(index2, 1);
            doc2 = location + "doc2";
            FeatureDocument * fd2 = new FeatureDocument(doc2, fm);
            corpus->addDocument(auto_ptr< Document > (fd1));
            corpus->addDocument(auto_ptr< Document > (fd2));
        }

        virtual ~FeatureCorpusIOTest() {
            FeatureCorpusIO::clearCache();
            delete corpus;
        }
        FeatureCorpus * corpus;
        string location, term1, term2, doc1, doc2;
        int index1, index2;
    };

    /*
     * Tests whether the clearCache method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, ClearCacheTest) {
        string const dir = string(IO_CACHE) + ".ClearCacheTest/dir";
        string const file1 = string(IO_CACHE) + ".ClearCacheTest/dir/file1";
        fs::create_directories(dir);
        fs::copy_file("CTestTestfile.cmake", file1);

        EXPECT_TRUE(fs::exists(file1));
        EXPECT_TRUE(fs::exists(dir));
        FeatureCorpusIO::clearCache();
        EXPECT_FALSE(fs::exists(file1));
        EXPECT_FALSE(fs::exists(dir));
    }

    /*
     * Tests whether the deleteCorpus method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, DeleteCorpusTest) {
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "00"));
        FeatureCorpusIO::deleteCorpus(location);
        EXPECT_FALSE(fs::exists(string(IO_CACHE) + "00"));
    }

    /*
     * Tests whether an exception is thrown when the corpus is not present.
     * 
     */
    TEST_F(FeatureCorpusIOTest, CorpusNotPresentTest) {
        EXPECT_THROW(FeatureCorpusIO::load("test"), CorpusNotFoundException);
    }

    /*
     * Tests whether the findNextFreeDirectory method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, FindNextFreeDirectoryTest) {
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "00"));
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "01"));
        for (int i = 2; i < 11; i++) {
            FeatureCorpusIO::save(corpus);
        }
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "10"));
    }

    /*
     * Tests whether an exception is thrown by the loadAlphabet method 
     * correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, LoadAlphabetExceptionTest) {
        string const directory = string(IO_CACHE)
                + ".LoadAlphabetExceptionTest";
        EXPECT_THROW(FeatureCorpusIO::util::loadAlphabet(directory),
                FileNotFoundException);
        fs::create_directories(directory);
        EXPECT_THROW(FeatureCorpusIO::util::loadAlphabet(directory),
                FileNotFoundException);
    }

    /*
     * Tests whether the save and load Alphabet methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, AlphabetIOTest) {
        string const directory = string(IO_CACHE) + ".AlphabetIOTest";
        fs::create_directories(directory);
        FeatureCorpusIO::util::saveAlphabet(directory, corpus->getAlphabet());
        EXPECT_EQ(*corpus->getAlphabet(),
                FeatureCorpusIO::util::loadAlphabet(directory).get());
    }

    /*
     * Tests whether an exception is thrown by the loadName method correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, LoadNameExceptionTest) {
        string const directory = string(IO_CACHE) + ".LoadNameExceptionTest";
        EXPECT_THROW(FeatureCorpusIO::util::loadName(directory),
                FileNotFoundException);
        fs::create_directories(directory);
        EXPECT_THROW(FeatureCorpusIO::util::loadName(directory),
                FileNotFoundException);
    }

    /*
     * Tests whether the save and load name methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, NameIOTest) {
        string const directory = string(IO_CACHE) + ".NameIOTest";
        fs::create_directories(directory);
        FeatureCorpusIO::util::saveInfoFile(directory, corpus);
        EXPECT_EQ(location, FeatureCorpusIO::util::loadName(directory));
    }

    /*
     * Tests whether the save and load methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, IOTest) {
        string const directory = string(IO_CACHE) + ".NameIOTest";
        fs::create_directories(directory);
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(FeatureCorpusIO::load(location)->equals(*corpus));
    }
}
