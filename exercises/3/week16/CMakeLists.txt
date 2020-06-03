cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#Exports compile commands for auto completion
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

project(ProjectName)

#Setting path to gmock
set(GMOCK_INCLUDE_DIRS /usr/include/gmock)
set(GMOCK_BOTH_LIBRARIES /usr/lib/libgmock.a /usr/lib/libgmock_main.a /usr/lib/libgtest.a /usr/lib/libgtest_main.a)

#Locate GTest
find_package(GTest REQUIRED)

#Add GTest and include/ to the included dirs
include_directories(include ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
file(GLOB TESTS "tests/*.cpp")
#Project executable
add_executable(ProjectName ${SOURCES})

#Removing the main so it doesn't collide with the main of the tests
list(FILTER SOURCES EXCLUDE REGEX "src/main.cpp")
#Add tests executable
add_executable(runTests ${SOURCES} ${TESTS})

#Link libraries for the gtest
target_link_libraries(runTests ${GMOCK_BOTH_LIBRARIES} pthread)

