#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 0
#define READ_END 0
#define WRITE_END 1

struct timeval tv;

int main(int argc, char *argv[]) {
	long write_msg[BUFFER_SIZE];
	long read_msg[BUFFER_SIZE];
	int fd[2];
	char* command = argv[1];
	pid_t pid;
	
	/*create the pipe*/
	if (pipe(fd) == -1) {
		fprintf(stderr, "Pipe failed");
		return -1;
	}	
	
	pid = fork();
	if (pid == 0) {
		close(fd[READ_END]);
		long sending = tv.tv_usec;
		printf("sending: %lu\n", sending);
		write_msg[0] = sending;
		write(fd[WRITE_END], write_msg, 0);
		execlp(command, command, ".", NULL);
		return 0; 
	} else if (pid > 0) {
		wait(NULL);
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		long diff = tv.tv_usec - read_msg[0];
		printf("receiving: %lu \n", read_msg[0]);
		printf("using time: %lu \n", diff);
	}
	return 0;
}
