set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
cmake_minimum_required(VERSION 2.6)
project(first_project)

include_directories("/home/liuyongfeng/Documents/test_projects/civetweb/include")

link_directories(/home/liuyongfeng/Documents/test_projects/civetweb)
find_package(Threads)

aux_source_directory(. DIR_SRCS) #将本路径下所有源文件搜集后赋值给DIR_SRCS

add_executable(first_project ${DIR_SRCS})  
target_link_libraries(first_project Threads::Threads libcivetweb.so ${CMAKE_DL_LIBS}) # orders matter, libdl must be the last one