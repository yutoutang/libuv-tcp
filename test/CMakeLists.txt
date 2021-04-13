add_executable(test_loop test_loop.cpp ${SRC})
target_link_libraries(test_loop uv)

add_executable(test_uv test_uv.cpp)
target_link_libraries(test_uv uv)

add_executable(test_idle_handle test_idle_handle.cpp)
target_link_libraries(test_idle_handle  uv)

add_executable(test_signal test_signal.cpp)
target_link_libraries(test_signal uv)

add_executable(test_async test_async.cpp)
target_link_libraries(test_async uv)

add_executable(test_acceptor test_acceptor.cpp ${SRC})
target_link_libraries(test_acceptor uv)

add_executable(test_timer test_timer.cpp ${SRC})
target_link_libraries(test_timer uv)

add_executable(test_log test_log.cpp)

add_executable(test_radix_tree test_radix_tree.cpp ../src/http/RadixTree.h ../src/http/HttpCommon.cpp)