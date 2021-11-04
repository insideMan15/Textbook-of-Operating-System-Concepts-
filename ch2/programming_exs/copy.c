#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("The argument supplied should be 3!\n");
		return -1;
	}
	
	/*receive two files from cmd line*/
	char *source = argv[1];
	char *target = argv[2];
	
	FILE *fp = NULL;
	/*break if source is NULL*/
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Source file doesn't exist!\n");
		return -1;
	}
	
	FILE *tp = NULL;
	tp = fopen(target, "w");
	char ch;
	do {
		ch = fgetc(fp); 
		fputc(ch, tp);
	} while(ch != EOF);
	fclose(fp);
	fclose(tp);
	printf("Source file: %s copied!\n", source);
	return 0;
}
