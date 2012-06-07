/**
 * @file StopwordFilterTest.cpp
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

#include "mewt/input/corpus/feature/FeatureCorpus.h"


#include "gtest/gtest.h"
#include "mewt/input/pipe/StopwordFilter.h"
#include "mewt/input/corpus/feature/Alphabet.h"
#include "mewt/input/corpus/text/TextCorpus.h"
#include "mewt/input/pipe/FeatureMapPipe.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

    /**
     * Tests StopwordFilter.
     * 
     */
    class StopwordFilterTest : public ::testing::Test {
    protected:

        StopwordFilterTest() {
            alphabet = new Alphabet();
            alphabet->addTerm("hello");
            pipe = new StopwordFilter(alphabet);
        }

        virtual ~StopwordFilterTest() {
            delete pipe;
            delete alphabet;
        }
        StopwordFilter * pipe;
        Alphabet * alphabet;
    };

    /*
     * Tests whether the file constructor works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, FileConstructorTest) {
        delete pipe;
        pipe = new StopwordFilter("CTestTestfile.cmake");

        Alphabet const * const stopwords = pipe->getStopwords();
        EXPECT_LT(0, stopwords->getSize());
    }

    /*
     * Tests whether the directory constructor works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, DirectoryConstructorTest) {
        fs::create_directories(".stopwordFilterTest/dir");
        fs::copy_file("CMakeCache.txt", ".stopwordFilterTest/file1");
        fs::copy_file("CTestTestfile.cmake", ".stopwordFilterTest/dir/file2");

        delete pipe;
        pipe = new StopwordFilter(".stopwordFilterTest", false);
        Alphabet const * stopwords = pipe->getStopwords();
        EXPECT_LT(0, stopwords->getSize());

        delete pipe;
        pipe = new StopwordFilter(".stopwordFilterTest", true);
        stopwords = pipe->getStopwords();
        EXPECT_LT(0, stopwords->getSize());

        fs::remove_all(".stopwordFilterTest");
    }

    /*
     * Tests whether the specific constructor works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, SpecificConstructorTest) {
        Alphabet const * const copiedAlphabet = pipe->getStopwords();
        EXPECT_EQ(alphabet->getSize(), copiedAlphabet->getSize());
        for (int i = 0; i < alphabet->getSize(); i++) {
            EXPECT_STREQ(alphabet->getTerms()->at(i).c_str(),
                    copiedAlphabet->getTerms()->at(i).c_str());
        }
    }

    /*
     * Tests whether the copy constructor works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, CopyConstructorTest) {
        StopwordFilter tmp(*pipe);
        Alphabet const * const copiedAlphabet = tmp.getStopwords();
        EXPECT_EQ(alphabet->getSize(), copiedAlphabet->getSize());
        for (int i = 0; i < alphabet->getSize(); i++) {
            EXPECT_STREQ(alphabet->getTerms()->at(i).c_str(),
                    copiedAlphabet->getTerms()->at(i).c_str());
        }
    }

    /*
     * Tests whether the getStopwords method works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, GetStopwordsTest) {
        Alphabet const * const stopwords = pipe->getStopwords();
        for (int i = 0; i < alphabet->getSize(); i++) {
            EXPECT_STREQ(alphabet->getTerms()->at(i).c_str(),
                    stopwords->getTerms()->at(i).c_str());
        }
    }

    /*
     * Tests whether the process method works correctly.
     * 
     */
    TEST_F(StopwordFilterTest, ProcessTest) {
        auto_ptr< Corpus > corpus = auto_ptr< Corpus > (new TextCorpus(""));
        auto_ptr< string > text =
                auto_ptr< string > (new string("hello world"));
        auto_ptr< Document > document = auto_ptr< Document > (
                new TextDocument("doc", text));
        corpus->addDocument(document);

        FeatureMapPipe featurePipe;
        corpus = featurePipe.pipe(corpus);
        Alphabet const * terms =
                ((FeatureCorpus *) corpus.get())->getAlphabet();
        EXPECT_EQ(2, terms->getSize());
        EXPECT_TRUE(terms->hasTerm("hello"));
        EXPECT_TRUE(terms->hasTerm("world"));

        corpus = pipe->pipe(corpus);
        EXPECT_EQ(1, terms->getSize());
        EXPECT_FALSE(terms->hasTerm("hello"));
        EXPECT_TRUE(terms->hasTerm("world"));
    }
}
