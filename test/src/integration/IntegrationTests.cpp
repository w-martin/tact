/**
 * @file IntegrationTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.4
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
#include "teflon/algorithm/LDA.h"
#include "teflon/input/corpus/feature/MockFeatureCorpus.h"
#include "teflon/input/pipe/bundle/ScanInputOptimiseBundle.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace {

    /**
     * Integration Tests.
     * 
     */
    class IntegrationTest : public ::testing::Test {
    protected:

        IntegrationTest() {
            alpha = 0.56;
            beta = 0.65;
            noTopics = 23;
            lda = new LDA(alpha, beta,
                    auto_ptr< Corpus > (new MockFeatureCorpus()), noTopics);
        }

        virtual ~IntegrationTest() {
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
    TEST_F(IntegrationTest, LDATest) {
        int const noIterations = 53;
        string const outputDirectory = ".LDATest";
        int const saveInterval = 10;
        
        delete lda;
        auto_ptr< Corpus > corpus = auto_ptr< Corpus >(
                new Corpus("../sample", DOCUMENT_TYPE_BASIC));
        corpus = ScanInputOptimiseBundle().pipe(corpus);
        lda = new LDA(alpha, beta, corpus, noTopics);
        
        lda->estimate(noIterations, outputDirectory, saveInterval);
        EXPECT_EQ(noIterations, lda->getNoIterationsCompleted());
        fs::remove_all(outputDirectory);
    }
}
