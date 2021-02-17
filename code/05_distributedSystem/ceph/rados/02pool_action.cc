#include <rados/librados.hpp>

#include <iostream>
#include <string>

int main()
{
    // connect cluster
    int ret = 0;
    std::string cluster_name = "ceph";
    std::string user_name = "client.admin";
    librados::Rados cluster;
    ret = cluster.init2(user_name.c_str(), cluster_name.c_str(), 0);
    if (ret < 0)
    {
        std::cout << "init2 failed\n";
    }
    ret = cluster.conf_read_file("/etc/ceph/ceph.conf");
    if (ret < 0)
    {
        std::cout << "conf_read_file failed\n";
    }
    ret = cluster.connect();
    if (ret < 0)
    {
        std::cout << "connect failed\n";
    }

    // pool create delete list
    cluster.pool_create("test");

    // list
    std::list<std::string> pools;
    librados::stats_map map;
    cluster.pool_list(pools);
    cluster.get_pool_stats(pools, map);
    std::cout << "pools are:\n";
    for (auto &it : pools)
    {
        std::cout << it << "\t";
    }
    std::cout << "\n"
              << "pools detail:\n";
    for (auto &it : map)
    {
        std::cout << "========================\n";
        std::cout << "pool:" << it.first << "\n";
        std::cout << "num_bytes:" << it.second.num_bytes << "\n";
        std::cout << "num_kb:" << it.second.num_kb << "\n";
        std::cout << "num_objects:" << it.second.num_objects << "\n";
        std::cout << "num_object_clones:" << it.second.num_object_clones << "\n";
        std::cout << "num_object_copies:" << it.second.num_object_copies << "\n";
        std::cout << "num_objects_missing_on_primary:" << it.second.num_objects_missing_on_primary << "\n";
        std::cout << "num_objects_unfound:" << it.second.num_objects_unfound << "\n";
        std::cout << "num_objects_degraded:" << it.second.num_objects_degraded << "\n";
        std::cout << "num_rd:" << it.second.num_rd << "\n";
        std::cout << "num_rd_kb:" << it.second.num_rd_kb << "\n";
        std::cout << "num_wr:" << it.second.num_wr << "\n";
        std::cout << "num_wr_kb:" << it.second.num_wr_kb << "\n";
        std::cout << "========================\n";
    }

    // delete
    cluster.pool_delete("test");
    cluster.shutdown();
}