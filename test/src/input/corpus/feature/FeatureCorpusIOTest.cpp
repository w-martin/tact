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
#include <sstream>
#include <boost/filesystem.hpp>

using std::stringstream;

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
            fd1 = new FeatureDocument(doc1, fm);
            fm = auto_ptr< FeatureMap > (new FeatureMap());
            fm->incrementFeature(index1, 10);
            fm->incrementFeature(index2, 1);
            doc2 = location + "doc2";
            fd2 = new FeatureDocument(doc2, fm);
            corpus->addDocument(auto_ptr< Document > (fd1));
            corpus->addDocument(auto_ptr< Document > (fd2));
        }

        virtual ~FeatureCorpusIOTest() {
            FeatureCorpusIO::clearCache();
            delete corpus;
            delete fd1;
            delete fd2;
        }
        FeatureCorpus * corpus;
        FeatureDocument * fd1, * fd2;
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
     * Tests whether the save and load methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, IOTest) {
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(FeatureCorpusIO::load(location)->equals(*corpus));

        corpus->removeDocument(fd1);
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(FeatureCorpusIO::load(location)->equals(*corpus));
    }

    /*
     * Tests whether the createDirectory method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, CreateDirectoryTest) {
        string const directory = string(IO_CACHE);
        EXPECT_FALSE(fs::exists(directory));
        EXPECT_FALSE(fs::exists(directory + "0"));
        EXPECT_FALSE(fs::exists(directory + "00"));
        EXPECT_FALSE(fs::is_directory(directory + "00"));

        FeatureCorpusIO::util::createDirectory(directory, 0);
        EXPECT_TRUE(fs::exists(directory));
        EXPECT_FALSE(fs::exists(directory + "0"));
        EXPECT_TRUE(fs::exists(directory + "00"));
        EXPECT_TRUE(fs::is_directory(directory + "00"));

        EXPECT_FALSE(fs::exists(directory + "27"));
        EXPECT_FALSE(fs::is_directory(directory + "27"));
        FeatureCorpusIO::util::createDirectory(directory, 27);
        EXPECT_TRUE(fs::exists(directory + "27"));
        EXPECT_TRUE(fs::is_directory(directory + "27"));
    }

    /*
     * Tests whether the findNextFreeDirectory method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, FindNextFreeDirectoryTest) {
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "00"));
        FeatureCorpusIO::save(corpus);
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "00"));
        EXPECT_FALSE(fs::exists(string(IO_CACHE) + "01"));

        stringstream name;
        name << location;
        for (int i = 1; i < 11; i++) {
            name << i;
            FeatureCorpusIO::save(
                    FeatureCorpus::createInstance(name.str()).get());
        }
        EXPECT_TRUE(fs::exists(string(IO_CACHE) + "10"));
    }

    /*
     * Tests whether the findSavedCorpus method works correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, FindSavedCorpusTest) {
        EXPECT_THROW(FeatureCorpusIO::util::findSavedCorpus(location),
                CorpusNotFoundException);

        FeatureCorpusIO::save(corpus);
        EXPECT_EQ(string(IO_CACHE) + "00",
                FeatureCorpusIO::util::findSavedCorpus(location));
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
     * Tests whether an exception is thrown by the loadAlphabet method 
     * correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, LoadDocumentExceptionTest) {
        string const documentFolder = string(IO_CACHE)
                + IO_CORPUS_DOCUMENTS + "00/";
        fs::create_directories(documentFolder);
        string const documentLocation = documentFolder + "00";
        Alphabet * const alphabet = corpus->getAlphabet();
        EXPECT_THROW(
                FeatureCorpusIO::util::loadDocument(documentLocation, alphabet),
                FileNotFoundException);

        FeatureCorpusIO::util::saveDocument(documentFolder, 0, fd1);
        alphabet->removeTerm(term1);
        EXPECT_THROW(
                FeatureCorpusIO::util::loadDocument(documentLocation, alphabet),
                TermNotPresentException);
    }

    /*
     * Tests whether the save and load Document methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, DocumentIOTest) {
        string const documentFolder = string(IO_CACHE)
                + IO_CORPUS_DOCUMENTS + "00/";
        fs::create_directories(documentFolder);
        string const documentLocation = documentFolder + "00";
        Alphabet * const alphabet = corpus->getAlphabet();

        FeatureCorpusIO::util::saveDocument(documentFolder, 0, fd1);
        EXPECT_EQ(*fd1, * FeatureCorpusIO::util::loadDocument(
                documentLocation, alphabet).get());
    }

    /*
     * Tests whether the save and load Documents methods work correctly.
     * 
     */
    TEST_F(FeatureCorpusIOTest, DocumentsIOTest) {
        string const documentFolder = string(IO_CACHE)
                + IO_CORPUS_DOCUMENTS + "00/";
        fs::create_directories(documentFolder);
        Alphabet const * const alphabet = corpus->getAlphabet();
        vector< Document * > const * const documents = corpus->getDocuments();

        FeatureCorpusIO::util::saveDocuments(documentFolder, documents);
        FeatureCorpus * const tmp = new FeatureCorpus(location,
                auto_ptr< Alphabet > (new Alphabet(*alphabet)));
        EXPECT_NE(*tmp, *corpus);

        FeatureCorpusIO::util::loadDocuments(documentFolder,
                tmp->getAlphabet(), tmp);
        EXPECT_EQ(*tmp, *corpus);
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
}
