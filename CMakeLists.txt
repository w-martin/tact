# CMake build script for Topic Model Training Enhancement project.

cmake_minimum_required (VERSION 2.4)

########
# Main #
########

project (tmte-cpp CXX)

set(TMTE_NAME tmte-cpp)
set(TMTE_LIB tmte-lib)
set(TMTE_SOURCE_DIR src)
set(TMTE_INCLUDE_DIR include)
set(TMTE_TEST_DIR test)

include_directories(${TMTE_INCLUDE_DIR})

# list all source files here
# TODO: replace this with a macro

add_library (${TMTE_LIB}
    ${TMTE_SOURCE_DIR}/model/Corpus.cpp
    ${TMTE_SOURCE_DIR}/model/Document.cpp
    )
    
add_executable (${TMTE_NAME}
	${TMTE_SOURCE_DIR}/main.cpp)
target_link_libraries(${TMTE_NAME}
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

add_executable(ModelTests 
	${TMTE_TEST_DIR}/model/CorpusTest.cpp
	${TMTE_TEST_DIR}/model/DocumentTest.cpp
	) 
target_link_libraries(ModelTests gmock gmock_main ${TMTE_LIB}) 
add_test(ModelTests ModelTests)

add_executable(UtilTests 
	${TMTE_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${TMTE_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
	) 
target_link_libraries(UtilTests gmock gmock_main ${TMTE_LIB}) 
add_test(UtilTests UtilTests)
