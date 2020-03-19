#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	int ret = -1;

	ret = msgget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL);
	if (ret == -1) {
		perror("msgget fail");
		return -1;
	}

	printf("msgget execute success\n");

	return 0;
}
