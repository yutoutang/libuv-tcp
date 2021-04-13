cmake_minimum_required(VERSION 3.17)
project(uv_tcp)

set(CMAKE_CXX_STANDARD 14)
add_definitions("-Wall -g")

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/http SRC)


set(LIBUV_DIR /usr/local/Cellar/libuv/1.31.0)
include_directories(${LIBUV_DIR}/include)
link_directories(${LIBUV_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/examples/cache)


add_executable(test_loop test/test_loop.cpp ${SRC})
target_link_libraries(test_loop uv)

add_executable(test_uv test/test_uv.cpp)
target_link_libraries(test_uv uv)
add_executable(test_idle_handle test/test_idle_handle.cpp)
target_link_libraries(test_idle_handle  uv)
add_executable(test_signal test/test_signal.cpp)
target_link_libraries(test_signal uv)
add_executable(test_async test/test_async.cpp)
target_link_libraries(test_async uv)

add_executable(test_acceptor test/test_acceptor.cpp ${SRC})
target_link_libraries(test_acceptor uv)

add_executable(test_timer test/test_timer.cpp ${SRC})
target_link_libraries(test_timer uv)

add_executable(test_log test/test_log.cpp)

add_executable(EchoServer examples/echo/server.cpp examples/echo/EchoServer.cpp examples/echo/EchoClient.cpp ${SRC})
target_link_libraries(EchoServer uv)

add_executable(EchoClient examples/echo/client.cpp examples/echo/EchoClient.cpp ${SRC})
target_link_libraries(EchoClient uv)


add_executable(test_str_fun test/test_str_fun.cpp)

add_executable(test_request test/test_request.cpp src/http/Request.cpp src/http/HttpCommon.cpp)

add_executable(cross_thread examples/client_cross/cross_thread.cpp ${SRC})
target_link_libraries(cross_thread uv)
add_executable(test_ref test/test_ref.cpp)

add_executable(test_packet test/test_packet.cpp src/Packet.cpp src/ListBuffer.cpp)

add_executable(RestfulServer examples/restful/server.cpp ${SRC})
target_link_libraries(RestfulServer uv)

add_executable(test_radix_tree test/test_radix_tree.cpp src/http/RadixTree.h src/http/HttpCommon.cpp)