#include <assert.h>
#include <iostream>
#include "leveldb/db.h"

/**
 * $ g++ -o write_test test.cpp -std=c++11 -g -DLEVELDB_PLATFORM_POSIX -DLEVELDB_HAS_PORT_CONFIG_H -lleveldb -lpthread -DWRITE_MODE
 * $ g++ -o read_test test.cpp -std=c++11 -g -DLEVELDB_PLATFORM_POSIX -DLEVELDB_HAS_PORT_CONFIG_H -lleveldb -lpthread
**/
int main()
{
    leveldb::DB *db = NULL;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "./data/test.db", &db);
    std::cout << status.ToString() << std::endl;

    std::string key = "name";

#if defined(WRITE_MODE)
    std::string value = "Jeff Dean";
    //写入key, value
    status = db->Put(leveldb::WriteOptions(), key, value);
    std::cout << "write key:" << key << " value:" << value << " " << status.ToString() << std::endl;
#else
    std::string db_value;
    status = db->Get(leveldb::ReadOptions(), key, &db_value);
    std::cout << "read key:" << key << " value:" << db_value << " " << status.ToString() << std::endl;
#endif
    delete db;
    return 0;
}