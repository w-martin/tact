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

set(MEWT_NAME mewt)
set(MEWT_INPUT mewt-input)
set(MEWT_OUTPUT mewt-output)
set(MEWT_MODEL mewt-model)
set(MEWT_ALGORITHM mewt-algorithm)
set(MEWT_SOURCE_DIR src)
set(MEWT_INCLUDE_DIR include)
set(MEWT_TEST_DIR test/src)

include_directories(${MEWT_INCLUDE_DIR}
)

# list all source files here
# TODO: replace this with a macro

add_library (${MEWT_INPUT}
    ${MEWT_SOURCE_DIR}/input/Alphabet.cpp
    ${MEWT_SOURCE_DIR}/input/FeatureVector.cpp
    ${MEWT_SOURCE_DIR}/input/Instance.cpp
    ${MEWT_SOURCE_DIR}/input/Pipe.cpp
    )

add_library (${MEWT_OUTPUT}
    ${MEWT_SOURCE_DIR}/output/Identifier.cpp
    )

add_library (${MEWT_MODEL}
    ${MEWT_SOURCE_DIR}/model/Corpus.cpp
    ${MEWT_SOURCE_DIR}/model/Document.cpp
    ${MEWT_SOURCE_DIR}/model/ProbabilityMatrix.cpp
    ${MEWT_SOURCE_DIR}/model/TopicModel.cpp
    )

add_library (${MEWT_ALGORITHM}
    ${MEWT_SOURCE_DIR}/algorithm/AbstractTopicModel.cpp
    ${MEWT_SOURCE_DIR}/algorithm/RandomNumberGenerator.cpp
    )

find_package(Threads REQUIRED)

add_executable (${MEWT_NAME}
	${MEWT_SOURCE_DIR}/main.cpp)
target_link_libraries(${MEWT_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
	${MEWT_INPUT}
	${MEWT_OUTPUT}
	${MEWT_MODEL}
	${MEWT_ALGORITHM})

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################
    
add_subdirectory(gmock-1.6.0)
enable_testing(true) 

include_directories(
        .
        ${gtest_SOURCE_DIR}/include 
	${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include 
	${gmock_SOURCE_DIR})
	
# list test definitions here
# TODO: replace this with a macro

add_executable(UtilTests 
	${MEWT_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
        ${MEWT_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
	) 
target_link_libraries(UtilTests gmock gmock_main) 
add_test(UtilTests UtilTests)

add_executable(InputTests
	${MEWT_TEST_DIR}/input/exceptions/AlphabetSetExceptionTest.cpp
	${MEWT_TEST_DIR}/input/AlphabetTest.cpp
	${MEWT_TEST_DIR}/input/FeatureVectorTest.cpp
	${MEWT_TEST_DIR}/input/InstanceTest.cpp
	${MEWT_TEST_DIR}/input/PipeTest.cpp
	) 
target_link_libraries(InputTests gmock gmock_main
    ${MEWT_INPUT})
add_test(InputTests InputTests)

add_executable(OutputTests
	${MEWT_TEST_DIR}/output/exceptions/ElementNotPresentExceptionTest.cpp
	${MEWT_TEST_DIR}/output/IdentifierTest.cpp
	) 
target_link_libraries(OutputTests gmock gmock_main
    ${MEWT_INPUT} ${MEWT_OUTPUT})
add_test(OutputTests OutputTests)

add_executable(ModelTests 
	${MEWT_TEST_DIR}/model/CorpusTest.cpp
	${MEWT_TEST_DIR}/model/DocumentTest.cpp
	${MEWT_TEST_DIR}/model/ProbabilityMatrixTest.cpp
	${MEWT_TEST_DIR}/model/TopicModelTest.cpp
	${MEWT_TEST_DIR}/model/exceptions/DuplicatedWordExceptionTest.cpp
	${MEWT_TEST_DIR}/model/exceptions/WordNotPresentExceptionTest.cpp
	) 
target_link_libraries(ModelTests gmock gmock_main
    ${MEWT_OUTPUT} ${MEWT_MODEL})
add_test(ModelTests ModelTests)

add_executable(AlgorithmTests
	${MEWT_TEST_DIR}/algorithm/AbstractTopicModelTest.cpp
	${MEWT_TEST_DIR}/algorithm/RandomNumberGeneratorTest.cpp
	) 
target_link_libraries(AlgorithmTests gmock gmock_main
    ${MEWT_INPUT} ${MEWT_OUTPUT} ${MEWT_MODEL} ${MEWT_ALGORITHM})
add_test(AlgorithmTests AlgorithmTests)
