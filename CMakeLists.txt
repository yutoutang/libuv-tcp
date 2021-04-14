cmake_minimum_required(VERSION 3.17)
project(uv_tcp)

set(CMAKE_CXX_STANDARD 14)
add_definitions("-Wall -g")

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/http SRC)


set(LIBUV_DIR /usr/local/Cellar/libuv/1.31.0)
include_directories(${LIBUV_DIR}/include)
link_directories(${LIBUV_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/test)

add_subdirectory(${PROJECT_SOURCE_DIR}/examples/cache)
add_subdirectory(${PROJECT_SOURCE_DIR}/examples/echo)
add_subdirectory(${PROJECT_SOURCE_DIR}/examples/restful)



