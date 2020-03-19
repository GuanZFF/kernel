#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define F "file.txt"

int main() {
	int ret = -1;
	
	ret = access(F, F_OK);
	if (ret == -1) {
		perror("access fail");
		return -1;
	}

	ret = mkfifo(F, 0666); 
	if (-1 == ret) {
		perror("mkfifo fail");
		return -1;
	} else {
		printf("mkfifo success\n");
	}

	int fd = -1;
	fd = open(F, O_WRONLY);
	if (-1 == fd) {
		perror("open fail");
		return -1;
	}

	char *buf;
	buf = "guanzhenfeng";
	ret = write(fd, buf, strlen(buf));
	if (ret == -1) {
		perror("write fail");
		return -1;
	}

	return 0;
}
