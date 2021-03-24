#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd, pid;
    char buffer[20];
    /** 最好用open打开文件就设置了O_CLOEXEC代替用fctnl设置FD_CLOEXEC */
    //fd=open("wo.txt",O_RDONLY|O_CLOEXEC);
    fd = open("test.txt", O_RDONLY);
    printf("%d\n", fd);
    int val = fcntl(fd, F_GETFD);
    val |= FD_CLOEXEC;
    fcntl(fd, F_SETFD, val);
    pid = fork();
    if (pid == 0)
    {
        char child_buf[2];
        memset(child_buf, 0, sizeof(child_buf));
        ssize_t bytes = read(fd, child_buf, sizeof(child_buf) - 1);
        printf("child process, bytes:%d,%s\n\n", bytes, child_buf);

        char fd_str[5];
        memset(fd_str, 0, sizeof(fd_str));
        sprintf(fd_str, "%d\n", fd);
        int ret = execl("./exe1.out", "exe1.out", fd_str, NULL);
        if (-1 == ret)
            perror("execl fail:");
    }

    waitpid(pid, NULL, 0);
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);
    printf("parent, bytes:%d,%s\n\n", bytes, buffer);
}