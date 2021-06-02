cmake_minimum_required(VERSION 3.19)
project(linux)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. SRC_LIST)
aux_source_directory(./syncframe SRC_LIST)

add_executable(linux ${SRC_LIST})

target_link_libraries(linux pthread ssl crypto)