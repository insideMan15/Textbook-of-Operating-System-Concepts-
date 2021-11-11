**Chartper 3 Exercises**
***
**3.8 Describe the actions taken by a kernel to context-switch between processes.**<br>
When a context switch occurs, the kernel saves the context of the old process in its PCB and loads the saved context of the new process scheduled to run.

**3.9 Construct a process tree similar to Figure 3.7. To obtain process information for the UNIX or Linux system, use the command ps -ael .Use the command man ps to get more information about the ps command. The task manager on Windows systems does not provide the parent process ID , but the process monitor tool, available from tech- net.microsoft.com , provides a process-tree tool.**<br>
do it by command "pstree"

**3.10 Explain the role of the init (or systemd) process on UNIX and Linux systems in regard to process termination.**<br>
- the first user process created when boots<br>
- once the system booted, the systemd process creates processes providing additional services<br>

**3.11 Including the initial parent process, how many processes are created by the program shown in Figure 3.32**<br>
- 12<br>

**3.12 Explain the circumstances under which the line of code marked printf("LINE J") in Figure 3.33 will be reached.**<br>
Excuted when the child process is running.<br>

**3.13 Using the program in Figure 3.34, identify the values of pid at lines A, B, C, and D. (Assume that the actual pids of the parent and child are 2600 and 2603, respectively.)**<br>
- A: 0
- B: 2603
- C: 2600
- D: 2603<br>

**3.14 Give an example of a situation in which ordinary pipes are more suitable than named pipes and an example of a situation in which named pipes are more suitable than ordinary pipes.**<br>
- situation(ordinary > named):
  - Unidirectional communication. 
  - parent-child relationship for process required
- situation(named > ordinary):
  - a named pipe for serveral processes and serveral writers
  - pipe is needed after communication terminated<br>
  
**3.15 Consider the RPC mechanism. Describe the undesirable consequences that could arise from not enforcing either the “at most once” or “exactly once” semantic. Describe possible uses for a mechanism that has neither of these guarantees.**<br>
- possible consequences: when network problems occur, the RPC will executes requests repeatedly.<br>

**3.16 Using the program shown in Figure 3.35, explain what the output will be at lines X and Y.**<br>
- The code block after wait() will executed after all child processes finished. HOWEVER, the processes don't share memory.
- LINE X: CHILD: 0 CHILD: -1 CHILD: -4 CHILD: -9 CHILD: -16
- LINE Y: PARENT: 0 PARENT: 1 PARENT: 2 PARENT: 3 PARENT: 4

**3.17 What are the benefits and the disadvantages of each of the following?Consider both the system level and the programmer level.**<br>
**a. Synchronous and asynchronous communication**<br>
**b. Automatic and explicit buffering**<br>
**c. Send by copy and send by reference**<br>
**d. Fixed-sized and variable-sized messages**<br>



                                                                  

