**gcc**
```
-> % gcc hello.c -o XXX.o
#generate XXX.o file

-> % gcc hello.c
#generate the default file(a.out) 
```

**shared memory ipc demo**
```
int *value
value = mmap(NULL, sizeof *value, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
pid = fork();
if (pid == 0) {
	*value = 10;
	return 0;
} else if (pid > 0) {
	wait(NULL);
	printf("%u", value); /*value is 10 here*/
}
```


