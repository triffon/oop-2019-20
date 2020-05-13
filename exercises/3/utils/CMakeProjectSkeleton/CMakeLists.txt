cmake_minimum_required(VERSION 2.8.9)
#Exports compile commands for auto completion
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

project(ProjectName)
 
#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(ProjectName ${SOURCES})
