#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
	int ret = -1;
	ret = semget(IPC_PRIVATE, 2, IPC_CREAT | IPC_EXCL);
	if (ret == -1) {
		perror("semget fail");
		return 0;
	}

	printf("semaphore created successfully\n");

	return 0;
}
