#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int ret = -1, fd[2];

	// 通过pipe生成两个文件描述符，fd[0] = r, fd[1] = w
	ret = pipe(fd);
	if (ret == -1) {
		perror("pipe fail");
	}

	printf("fd1 = %d\n", fd[0]);
	printf("fd2 = %d\n", fd[1]);

	pid_t t;

	// fork返回0表示子进程，父进程返回子进程的PID
	t = fork();
	if (t == -1) {
		perror("fork fail");
	}

	// sizeof测试指针时返回地址长度8，不是字符长度
	if (t == 0) {
		printf("I am child. pid = %d\n", getpid());
		ssize_t s = 0;
		char *c;
		c = "guanzhenfeng is a good man!!!";
		s = write(fd[1], c, strlen(c));
		if (s == -1) {
			perror("write fail");
			return -1;
		}

		printf("write size %d\n", s);

		wait(NULL);
	} else {
		printf("I am parent. pid = %d\n", getpid());
		ssize_t s = 0;
		char c[100];
		s = read(fd[0], c, sizeof(c));
		if (-1 == s) {
			perror("read fail");
			return -1;
		}
		printf("read result = %s\n", c);
	}

	return 0;
}
