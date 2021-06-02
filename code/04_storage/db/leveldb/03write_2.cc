#include <assert.h>
#include <iostream>
#include <thread>
#include "leveldb/db.h"

/**
 * $ g++ -o write_test test.cpp -std=c++11 -g -DLEVELDB_PLATFORM_POSIX -DLEVELDB_HAS_PORT_CONFIG_H -lleveldb -lpthread -DWRITE_MODE
 * $ g++ -o read_test test.cpp -std=c++11 -g -DLEVELDB_PLATFORM_POSIX -DLEVELDB_HAS_PORT_CONFIG_H -lleveldb -lpthread
**/

void write(leveldb::DB *db)
{
    //写入key, value
    for (int i = 0; i < 500; i++)
    {
        db->Put(leveldb::WriteOptions(), std::to_string(i), std::to_string(i));
        //std::cout << "write key:" << key << " value:" << value << " " << status.ToString() << std::endl;
    }
}

int main()
{
    leveldb::DB *db = NULL;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "./data.db/test.db", &db);
    std::cout << status.ToString() << std::endl;

    std::string key = "name";

    std::string value = "Jeff Dean";

    std::thread t1(write, db);
    std::thread t2(write, db);
    // std::thread t3(write, db);
    // std::thread t4(write, db);
    // std::thread t5(write, db);
    // std::thread t6(write, db);
    // std::thread t7(write, db);
    // std::thread t8(write, db);
    // std::thread t9(write, db);
    // std::thread t10(write, db);
    // std::thread t3(write, db);
    // std::thread t4(write, db);
    // std::thread t5(write, db);
    // std::thread t6(write, db);
    t1.join();
    t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();
    // t7.join();
    // t8.join();
    // t9.join();
    // t10.join();

    delete db;
    return 0;
}
