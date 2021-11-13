#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1

int main() {
	pid_t pid;
	pid = fork();
	int buffer[BUFFER_SIZE];
	if (pid == 0 ) { /*child process*/
		buffer[0] = 1;
		printf("a zombie process: %u", pid);
		return 0;
	} else if(pid > 0){ /* parent process */
		wait(NULL);
		int a = buffer[0];
		printf("parent complete: %u", a); 
		return 0;
	}
}
