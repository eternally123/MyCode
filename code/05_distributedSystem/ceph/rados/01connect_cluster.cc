#include <rados/librados.hpp>

#include <iostream>
#include <string>

int main()
{
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

    cluster.shutdown();
}