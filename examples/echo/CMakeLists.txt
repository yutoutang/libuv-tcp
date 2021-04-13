add_executable(EchoServer server.cpp EchoServer.cpp ${SRC})
target_link_libraries(EchoServer uv)

add_executable(EchoClient client.cpp EchoClient.cpp ${SRC})
target_link_libraries(EchoClient uv)