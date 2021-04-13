add_definitions("-Wall -g")

add_executable(CacheServer server.cpp CacheItem.cpp CacheSegments.cpp CacheServer.cpp Buffer.cpp ${SRC})
target_link_libraries(CacheServer uv)