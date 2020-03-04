cmake_minimum_required(VERSION 3.0.0)
project(geometry VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

add_executable(geometry main.cpp point2d.cpp point3d.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
