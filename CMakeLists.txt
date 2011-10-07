# CMake build script for Topic Model Training Enhancement project.

cmake_minimum_required (VERSION 2.6)

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

########
# Main #
########

project (tmte-cpp CXX)

set(NNSIM_NAME tmte-cpp)
set(NNSIM_LIB tmte-lib)
set(NNSIM_SOURCE_DIR src)
set(NNSIM_INCLUDE_DIR include)
set(NNSIM_TEST_DIR test)

include_directories(${NNSIM_INCLUDE_DIR})

# list all source files here
# TODO: replace this with a macro

#add_library (${NNSIM_LIB}
#    ${NNSIM_SOURCE_DIR}/
#    )
    
add_executable (${NNSIM_NAME}
	${NNSIM_SOURCE_DIR}/main.cpp)
#target_link_libraries(${NNSIM_NAME}
#	${NNSIM_LIB})

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

#add_executable(ModelTests 
#	${NNSIM_TEST_DIR}/
#	) 
#target_link_libraries(ModelTests gmock gmock_main ${NNSIM_LIB}) 
#add_test(ModelTests ModelTests)
