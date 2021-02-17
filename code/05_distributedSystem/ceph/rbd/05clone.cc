#include <rados/librados.hpp>
#include <rbd/librbd.hpp>

#include <cstring>
#include <iostream>
#include <string>
#include <list>

void err_msg(int ret, const std::string &msg = "")
{
    std::cerr << "[error] msg:" << msg << " strerror: " << strerror(-ret) << std::endl;
}
void err_exit(int ret, const std::string &msg = "")
{
    err_msg(ret, msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int ret = 0;
    std::string cluster_name = "ceph";
    std::string user_name = "client.admin";
    librados::Rados cluster;
    // 1.连接集群
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

    std::string pool_name = "rbd_pool";
    librados::IoCtx io_ctx;

    ret = cluster.pool_create(pool_name.c_str());
    if (ret < 0)
    {
        std::cout << "ret=" << ret << std::endl;
        err_exit(ret, "failed to create ioctx");
    }

    // 3.创建ioctx
    ret = cluster.ioctx_create(pool_name.c_str(), io_ctx);
    if (ret < 0)
    {
        err_exit(ret, "open ioctx failed");
    }

    // 2.创建rbd镜像
    librbd::RBD rbd;

    std::string image_name = "image01";
    librbd::Image image;
    uint64_t feature = 1;
    int size = 200 * 1024 * 1024;
    int order = 22;
    ret = rbd.create2(io_ctx, image_name.c_str(), size, feature, &order);
    if (ret < 0)
    {
        err_exit(ret, "failed to create rbd");
    }

    // 3.open image
    ret = rbd.open(io_ctx, image, image_name.c_str());
    if (ret < 0)
    {
        err_exit(ret, "failed to open rbd image");
    }

    // 4.操作镜像
    image.snap_create("snap1");
    image.snap_create("snap2");
    image.snap_create("snap3");

    std::vector<librbd::snap_info_t> snaps;
    image.snap_list(snaps);
    for (auto &it : snaps)
    {
        std::cout << "================================\n";
        std::cout << "snap name:" << it.name << "\n"
                  << "snap id:" << it.id << "\n"
                  << "snap size:" << it.size << "\n";
    }
    std::cout << "\n";
    // 5.克隆
    ret = image.snap_protect("snap3");
    if (ret < 0)
    {
        err_exit(ret, "protect failed");
    }
    else
    {
        std::cout << "protect snap3\n";
    }

    ret = rbd.clone(io_ctx, image_name.c_str(), "snap3", io_ctx, "image01_child", feature, &order);
    if (ret < 0)
    {
        err_exit(ret, "clone failed");
    }
    else
    {
        std::cout << "clone snap3\n";
    }

    // 6.显示所有的rbd
    std::vector<std::string> rbds;
    ret = rbd.list(io_ctx, rbds);
    if (ret < 0)
    {
        err_exit(ret, "rbd list failed");
    }
    else
    {
        std::cout << "rbds in this pool are:";
        for (auto &it : rbds)
        {
            std::cout << it << "\t";
        }
        std::cout << "\n";
    }

    // 8.flatten clone

    // 删除镜像
    image.close();
    rbd.remove(io_ctx, image_name.c_str());
    // 关闭资源池
    cluster.pool_delete(pool_name.c_str());
    io_ctx.close();
    // 断开集群连接
    cluster.shutdown();
    exit(EXIT_SUCCESS);
}