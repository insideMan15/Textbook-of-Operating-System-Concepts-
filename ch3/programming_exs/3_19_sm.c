#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1

struct timeval current;

int main(int argc, char* argv[]) {
	pid_t pid;
	char* command = argv[1];
	long *startStamp;
	long nowStamp;
	startStamp = mmap(NULL, sizeof *startStamp, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    struct timeval tv;
	pid = fork();
	if (pid == 0) {
		*startStamp = tv.tv_sec;
		printf("st: %lu \n", *startStamp);
		execlp(command, command, ".", NULL);	
		return 0;
	} else if (pid > 0) {
		nowStamp = tv.tv_sec;
		wait(NULL);
		printf("et: %lu \n", nowStamp);
		printf("used time:%lu \n", (nowStamp-*startStamp)/1000);
		return 0;
	}
}
