set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
cmake_minimum_required(VERSION 2.6)
project(first_project)

# configure_file (
#   "${PROJECT_SOURCE_DIR}/config.h.in"
#   "${PROJECT_BINARY_DIR}/config.h"
# )

aux_source_directory(. DIR_SRCS) #将本路径下所有源文件搜集后赋值给DIR_SRCS

add_executable(first_project ${DIR_SRCS})  