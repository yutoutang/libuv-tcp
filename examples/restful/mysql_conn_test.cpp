#include "mysql.h"
#include "string"
#include "mutex"
#include "thread"
#include "iostream"

#include "SqlConnPool.h"

using namespace std;

const char host[] = "localhost";
const char user[] = "root";
const char pwd[] = "127010";
const char database[] = "yutou_blog";
unsigned int port = 3306;

void init(){
    SqlConnPool::instance()->init(host, port, user, pwd, database, 2);
}

void thr(){
    MYSQL *myCont;
    MYSQL_RES* res = nullptr;
    SqlConnPoolGuard sqlguard(&myCont, SqlConnPool::instance()); // 拿

//    cout << myCont << endl;
    string name = "2625962609@qq.com";
    if (myCont != nullptr){
//        cout << "connect ok" << endl;
        char order[256] = { 0 };
        snprintf(order, 256, "select username, password from user where username='%s' LIMIT 1", name.c_str());
        // 查询
        mysql_query(myCont, order);
        res = mysql_store_result(myCont);

        while (MYSQL_ROW row = mysql_fetch_row(res)){
            printf("%s\n", row[0]);
            printf("%s\n", row[1]);
        }

    }
    else
    {
        cout << "connect failed!" << endl;
    }
}

int main(){
    init();
    this_thread::sleep_for(std::chrono::seconds(1));
    thread t1(thr);
    thread t2(thr);
    thread t3(thr);
    thread t4(thr);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}