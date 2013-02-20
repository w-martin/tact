#
# CMake build script for teflon.
#
########################################################################
#                                                                      #
# This file is part of teflon.                                           #
#                                                                      #
# teflon is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by #
# the Free Software Foundation, either version 3 of the License, or    #
# (at your option) any later version.                                  #
#                                                                      #
# teflon is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of       #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        #
# GNU General Public License for more details.                         #
#                                                                      #
# You should have received a copy of the GNU General Public License    #
# along with teflon.  If not, see <http://www.gnu.org/licenses/>.        #
#                                                                      #
########################################################################
#

cmake_minimum_required (VERSION 2.6.2)

########
# Main #
########

project (teflon)

set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(TEFLON_NAME teflon)
set(TEFLON_UTIL teflon-util)
set(TEFLON_LOGGER teflon-logger)
set(TEFLON_INPUT teflon-input)
set(TEFLON_OUTPUT teflon-output)
set(TEFLON_MODEL teflon-model)
set(TEFLON_ALGORITHM teflon-algorithm)
set(TEFLON_SOURCE_DIR src)
set(TEFLON_INCLUDE_DIR include)
set(TEFLON_TEST_DIR test/src)
set(TEFLON_MOCK_DIR test/mock)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS 
    regex
    date_time
    filesystem
    system
    thread
    REQUIRED)

include_directories(
    ${TEFLON_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
)

# list all source files here
# TODO: replace this with a macro

add_library (${TEFLON_UTIL}
    ${TEFLON_SOURCE_DIR}/util/Files.cpp
    ${TEFLON_SOURCE_DIR}/util/Strings.cpp
    ${TEFLON_SOURCE_DIR}/util/exceptions/BadCastException.cpp
    ${TEFLON_SOURCE_DIR}/util/exceptions/DuplicateException.cpp
    ${TEFLON_SOURCE_DIR}/util/exceptions/Exception.cpp
    ${TEFLON_SOURCE_DIR}/util/exceptions/FileNotFoundException.cpp
    ${TEFLON_SOURCE_DIR}/util/exceptions/OutOfBoundsException.cpp
    )

add_library (${TEFLON_LOGGER}
    ${TEFLON_SOURCE_DIR}/logger/Logger.cpp
    )

add_library (${TEFLON_INPUT}
    ${TEFLON_SOURCE_DIR}/input/corpus/Corpus.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/Document.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/Alphabet.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/AlphabetIterator.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/FeatureCorpus.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/FeatureCorpusIO.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/FeatureDocument.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/FeatureMap.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/feature/FeatureMapIterator.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/text/TextCorpus.cpp
    ${TEFLON_SOURCE_DIR}/input/corpus/text/TextDocument.cpp
    ${TEFLON_SOURCE_DIR}/input/exceptions/CorpusNotFoundException.cpp
    ${TEFLON_SOURCE_DIR}/input/exceptions/IncompatibleCorpusException.cpp
    ${TEFLON_SOURCE_DIR}/input/exceptions/TermNotPresentException.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/bundle/CompleteFilteredBundle.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/bundle/InputOptimiseBundle.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/bundle/ScanInputOptimiseBundle.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/DirectoryScannerPipe.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/FeatureMapPipe.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/InputPipe.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/LengthFilter.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/LowerCasePipe.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/Pipe.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/PunctuationFilter.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/StopwordFilter.cpp
    ${TEFLON_SOURCE_DIR}/input/pipe/XmlFilter.cpp
    )

add_library (${TEFLON_OUTPUT}
    ${TEFLON_SOURCE_DIR}/output/Identifier.cpp
    )

add_library (${TEFLON_MODEL}
    ${TEFLON_SOURCE_DIR}/model/ProbabilityMatrix.cpp
    ${TEFLON_SOURCE_DIR}/model/TopicModel.cpp
    )

add_library (${TEFLON_ALGORITHM}
    ${TEFLON_SOURCE_DIR}/algorithm/LDA.cpp
    ${TEFLON_SOURCE_DIR}/algorithm/RandomNumberGenerator.cpp
    )

#find_package(Threads REQUIRED)

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################

message("-- Testing mode: ${TESTING}")

IF(("FAST" STREQUAL TESTING) OR ("ALL" STREQUAL TESTING))

    message("-- Testing is enabled.")

    add_subdirectory(gmock)
    enable_testing(true) 

    include_directories(
        ${gtest_SOURCE_DIR}/include 
        ${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include 
        ${gmock_SOURCE_DIR}
        ${TEFLON_MOCK_DIR}
    )

    ################################################
    # Code coverage ################################
    ################################################

    message("-- Coverage mode: ${COVERAGE}")
    if(("LCOV" STREQUAL COVERAGE) OR ("COBERTURA" STREQUAL COVERAGE))

      set(CMAKE_BUILD_TYPE "Debug")

      if(NOT CMAKE_COMPILER_IS_GNUCXX)
        message("-- Compiler not GNU, cannot create coverage report.")
      else()
        FIND_PROGRAM(PYTHON_EXECUTABLE
          NAMES python python3
          PATHS /usr/bin /usr/local/bin /usr/pkg/bin
        )
        include(CodeCoverage)
        message("-- Code coverage is enabled.")

        if("LCOV" STREQUAL COVERAGE)
          SETUP_TARGET_FOR_COVERAGE(coverage ctest coverage)
        else()
          SETUP_TARGET_FOR_COVERAGE_COBERTURA(coverage ctest coverage)
        endif()

      endif()

    endif()

    # list test definitions here
    # TODO: replace this with a macro

    add_executable(UtilTests
        ${TEFLON_TEST_DIR}/util/FilesTest.cpp
        ${TEFLON_TEST_DIR}/util/StringsTest.cpp
        ${TEFLON_TEST_DIR}/util/exceptions/BadCastExceptionTest.cpp
        ${TEFLON_TEST_DIR}/util/exceptions/DuplicateExceptionTest.cpp
        ${TEFLON_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${TEFLON_TEST_DIR}/util/exceptions/FileNotFoundExceptionTest.cpp
        ${TEFLON_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
    ) 
    target_link_libraries(UtilTests
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main) 
    add_test(UtilTests UtilTests)

    add_executable(LoggerTests
        ${TEFLON_TEST_DIR}/logger/LoggerTest.cpp
    ) 
    target_link_libraries(LoggerTests
        ${TEFLON_LOGGER}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        gmock
        gmock_main) 
    add_test(LoggerTests LoggerTests)

    add_executable(InputTests
        ${TEFLON_TEST_DIR}/input/corpus/CorpusTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/DocumentTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/AlphabetTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/AlphabetIteratorTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/FeatureCorpusIOTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/FeatureCorpusTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/FeatureDocumentTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/FeatureMapIteratorTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/feature/FeatureMapTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/text/TextCorpusTest.cpp
        ${TEFLON_TEST_DIR}/input/corpus/text/TextDocumentTest.cpp
        ${TEFLON_TEST_DIR}/input/exceptions/CorpusNotFoundExceptionTest.cpp
        ${TEFLON_TEST_DIR}/input/exceptions/IncompatibleCorpusExceptionTest.cpp
        ${TEFLON_TEST_DIR}/input/exceptions/TermNotPresentExceptionTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/bundle/CompleteFilteredBundleTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/bundle/InputOptimiseBundleTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/bundle/ScanInputOptimiseBundleTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/DirectoryScannerPipeTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/FeatureMapPipeTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/InputPipeTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/LengthFilterTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/LowerCasePipeTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/PipeTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/PunctuationFilterTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/StopwordFilterTest.cpp
        ${TEFLON_TEST_DIR}/input/pipe/XmlFilterTest.cpp
    ) 
    target_link_libraries(InputTests
        ${TEFLON_INPUT}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main)
    add_test(InputTests InputTests)

    add_executable(OutputTests
        ${TEFLON_TEST_DIR}/output/IdentifierTest.cpp
    ) 
    target_link_libraries(OutputTests
        ${TEFLON_OUTPUT}
        ${TEFLON_INPUT}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main)
    add_test(OutputTests OutputTests)

    add_executable(ModelTests
        ${TEFLON_TEST_DIR}/model/ProbabilityMatrixTest.cpp
        ${TEFLON_TEST_DIR}/model/TopicModelTest.cpp
    ) 
    target_link_libraries(ModelTests
        ${TEFLON_MODEL}
        ${TEFLON_OUTPUT}
        ${TEFLON_INPUT}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main)
    add_test(ModelTests ModelTests)

    add_executable(AlgorithmTests
        ${TEFLON_TEST_DIR}/algorithm/LDATest.cpp
        ${TEFLON_TEST_DIR}/algorithm/RandomNumberGeneratorTest.cpp
    ) 
    target_link_libraries(AlgorithmTests
        ${TEFLON_ALGORITHM}
        ${TEFLON_MODEL}
        ${TEFLON_OUTPUT}
        ${TEFLON_INPUT}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main)
    add_test(AlgorithmTests AlgorithmTests)

ENDIF()

IF("ALL" STREQUAL TESTING)

    message("-- Integration testing is enabled.")

    add_executable(IntegrationTests
        ${TEFLON_TEST_DIR}/integration/IntegrationTests.cpp
    ) 
    target_link_libraries(IntegrationTests
        ${TEFLON_ALGORITHM}
        ${TEFLON_MODEL}
        ${TEFLON_OUTPUT}
        ${TEFLON_INPUT}
        ${TEFLON_UTIL}
        ${Boost_REGEX_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        gmock
        gmock_main)
    add_test(IntegrationTests IntegrationTests)

ENDIF()

add_executable (${TEFLON_NAME}
    ${TEFLON_SOURCE_DIR}/main.cpp)
target_link_libraries(${TEFLON_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    ${TEFLON_ALGORITHM}
    ${TEFLON_MODEL}
    ${TEFLON_OUTPUT}
    ${TEFLON_INPUT}
    ${TEFLON_UTIL}
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_REGEX_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    )
