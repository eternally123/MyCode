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

    // 3.异步写入对象
    librados::bufferlist bl;
    std::string objectID = "ndsl";
    std::string objectContent = "hello world! this is a test.";
    bl.append(objectContent);
    librados::AioCompletion *write_completion = librados::Rados::aio_create_completion();
    ret = io_ctx.aio_write(objectID, write_completion, bl, objectContent.size(), 0);
    if (ret < 0)
    {
        std::cout << "aio_write failed\n";
    }
    else
    {
        std::cout << "aio_write success\n";
    }
    ret = io_ctx.aio_append(objectID, write_completion, bl, objectContent.size());
    if (ret < 0)
    {
        std::cout << "aio_append failed\n";
    }
    else
    {
        std::cout << "aio_append success\n";
    }
    write_completion->wait_for_complete();
    ret = write_completion->get_return_value();
    if (ret < 0)
    {
        std::cout << "error\n";
    }
    else
    {
        std::cout << "aio write operation finish\n";
    }

    // 4.异步读取对象
    librados::bufferlist readbl;
    librados::AioCompletion *read_completion = librados::Rados::aio_create_completion();
    int size = 4 * 1024 * 1024;
    io_ctx.aio_read(objectID, read_completion, &readbl, size, 0);
    read_completion->wait_for_complete();
    ret = read_completion->get_return_value();
    if (ret < 0)
    {
        std::cout << "read failed\n";
    }
    else
    {
        std::cout << "aio read " << ret << " bytes:" << readbl.c_str() << "\n";
    }

    //delete pool
    cluster.pool_delete(pool_name.c_str());
    io_ctx.close();
    cluster.shutdown();
}