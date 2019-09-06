#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t func_thread;
pthread_mutex_t lock;

void *func() {
	printf("[FUNC] Waiting for lock...\n");

	pthread_mutex_lock(&lock);

	printf("[FUNC] Acquired lock. Starting task 2...\n");
	sleep(20);

	pthread_mutex_unlock(&lock);

	printf("[FUNC] Task 2 finished. Returning to main...\n");
}

int main() {
	printf("[MAIN] Main started. Acquiring mutex...\n");

	if (pthread_mutex_init(&lock, NULL)) {
		printf("[MAIN] ERROR: mutex could not be initialised. Exiting...\n");
		exit(-1);
	}

	pthread_mutex_lock(&lock);
	pthread_create(&func_thread, NULL, func, NULL);

	printf("[MAIN] Doing task 1 before giving the lock away to func...\n");

	sleep(10);

	printf("[MAIN] Task 1 finished. Releasing lock...\n");

	pthread_mutex_unlock(&lock);
	pthread_join(func_thread, NULL);

	pthread_mutex_destroy(&lock);

	printf("[MAIN] Exiting...\n");

	return(0);
}
