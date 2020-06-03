cmake_minimum_required(VERSION 3.0.0)
project(player VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

add_executable(tasks main.cpp task.cpp quicktask.cpp simpletask.cpp repeattask.cpp ../common/named.cpp)
include_directories(../common tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
