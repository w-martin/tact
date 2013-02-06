/**
 * @file LDATest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
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
#include "mewt/algorithm/LDA.h"
#include "mewt/input/corpus/feature/MockFeatureCorpus.h"
#include "mewt/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
using mewt::algorithm::LDA;

namespace {

    /**
     * Tests LDA.
     * 
     */
    class LDATest : public ::testing::Test {
    protected:

        LDATest() {
            alpha = 0.56;
            beta = 0.65;
            noTopics = 23;
            lda = new LDA(alpha, beta,
                    auto_ptr< Corpus > (new MockFeatureCorpus()), noTopics);
        }

        virtual ~LDATest() {
            delete lda;
        }
        LDA * lda;
        double alpha, beta;
        int noTopics;
    };

    /*
     * Tests whether the estimate method works correctly.
     * 
     */
    TEST_F(LDATest, EstimateTest) {
        int const noIterations = 53;
        string const outputDirectory = ".EstimateTest";
        int const saveInterval = 10;
        lda->estimate(noIterations, outputDirectory, saveInterval);
        EXPECT_EQ(noIterations, lda->getNoIterationsCompleted());
        fs::remove_all(outputDirectory);
    }

    /*
     * Tests whether the estimate method works correctly.
     * 
     */
    TEST_F(LDATest, NonTrivialTest) {
        int const noIterations = 53;
        string const outputDirectory = ".NonTrivialTest";
        int const saveInterval = 10;
        
        delete lda;
        auto_ptr< Corpus > corpus = auto_ptr< Corpus >(
                new Corpus("../include", DOCUMENT_TYPE_BASIC));
        corpus = ScanInputOptimiseBundle().pipe(corpus);
        lda = new LDA(alpha, beta, corpus, noTopics);
        
        lda->estimate(noIterations, outputDirectory, saveInterval);
        EXPECT_EQ(noIterations, lda->getNoIterationsCompleted());
        fs::remove_all(outputDirectory);
    }
}
