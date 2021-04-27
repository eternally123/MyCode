#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <liburing.h>
#define ENTRIES 4

/**
 * gcc main.c -luring
 * ./a.out test.file
 **/

void callback()
{
    printf("callback function\n");
}

int main(int argc, char *argv[])
{
    struct io_uring ring;
    struct io_uring_sqe *sqe; // send queue
    struct io_uring_cqe *cqe; // receive queue
    int fd, ret;
    void (*func)() = callback;

    struct iovec iov = {
        .iov_base = "Hello World",
        .iov_len = strlen("Hello World"),
    };

    if (argc != 2)
    {
        printf("%s: <testfile>\n", argv[0]);
        return 1;
    }
    /* 1.setup io_uring and do mmap */
    ret = io_uring_queue_init(ENTRIES, &ring, 0);
    if (ret < 0)
    {
        printf("io_uring_queue_init: %s\n", strerror(-ret));
        return 1;
    }

    /* 打开文件 */
    fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd < 0)
    {
        printf("open failed\n");
        ret = 1;
        goto exit;
    }

    /* 2.get an sqe and fill in a WRITEV operation */
    sqe = io_uring_get_sqe(&ring);
    if (!sqe)
    {
        printf("io_uring_get_sqe failed\n");
        ret = 1;
        goto out;
    }
    io_uring_prep_writev(sqe, fd, &iov, 1, 0);
    io_uring_sqe_set_data(sqe, callback);

    /* 3.tell the kernel we have an sqe ready for consumption */
    ret = io_uring_submit(&ring);
    if (ret < 0)
    {
        printf("io_uring_submit: %s\n", strerror(-ret));
        goto out;
    }

    /* 4.wait for the sqe to complete */
    ret = io_uring_wait_cqe(&ring, &cqe);
    if (ret < 0)
    {
        printf("io_uring_wait_cqe: %s\n", strerror(-ret));
        goto out;
    }
    void (*cb)() = (void (*)())io_uring_cqe_get_data(cqe);
    cb();
    /* 5.read and process cqe event */
    io_uring_cqe_seen(&ring, cqe);
out:
    close(fd);
exit:
    /* tear down */
    io_uring_queue_exit(&ring);
    return ret;
}