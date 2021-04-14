//
// Created by txy on 2021/1/5.
// sql 池封装
#ifndef YM_SERVER_SQLCONNPOOL_H
#define YM_SERVER_SQLCONNPOOL_H
#include "mysql.h"
#include "string"
#include "queue"
#include "mutex"
#include "thread"
#include "condition_variable"


#include "../../src/LogWriter.h"


class SqlConnPool {
public:
    void init(const char* host, unsigned int port, const char* user, const char* pwd,
              const char* dbName, int connSize);

    static SqlConnPool* instance(); // 静态 instance，私有构造，通过 class::instance()->init 初始化

    MYSQL* getMysqlConn();

    int getFreeCount();

    void closeConn();
    void freeConn(MYSQL *mysql);
private:
    SqlConnPool();
    ~SqlConnPool();

    int maxConnSize_;
    int freeCount_;
    int useCount_;

    std::queue<MYSQL*> connQ_;
    std::condition_variable cond_;
    std::mutex mutex_;
};

class SqlConnPoolGuard{
public:
    SqlConnPoolGuard(MYSQL** sql, SqlConnPool* pool){ // 这边 MYSQL 必须 **
        assert(pool);
        // 防止资源瞬间抢完（待测试）
        while (*sql == nullptr){
            *sql = pool->getMysqlConn();
        }
        sql_ = *sql;
        pool_ = pool;
    }

    ~SqlConnPoolGuard(){
        if (sql_){
//                std::cout << "free" << std::endl;
            pool_->freeConn(sql_);
        }
    }
private:
    SqlConnPool *pool_;
    MYSQL *sql_;
};


#endif //YM_SERVER_SQLCONNPOOL_H
