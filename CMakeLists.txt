cmake_minimum_required(VERSION 3.20)

project(SimpleChessGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(SimpleChessGame ${PROJECT_SOURCES})
target_include_directories(SimpleChessGame PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/c++_headers")