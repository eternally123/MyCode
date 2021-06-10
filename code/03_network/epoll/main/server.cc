#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/epoll.h>
#include <iostream>

#define MAXEVENTS 100

// 创建并初始化连接套接字
int InitSocket()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		return -1;
	}

	struct sockaddr_in ser;
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(11101);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");

	int res = bind(sockfd, (struct sockaddr *)&ser, sizeof(ser));
	if (res == -1)
	{
		return -1;
	}

	res = listen(sockfd, 5);
	if (res == -1)
	{
		return -1;
	}

	return sockfd;
}

// 获取新的客户端链接，并添加到epfd中
void GetNewClient(int fd, int epfd)
{
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);

	int c = accept(fd, (struct sockaddr *)&cli, &len);
	if (c < 0)
	{
		printf("accpet error\n");
		return;
	}

	printf("one client link success\n");

	// 将新的客户端文件描述符添加到内核事件表中
	struct epoll_event events;
	events.data.fd = c;
	events.events = EPOLLIN | EPOLLOUT;

	int res = epoll_ctl(epfd, EPOLL_CTL_ADD, c, &events);
	assert(res != -1);
}

// 处理客户端的数据
void DealClientData(int fd)
{
	char buff[128] = {0};
	int n = recv(fd, buff, 1, 0); // 将接收的字符设置为一个以便观察LT的结果
	//sleep(4);
	if (n <= 0)
	{
		printf("%d recv error\n", fd);
		return;
	}

	printf("%d: %s\n", fd, buff);
	send(fd, "OK", 2, 0);
}

void printEvents(uint32_t event)
{
	std::cout << "events are:"
		  << ((event & EPOLLRDHUP) ? "EPOLLRDHUP " : "")
		  << ((event & EPOLLHUP) ? "EPOLLHUP " : " ")
		  << ((event & EPOLLIN) ? "EPOLLIN " : " ")
		  << ((event & EPOLLOUT) ? "EPOLLOUT " : " ")
		  << std::endl;
}

// 处理就绪事件
void DealFinshEvents(struct epoll_event *events, int n, int epfd, int sockfd)
{
	int i = 0;
	for (; i < n; ++i)
	{
		int fd = events[i].data.fd;
		if (fd == sockfd)
		{
			// 获取新的客户端链接，并添加到epfd中
			GetNewClient(fd, epfd);
			sleep(4);
		}
		else
		{
			printEvents(events[i].events);
			if (events[i].events & EPOLLRDHUP) // 客户端关闭了连接或者写操作
			{
				printf("EPOLLRDHUP happened.\n");
				close(fd);
				// 删除内核事件表中的事件描述符
				epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
			}
			else if (events[i].events & EPOLLHUP)
			{
				printf("EPOLLHUP happened.\n");
				close(fd);
				// 删除内核事件表中的事件描述符
				epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
			}
			else
			{
				// 处理客户端的数据
				DealClientData(fd);
			}
		}
	}
}

int main()
{
	// 创建并初始化连接套接字
	int sockfd = InitSocket();
	assert(sockfd != -1);

	// 创建内核事件表
	int epfd = epoll_create(10);
	assert(epfd != -1);

	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = sockfd;

	// 将sockfd添加到内核事件表
	int res = epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &event);
	assert(res != -1);

	int count = 0; // 用于记录epoll_wait的返回次数
	while (1)
	{
		struct epoll_event events[MAXEVENTS];
		int n = epoll_wait(epfd, events, MAXEVENTS, -1);
		if (n <= 0)
		{
			printf("epoll_wait error\n");
			continue;
		}

		printf("epoll_wait return %d\n", count++);

		// 处理就绪事件
		DealFinshEvents(events, n, epfd, sockfd);
	}
	return 0;
}