# CMake build script for Topic Model Training Enhancement project.

cmake_minimum_required (VERSION 2.6.2)

########
# Main #
########

project (tmte-cpp)

set(TMTE_NAME tmte-cpp)
set(TMTE_LIB tmte-lib)
set(TMTE_SOURCE_DIR src)
set(TMTE_INCLUDE_DIR include)
set(TMTE_TEST_DIR test)

# list all source files here
# TODO: replace this with a macro

add_library (${TMTE_LIB}
    ${TMTE_SOURCE_DIR}/algorithm/LatentDirichletAllocation.cpp
    ${TMTE_SOURCE_DIR}/input/FeatureVector.cpp
    ${TMTE_SOURCE_DIR}/input/InstanceList.cpp
    ${TMTE_SOURCE_DIR}/input/Pipe.cpp
    ${TMTE_SOURCE_DIR}/model/Alphabet.cpp
    ${TMTE_SOURCE_DIR}/model/Corpus.cpp
    ${TMTE_SOURCE_DIR}/model/Document.cpp
    ${TMTE_SOURCE_DIR}/model/TopicModel.cpp
    ${TMTE_SOURCE_DIR}/output/Identifier.cpp
    ${TMTE_SOURCE_DIR}/output/TopicAssignment.cpp
    )

find_package(Threads REQUIRED)

add_executable (${TMTE_NAME}
	${TMTE_SOURCE_DIR}/main.cpp)
target_link_libraries(${TMTE_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
	${TMTE_LIB})

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################
    
add_subdirectory(gmock-1.6.0)
enable_testing(true) 

include_directories(${gtest_SOURCE_DIR}/include 
	${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include 
	${gmock_SOURCE_DIR})
	
# list test definitions here
# TODO: replace this with a macro

add_executable(AlgorithmTests
	${TMTE_TEST_DIR}/algorithm/LatentDirichletAllocationTest.cpp
	) 
target_link_libraries(AlgorithmTests gmock gmock_main ${TMTE_LIB})
add_test(AlgorithmTests AlgorithmTests)

add_executable(InputTests
	${TMTE_TEST_DIR}/input/exceptions/AlphabetSetExceptionTest.cpp
	${TMTE_TEST_DIR}/input/FeatureVectorTest.cpp
	${TMTE_TEST_DIR}/input/InstanceListTest.cpp
	${TMTE_TEST_DIR}/input/PipeTest.cpp
	) 
target_link_libraries(InputTests gmock gmock_main ${TMTE_LIB}) 
add_test(InputTests InputTests)

add_executable(ModelTests 
	${TMTE_TEST_DIR}/model/AlphabetTest.cpp
	${TMTE_TEST_DIR}/model/CorpusTest.cpp
	${TMTE_TEST_DIR}/model/DocumentTest.cpp
	${TMTE_TEST_DIR}/model/TopicModelTest.cpp
	${TMTE_TEST_DIR}/model/exceptions/DuplicatedWordExceptionTest.cpp
	${TMTE_TEST_DIR}/model/exceptions/WordNotPresentExceptionTest.cpp
	) 
target_link_libraries(ModelTests gmock gmock_main ${TMTE_LIB}) 
add_test(ModelTests ModelTests)

add_executable(OutputTests 
	${TMTE_TEST_DIR}/output/IdentifierTest.cpp
	${TMTE_TEST_DIR}/output/TopicAssignmentTest.cpp
	) 
target_link_libraries(OutputTests gmock gmock_main ${TMTE_LIB}) 
add_test(OutputTests OutputTests)

add_executable(UtilTests 
	${TMTE_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${TMTE_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
        ${TMTE_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
	) 
target_link_libraries(UtilTests gmock gmock_main ${TMTE_LIB}) 
add_test(UtilTests UtilTests)
