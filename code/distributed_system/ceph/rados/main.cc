#include <rados/librados.hpp>

#include <iostream>
#include <string>
#include <list>

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

    // 2.创建存储池
    std::string pool_name = "test_pool";
    // ret = cluster.pool_create(pool_name.c_str());
    if (ret < 0)
    {
        std::cout << "pool_create failed\n";
    }

    // 3.创建ioctx
    librados::IoCtx io_ctx;
    ret = cluster.ioctx_create(pool_name.c_str(), io_ctx);
    if (ret < 0)
    {
        std::cout << "ioctx_create failed\n";
    }

    // 4.读写对象
    std::string objectId = "ndsl";
    std::string objectContent = "hello world2!";
    librados::bufferlist bl;
    bl.append(objectContent);
    bl.append(objectContent);
    ret = io_ctx.write(objectId, bl, objectContent.size() * 2, 0);
    if (ret < 0)
    {
        std::cout << "write failed\n";
    }

    librados::bufferlist readbl;
    ret = io_ctx.read(objectId, readbl, 4096, 0);
    std::cout << "ret=" << ret << std::endl;
    std::cout << "read context:" << readbl.c_str() << std::endl;

    // 5.快照
    ret = io_ctx.snap_create("what");
    if (ret < 0)
    {
        std::cout << "snap_create failed\n";
    }
    // io_ctx.snap_get_name();

    // 删除存储池、关闭连接
    // sleep(10);
    // cluster.pool_delete(pool_name.c_str());
    io_ctx.close();
    cluster.shutdown();
}