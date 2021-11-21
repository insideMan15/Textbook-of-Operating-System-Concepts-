**Practice Exercises**
***
**4.8 Provide two programming examples in which multithreading does not provide better performance than a single-threaded solution.**<br>
- dependent tasks

**4.9 Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?**<br>
- it could arrange a thread occuping the single processor, while other threads doing I/O or other execution without processor.

**4.10 Which of the following components of program state are shared across threads in a multithreaded process?**<br>
**a. Register values**<br>
**b. Heap memory**  shared<br>
**c. Global variables** shared<br>
**d. Stack memory**<br>

**4.11 Can a multithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than on a single-processor system? Explain.**<br>
Yes. Multiprocessor allows the parallelism exectuion.

**4.12 In Chapter 3, we discussed Google’s Chrome browser and its practice of opening each new tab in a separate process. Would the same benefits have been achieved if, instead, Chrome had been designed to open each new tab in a separate thread? Explain**<br>
No, because separate process has own PCB and own resource.<br>

**4.13 Is it possible to have concurrency but not parallelism? Explain**<br>
Yes, for example the multithread solution in single-processor system as described in 4.8.<br>

**4.14  Using Amdahl’s Law, calculate the speedup gain for the following applications:**
- 40 percent parallel with (a) eight processing cores and (b) sixteen processing cores
- 67 percent parallel with (a) two processing cores and (b) four processing core
- 90 percent parallel with (a) four processing cores and (b) eight processing cores
calculation results:
- a: 1.54 b: 1.6
- a: 1.50 b: 2.01
- a: 3.08 b: 4.71

**4.15 Determine if the following problems exhibit task or data parallelism:**
• a. Using a separate thread to generate a thumbnail for each photo in a collection
• b. Transposing a matrix in parallel
• c. A networked application where one thread reads from the network and another writes to the network
• d. The fork-join array summation application described in Section 4.5.2
• e. The Grand Central Dispatch system
task paralleism: a, c, e
data paralleism: b, d, <br>

**4.16 A system with two dual-core processors has four processors available for scheduling. A CPU-intensive application is running on this system. All input is performed at program start-up, when a single file must be opened. Similarly, all output is performed just before the program terminates, when the program results must be written to a single file. Between start-up and termination, the program is entirely CPU-bound. Your task is to improve the performance of this application by multithreading it. The application runs on a system that uses the one-to-one threading model (each user thread maps to a kernel thread)**
• How many threads will you create to perform the input and output? Explain.
• How many threads will you create for the CPU-intensive portion of the application? Explain.

**4.17 Consider the following code segment:**
```
pid t pid;
pid = fork();
if (pid == 0) { /* child process */
fork();
thread create( . . .);
}
fork();
```
- a. How many unique processes are created? 4
- b. How many unique threads are create

**4.18 8 As described in Section 4.7.2, Linux does not distinguish between processes and threads. Instead, Linux treats both in the same way, allowing a task to be more akin to a process or a thread depending on the set of flags passed to the clone() system call. However, other operating systems, such as Windows, treat processes and threads differently. Typically, such systems use a notation in which the data structure for a process contains pointers to the separate threads belonging to the process. Contrast these
two approaches for modeling processes and threads within the kernel**
- Not ditinguishing easier for system design

**4.19 The program shown in Figure 4.22 uses the Pthreads API. What would be the output from the program at LINE C and LINE P?**
- LINE C: 5
- LINE P: 0

**4.20 Consider a multicore system and a multithreaded program written using the many-to-many threading model. Let the number of user-level threads in the program be greater than the number of processing cores in the system. Discuss the performance implications of the following scenarios.**
- a. The number of kernel threads allocated to the program is less than the number of processing cores.
- b. The number of kernel threads allocated to the program is equal to the number of processing cores.
- c. The number of kernel threads allocated to the program is greater than the number of processing cores but less than the number of user-level threads.

**4.21 Pthreads provides an API for managing thread cancellation. The pthread setcancelstate() function is used to set the cancellation
state. Its prototype appears as follows:**
```
pthread setcancelstate(int state, int *oldstate)
```
The two possible values for the state are PTHREAD CANCEL ENABLE and PTHREAD CANCEL DISABLE. Using the code segment shown in Figure 4.24, provide examples of two operations that would be suitable to perform between the calls to disable and enable thread cancellation.
