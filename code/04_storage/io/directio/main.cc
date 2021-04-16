#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define BUF_SIZE 1024 * 10000

int main(int argc, char *argv[])
{
    int fd;
    int ret;
    unsigned char *buf;
    ret = posix_memalign((void **)&buf, 512, BUF_SIZE);
    if (ret)
    {
        perror("posix_memalign failed");
        exit(1);
    }
    memset(buf, 'c', BUF_SIZE);

    fd = open("./direct_io.data", O_WRONLY | O_DIRECT | O_CREAT, 0755);
    if (fd < 0)
    {
        perror("open ./direct_io.data failed");
        exit(1);
    }

    ret = write(fd, buf, BUF_SIZE);
    memset(buf + 512 * 9999, 'd', 1);
    if (ret < 0)
    {
        perror("write ./direct_io.data failed");
    }

    free(buf);
    close(fd);
}