#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = IPC_NOWAIT;

	int ret = -1;
	ret = semop(65537, &buf, 1);
	if (ret == -1) {
		perror("semop fail");
		return 0;
	}

	printf("semop operate successfully\n");

	return 0;
}
