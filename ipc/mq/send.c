#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long mtype;
	char mtext[100];
};

int main() {
	struct msgbuf msg;
	msg.mtype = 1;
	strcpy(msg.mtext, "guanzhenfeng is a good man");
	int ret = -1;
	ret = msgsnd(65536, &msg, 100, IPC_NOWAIT);
	if (ret == -1) {
		perror("msgsnd fail");
		return -1;
	}

	printf("msgsnd execute success\n");

	return 0;
}
