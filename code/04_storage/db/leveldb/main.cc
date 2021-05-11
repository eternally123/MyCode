#include <iostream>
#include "leveldb/db.h"

using namespace std;

int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    leveldb::Status s;

    options.create_if_missing = true;
    //options.error_if_exists = true;
    std::string dbpath = "testdb";
    s = leveldb::DB::Open(options, dbpath, &db);
    if (!s.ok())
    {
        cerr << s.ToString() << endl;
        return -1;
    }

    std::string value;
    s = db->Put(leveldb::WriteOptions(), "k1", "v1");
    cout << s.ok() << endl;
    s = db->Get(leveldb::ReadOptions(), "k1", &value);
    cout << s.ok() << " " << value << std::endl;
    s = db->Delete(leveldb::WriteOptions(), "k1");
    cout << s.ok() << endl;
    value.clear();
    s = db->Get(leveldb::ReadOptions(), "k1", &value);
    cout << s.ok() << "" << value << std::endl;

    delete db;
    return 0;
}