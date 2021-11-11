#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1

int main() {
	pid_t pid;
	pid = fork();
	int buff[BUFFER_SIZE];
	if (pid == 0 ) { /*child process*/
		fprintf("a zombie process: %u", pid);
		return 0;
	} else if(pid > 0){ /* parent process */
		sleep(10);
		fprintf("parent complete: %u", pid); /* LINE A */
		return 0;
	}
}
