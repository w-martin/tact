#
# CMake build script for mewt.
#
########################################################################
#                                                                      #
# This file is part of mewt.                                           #
#                                                                      #
# mewt is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by #
# the Free Software Foundation, either version 3 of the License, or    #
# (at your option) any later version.                                  #
#                                                                      #
# mewt is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of       #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        #
# GNU General Public License for more details.                         #
#                                                                      #
# You should have received a copy of the GNU General Public License    #
# along with mewt.  If not, see <http://www.gnu.org/licenses/>.        #
#                                                                      #
########################################################################
#

cmake_minimum_required (VERSION 2.6.2)

########
# Main #
########

project (mewt)

OPTION(TESTING "Build tests." ON)

set(MEWT_NAME mewt)
set(MEWT_UTIL mewt-util)
set(MEWT_INPUT mewt-input)
set(MEWT_OUTPUT mewt-output)
set(MEWT_MODEL mewt-model)
set(MEWT_ALGORITHM mewt-algorithm)
set(MEWT_SOURCE_DIR src)
set(MEWT_INCLUDE_DIR include)
set(MEWT_TEST_DIR test/src)
set(MEWT_MOCK_DIR test/mock)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS regex filesystem system REQUIRED)

include_directories(
    ${MEWT_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
)

# list all source files here
# TODO: replace this with a macro

add_library (${MEWT_UTIL}
    ${MEWT_SOURCE_DIR}/util/Files.cpp
    ${MEWT_SOURCE_DIR}/util/Strings.cpp
    ${MEWT_SOURCE_DIR}/util/exceptions/BadCastException.cpp
    ${MEWT_SOURCE_DIR}/util/exceptions/DuplicateException.cpp
    ${MEWT_SOURCE_DIR}/util/exceptions/Exception.cpp
    ${MEWT_SOURCE_DIR}/util/exceptions/FileNotFoundException.cpp
    ${MEWT_SOURCE_DIR}/util/exceptions/OutOfBoundsException.cpp
    )

target_link_libraries (${MEWT_UTIL}
    ${Boost_REGEX_LIBRARY}
    )

add_library (${MEWT_INPUT}
    ${MEWT_SOURCE_DIR}/input/corpus/Corpus.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/Document.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/Alphabet.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/AlphabetIterator.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/FeatureCorpus.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/FeatureCorpusIO.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/FeatureDocument.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/FeatureMap.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/feature/FeatureMapIterator.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/text/TextCorpus.cpp
    ${MEWT_SOURCE_DIR}/input/corpus/text/TextDocument.cpp
    ${MEWT_SOURCE_DIR}/input/exceptions/CorpusNotFoundException.cpp
    ${MEWT_SOURCE_DIR}/input/exceptions/IncompatibleCorpusException.cpp
    ${MEWT_SOURCE_DIR}/input/exceptions/TermNotPresentException.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/bundle/CompleteFilteredBundle.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/bundle/InputOptimiseBundle.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/bundle/ScanInputOptimiseBundle.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/DirectoryScannerPipe.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/FeatureMapPipe.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/InputPipe.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/LengthFilter.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/LowerCasePipe.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/Pipe.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/PunctuationFilter.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/StopwordFilter.cpp
    ${MEWT_SOURCE_DIR}/input/pipe/XmlFilter.cpp
    )

target_link_libraries (${MEWT_INPUT}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    )

add_library (${MEWT_OUTPUT}
    ${MEWT_SOURCE_DIR}/output/Identifier.cpp
    )

add_library (${MEWT_MODEL}
    ${MEWT_SOURCE_DIR}/model/ProbabilityMatrix.cpp
    ${MEWT_SOURCE_DIR}/model/TopicModel.cpp
    )

add_library (${MEWT_ALGORITHM}
    ${MEWT_SOURCE_DIR}/algorithm/RandomNumberGenerator.cpp
    )

#find_package(Threads REQUIRED)

add_executable (${MEWT_NAME}
    ${MEWT_SOURCE_DIR}/main.cpp)
target_link_libraries(${MEWT_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    ${MEWT_UTIL}
    ${MEWT_INPUT}
    ${MEWT_OUTPUT}
    ${MEWT_MODEL}
    ${MEWT_ALGORITHM})

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################

IF(TESTING)

    add_subdirectory(gmock-1.6.0)
    enable_testing(true) 

    include_directories(
        ${gtest_SOURCE_DIR}/include 
        ${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include 
        ${gmock_SOURCE_DIR}
        ${MEWT_MOCK_DIR}
    )

    # list test definitions here
    # TODO: replace this with a macro

    add_executable(UtilTests
        ${MEWT_TEST_DIR}/util/FilesTest.cpp
        ${MEWT_TEST_DIR}/util/StringsTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/BadCastExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/DuplicateExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/FileNotFoundExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
    ) 
    target_link_libraries(UtilTests gmock gmock_main
        ${MEWT_UTIL}) 
    add_test(UtilTests UtilTests)

    add_executable(InputTests
        ${MEWT_TEST_DIR}/input/corpus/CorpusTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/DocumentTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/AlphabetTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/AlphabetIteratorTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/FeatureCorpusIOTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/FeatureCorpusTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/FeatureDocumentTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/FeatureMapIteratorTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/feature/FeatureMapTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/text/TextCorpusTest.cpp
        ${MEWT_TEST_DIR}/input/corpus/text/TextDocumentTest.cpp
        ${MEWT_TEST_DIR}/input/exceptions/CorpusNotFoundExceptionTest.cpp
        ${MEWT_TEST_DIR}/input/exceptions/IncompatibleCorpusExceptionTest.cpp
        ${MEWT_TEST_DIR}/input/exceptions/TermNotPresentExceptionTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/bundle/CompleteFilteredBundleTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/bundle/InputOptimiseBundleTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/bundle/ScanInputOptimiseBundleTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/DirectoryScannerPipeTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/FeatureMapPipeTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/InputPipeTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/LengthFilterTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/LowerCasePipeTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/PipeTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/PunctuationFilterTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/StopwordFilterTest.cpp
        ${MEWT_TEST_DIR}/input/pipe/XmlFilterTest.cpp
    ) 
    target_link_libraries(InputTests gmock gmock_main
        ${MEWT_UTIL}
        ${MEWT_INPUT})
    add_test(InputTests InputTests)

    add_executable(OutputTests
        ${MEWT_TEST_DIR}/output/IdentifierTest.cpp
    ) 
    target_link_libraries(OutputTests gmock gmock_main
        ${MEWT_UTIL}
        ${MEWT_INPUT}
        ${MEWT_OUTPUT})
    add_test(OutputTests OutputTests)

    add_executable(ModelTests
        ${MEWT_TEST_DIR}/model/ProbabilityMatrixTest.cpp
        ${MEWT_TEST_DIR}/model/TopicModelTest.cpp
    ) 
    target_link_libraries(ModelTests gmock gmock_main
        ${MEWT_UTIL}
        ${MEWT_OUTPUT}
        ${MEWT_MODEL})
    add_test(ModelTests ModelTests)

    add_executable(AlgorithmTests
        ${MEWT_TEST_DIR}/algorithm/RandomNumberGeneratorTest.cpp
    ) 
    target_link_libraries(AlgorithmTests gmock gmock_main
        ${MEWT_UTIL}
        ${MEWT_INPUT}
        ${MEWT_OUTPUT}
        ${MEWT_MODEL}
        ${MEWT_ALGORITHM})
    add_test(AlgorithmTests AlgorithmTests)

ENDIF(TESTING)
