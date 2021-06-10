#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(sockfd != -1);

	struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(11101);
	ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int res = connect(sockfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
	assert(res != -1);

	while (1)
	{
		printf("please input: ");
		char buff[128] = {0};
		fgets(buff, 127, stdin);
		if (strncmp(buff, "end", 3) == 0)
		{
			break;
		}

		send(sockfd, buff, strlen(buff) - 1, 0);
		sleep(3);
		shutdown(sockfd, SHUT_WR);
		break;

		char result[128] = {0};
		int n = recv(sockfd, result, 127, 0);
		if (n <= 0)
		{
			break;
		}

		printf("result: %s\n", result);
	}

	close(sockfd);
	exit(0);
}