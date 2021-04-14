//
// Created by txy on 2021/1/5.
//

#include "SqlConnPool.h"

using namespace std;

SqlConnPool::SqlConnPool() : freeCount_(0), useCount_(0){}

SqlConnPool::~SqlConnPool() {
    closeConn();
}


void SqlConnPool::init(const char *host, unsigned int port,
                           const char *user, const char *pwd, const char *dbName,
                           int connSize = 10) {
    for (int i = 0; i < connSize; ++i) {
        MYSQL *sql = nullptr;
        sql = mysql_init(sql);
        if (mysql_real_connect(sql, host, user, pwd, dbName, port, nullptr, 0)){
            connQ_.push(sql);
        } else {
            LogWriter::Instance()->warn("sql conn error");
        }
        freeCount_++;
    }
    maxConnSize_ = connSize;
}

SqlConnPool *SqlConnPool::instance() {
    static SqlConnPool sqlConnPool;
    return &sqlConnPool;
}

// 从连接池中取出
MYSQL *SqlConnPool::getMysqlConn() {
    MYSQL *sql = nullptr;
    if (connQ_.empty()){
//        LogWriter::Instance()->warn("sqlConnPoll is empty");
        return nullptr;
    }
    {
        std::unique_lock<std::mutex> lck(mutex_);
        useCount_++;
        while (useCount_ > maxConnSize_){
            cond_.wait(lck);
        }
        sql = connQ_.front();
        connQ_.pop();
    }
    return sql;
}

int SqlConnPool::getFreeCount() {
    // 读
    std::lock_guard<std::mutex> lck(mutex_);
    return freeCount_;
}

void SqlConnPool::closeConn() {
    MYSQL *sql = nullptr; // 写
    std::lock_guard<std::mutex> lck(mutex_);
    while (connQ_.empty()){
        sql = connQ_.front();
        mysql_close(sql);
        connQ_.pop();
    }
    mysql_library_end;
}

// sql 空闲了进入连接池中
void SqlConnPool::freeConn(MYSQL *mysql) {
    assert(mysql); // 写
    std::lock_guard<std::mutex> lck(mutex_);
    connQ_.push(mysql);
    useCount_--;
    cond_.notify_one();
}
