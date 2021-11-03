#include <stdio.h>
#define N 100

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("The argument supplied should be 2!\n");
		return -1;
	}
	
	/*receive two files from cmd line*/
	char *source = argv[1];
	char *target = argv[2];
	
	FILE *fp = NULL;
	
	/*break if source is NULL*/
	fp = fopen(source, "r");
	if (fp == NULL) {
		printf("Source file doesn't exist!\n");
		return -1;
	}
	
	char str[N+1];
	int c;
	FILE *tp = NULL;
	tp = fopen(target, "w");
	while(fgets(str, N, fp) != NULL) {
		fputs(str, tp);
	}
	fclose(fp);
	fclose(tp);
	printf("Source file copied!");
	return 0;
}
