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

    // 2.create io contex ,binding a pool
    cluster.pool_create("test");
    std::cout << "pool create:test\n";
    librados::IoCtx io_ctx;
    std::string pool_name = "test";
    ret = cluster.ioctx_create(pool_name.c_str(), io_ctx);
    if (ret < 0)
    {
        std::cout << "ioctx_create failed\n";
    }
    else
    {
        std::cout << "binding ioctx to pool:test\n";
    }
    cluster.pool_delete("test");
    std::cout << "pool delete:test\n";

    io_ctx.close();
    cluster.shutdown();
}