#include <sys/syscall.h>
#include <pthread.h>
#include <stdio.h>

void *func(void *args) {
	pid_t id;
	id = (pid_t) syscall (SYS_gettid);

	printf("%d\n", id);
}

int main() {
	pthread_t t[10];

	for (int i = 0; i < 10; i++) {
		pthread_create(&t[i], NULL, func, (void *) NULL);
		pthread_join(t[i], NULL);
	}

	return 0;
}
