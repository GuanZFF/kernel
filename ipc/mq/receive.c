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
	struct msgbuf m;
	int ret = -1;
	ret = msgrcv(32769, &m, 100, 0, IPC_NOWAIT);
	if (ret == -1) {
		perror("msgrcv fail");
		return -1;
	}

	printf("message = %s\n", m.mtext);

	return 0;
}
