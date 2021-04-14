set(MYSQL_CONCPP_DIR /usr/local/mysql-connector-c++-8.0.22)
set(MYSQL_DIR /usr/local/mysql)



include_directories(${MYSQL_DIR}/include)
include_directories(${MYSQL_CONCPP_DIR}/include)
link_directories(${MYSQL_DIR}/lib)
link_directories(${MYSQL_CONCPP_DIR}/lib64)


add_executable(mysql_conn_test mysql_conn_test.cpp SqlConnPool.cpp ../../src/LogWriter.cpp)
target_link_libraries(mysql_conn_test uv mysqlcppconn8 mysqlcppconn-static ssl crypto)

add_executable(RestfulServer server.cpp ${SRC})
target_link_libraries(RestfulServer uv)

