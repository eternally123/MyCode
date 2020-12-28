#include <rados/librados.hpp>

#include <iostream>
#include <string>

int main()
{
    // 1.connect cluster
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
    std::string pool_name = "test";
    // create pool
    cluster.pool_create(pool_name.c_str());
    librados::IoCtx io_ctx;
    // binding pool
    ret = cluster.ioctx_create(pool_name.c_str(), io_ctx);
    if (ret < 0)
    {
        std::cout << "ioctx_create failed\n";
    }

    // 3.snap operation
    io_ctx.snap_create("snap1");
    io_ctx.snap_create("snap2");
    io_ctx.snap_create("snap3");
    io_ctx.snap_remove("snap2");
    std::vector<librados::snap_t> snaps;
    io_ctx.snap_list(&snaps);
    for (auto &it : snaps)
    {
        std::string name;
        io_ctx.snap_get_name(it, &name);
        time_t time;
        io_ctx.snap_get_stamp(it, &time);
        std::cout << "snapid:" << it
                  << "\tname:" << name
                  << "\ttime:" << time << "\n";
    }

    // delete pool
    cluster.pool_delete(pool_name.c_str());
    io_ctx.close();
    cluster.shutdown();
}