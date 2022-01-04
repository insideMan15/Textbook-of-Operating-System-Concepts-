**6.7 The pseudocode of Figure 6.15 illustrates the basic push() and pop() operations of an array-based stack. Assuming that this algorithm could be used in a concurrent environment, answer the following questions:**
- a. What data have a race condition?
- b. How could the race condition be fixed?
<br>**Answers**<br>
- a. the variable top. Assume that the top was 3, a push() and a pop() ran simultaneously with such order.
```
stack = {1,2,3,0,0} //---> top = 3
stack[3] = 4 //---> {1,2,3,4,0}, top=3
top-- //---> {1,2,3,4,0}, top=2
return stack[top] //---> {1,2,3,4,0}, top=2, return 3
top++ //---> {1,2,3,4,0}, top=3
```
- b. (1) add mutex lock to top, the value update execution should ask for the mutex lock first and then exectued the update. 
- b. (2) atomical exectuion of top

**6.8 Race conditions are possible in many computer systems. Consider an online auction system where the current highest bid for each item must be maintained. A person who wishes to bid on an item calls the bid(amount) function, which compares the amount being bid to the current highest bid. If the amount exceeds the current highest bid, the highest bid is set to the new amount. This is illustrated below: Describe how a race condition is possible in this situation and what might be done to prevent the race condition from occurring.**
```
void bid(double amount) {
  if (amount > highestBid)
    highestBid = amount;
}
```

<br>**Answers**<br>
Assume two thread A and B run concurrently(both amount greater than the highestBid), it is possible that A and B execute if-condition simulatouesly, A updated the highestBid first but then is replaced by B, where the highestBid becomes 90. The correct value should be 100. It could be solved by adding a mutex-lock for bid().

**6.9 The following program example can be used to sum the array values of size N elements in parallel on a system containing N computing cores (there is a separate processor for each array element):**
```
for j = 1 to log_2(N) {
  for k = 1 to N {
    if ((k + 1) % pow(2,j) == 0) {
      values[k] += values[k - pow(2,(j-1))]
    }
  }
}
```
**This has the effect of summing the elements in the array as a series of partial sums, as shown in Figure 6.16. After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.**
<br>**Answers**<br>
NO race conditions. Because no data sharing exists between processors, each array has own processors.

**6.10 The compare_and_swap() instruction can be used to design lock-free data structures such as stacks, queues, and lists. The program example shown in Figure 6.17 presents a possible solution to a lock-free stack using CAS instructions, where the stack is represented as a linked list of Node elements with top representing the top of the stack. Is this implementation free from race conditions?**
<br>**Answers**<br>
It is free from race condition as both the push() and pop() are CAS instructions.<br>

**6.11 One approach for using compare_and_swap() for implementing a spinlock is as follows:***
```
void lock spinlock(int *lock) {
  while (compare and swap(lock, 0, 1) != 0)
    ; /* spin */
}
```
**A suggested alternative approach is to use the “compare and compare-and-swap” idiom, which checks the status of the lock before invoking the compare_and_swap() operation. (The rationale behind this approach is to invoke compare_and_swap() only if the lock is currently available.) This strategy is shown below:**
```
void lock spinlock(int *lock) {
{
  while (true) {
  if (*lock == 0) {
    /* lock appears to be available */
    if (!compare and swap(lock, 0, 1))
      break;
    }
  }
}
```
**Does this “compare and compare-and-swap” idiom work appropriately for implementing spinlocks? If so, explain. If not, illustrate how the integrity of the lock is compromised.**
<br>**Try Answers**<br>
Ths "compare and compare-and-swap" seems to be useless. Possible reasons:
- "compare" is not atomical

**6.12 Some semaphore implementations provide a function getValue() that returns the current value of a semaphore. This function may, for instance, be invoked prior to calling wait() so that a process will only call wait() if the value of the semaphore is > 0, thereby preventing blocking while waiting for the semaphore. For example:**
```
  if (getValue(&sem) > 0)
    wait(&sem);
```
**Many developers argue against such a function and discourage its use. Describe a potential problem that could occur when using the function getValue() in this scenario.**
<br>**Try Answers**<br>
- The bounded-waiting requirement is not met in such scenario, because wait() is allowed to call only when semaphore > 0
- according to the second requirement, some processes could'n get the lock because it is excluded from the reminder section

**6.13 The first known correct software solution to the critical-section problem for two processes was developed by Dekker. The two processes, P0 and P1, share the following variables:**
```
  boolean flag[2]; /* initially false */
  int turn;
```
**The structure of process Pi (i == 0 or 1) is shown in Figure 6.18. The other process is Pj (j == 1 or 0). Prove that the algorithm satisfies all three requirements for the critical-section problem.**
<br>**Try proving process**<br>
- 1. Mutual exclusion: only the process get the turn could be executed(only one)
- 2. Progress: the entry selection is not indefinitely
- 3. Bounded waiting: if one process finishes the critical-section, it will yield the entry of critical-selection to the other process.


**6.14 The first known correct software solution to the critical-section problem for n processes with a lower bound on waiting of n − 1 turns was presented by Eisenberg andMcGuire. The processes share the following variables:**
```
enum pstate {idle, want in, in cs};
pstate flag[n];
int turn;
```
**All the elements of flag are initially idle. The initial value of turn is immaterial (between 0 and n-1). The structure of process Pi is shown in Figure 6.19. Prove that the algorithm satisfies all three requirements for the critical-section problem.**
<br>**Try proving process**<br>

**6.15 Explain why implementing synchronization primitives by disabling interrupts is not appropriate in a single-processor system if the synchronization primitives are to be used in user-level programs.**
<br>**Try Answers**<br>
The system clock is updated at every clock interrupt. If interrupts were disabled—particularly for a long period of time— the system clock could easily lose the correct time. The system clock is also used for scheduling purposes.

**6.16 Consider how to implement a mutex lock using the compare_and_swap() instruction. Assume that the following structure defining the mutex lock is available:**
```
typedef struct {
  int available;
} lock;
```
**The value (available == 0) indicates that the lock is available, and a value of 1 indicates that the lock is unavailable. Using this struct, illustrate how the following functions can be implemented using the compare_and_swap() instruction:**
- ```void acquire(lock *mutex)```
- ```void release(lock *mutex)```<br>
**Be sure to include any initialization that may be necessary.**
<br>**Try Answers**<br>
```
waiting[n]

void acquire(lock *mutex) {
  while(true) {
    waiting[i] = true;
    while(waiting && compare_and_swap(&lock.available, 0, 1) != 0） 
      ;/* do nothing */
    waiting[i] = false;
  }
}

void release(lock *mutex) {
  lock.available = 0;
  waiting[i] = true;
}
```

**6.17 Explain why interrupts are not appropriate for implementing synchronization primitives in multiprocessor systems.**
<br>Instructions from different process(running on different cores) may be interleaved in some arbitrary way.

**6.18 The implementation of mutex locks provided in Section 6.5 suffers from busy waiting. Describe what changes would be necessary so that a process waiting to acquire a mutex lock would be blocked and placed into a waiting queue until the lock became available.**
<br>**Try Answers**<br>
using contended block..

**6.19 Assume that a system has multiple processing cores. For each of the following scenarios, describe which is a better locking mechanism—a spinlock or a mutex lock where waiting processes sleep while waiting for the lock to become available:**
- a. The lock is to be held for a short duration.
- b. The lock is to be held for a long duration.
- c. A thread may be put to sleep while holding the lock.
<br>**Try Answers**<br>
- a. a spinlock --> No context switch is required in spinlock, which takes long time.
- b. a mutex-lock --> As lock is to be held for a long duration, busy waiting wastes cpu cycles.
- c. a mutex-lock --> The lock would be held for long time, busy waiting is inappropriate.
<br>

**6.20 Assume that a context switch takes T time. Suggest an upper bound (in terms of T) for holding a spinlock. If the spinlock is held for any longer, a mutex lock (where waiting threads are put to sleep) is a better alternative.**
<br>**Try Answers**<br>
**2T..** Given that waiting on a lock requires two context switches—a context switch to move the thread to the waiting state and a second context switch to restore the waiting thread once the lock becomes available—the general rule is to use a spinlock if the lock will be held for a duration of less than two context switches.
<br>

**6.21 A multithreaded web server wishes to keep track of the number of requests it services (known as hits). Consider the two following strategies to prevent a race condition on the variable hits. The first strategy is to use a basic mutex lock when updating hits:**
```
int hits;
mutex_lock hit_lock;
hit_lock.acquire();
hits++;
hit_lock.release();
```
**A second strategy is to use an atomic integer:**
```
atomic_t hits;
atomic_inc(&hits);
```
**Explain which of these two strategies is more efficient.**

**6.22 Consider the code example for allocating and releasing processes shown in Figure 6.20.**
- a. Identify the race condition(s).
- b. Assume you have a mutex lock named mutex with the operations acquire() and release(). Indicatewhere the locking needs to be
placed to prevent the race condition(s).
- c. Could we replace the integer variable 
      <br>```int number of processes = 0```<br>
   with the atomic 
     <br>```integer atomic t number of processes = 0```<br>
  to prevent the race condition(s)?

**6.23 Servers can be designed to limit the number of open connections. For example, a server may wish to have only N socket connections at any point in time. As soon as N connections are made, the server will not accept another incoming connection until an existing connection is released. Illustrate how semaphores can be used by a server to limit the number of concurrent connections.**


**6.24 In Section 6.7, we use the following illustration as an incorrect use of semaphores to solve the critical-section problem:**
```
  wait(mutex);
  ...
  critical section
  ...
  wait(mutex);
```
**Explain why this is an example of a liveness failure.**

**6.25 Demonstrate thatmonitors and semaphores are equivalent to the degree that they can be used to implement solutions to the same types of synchronization problems.**

**6.26 Describe how the signal() operation associated with monitors differs from the corresponding operation defined for semaphores.**

**6.27 Suppose the signal() statement can appear only as the last statement in a monitor function. Suggest how the implementation described in Section 6.7 can be simplified in this situation.**

**6.28 Consider a system consisting of processes P1, P2, ..., Pn, each ofwhich has a unique priority number. Write a monitor that allocates three identical printers to these processes, using the priority numbers for deciding the order of allocation.**

**6.29 A file is to be shared among different processes, each of which has a unique number. The file can be accessed simultaneously by several processes, subject to the following constraint: the sum of all unique numbers associated with all the processes currently accessing the file must be less than n.Write a monitor to coordinate access to the file.**

**6.30 When a signal is performed on a condition inside amonitor, the signaling process can either continue its execution or transfer control to the process that is signaled. How would the solution to the preceding exercise differ
with these two different ways in which signaling can be performed?**

**6.31 Design an algorithm for a monitor that implements an alarm clock that enables a calling program to delay itself for a specified number of time units (ticks). You may assume the existence of a real hardware clock that invokes a function tick() in your monitor at regular intervals.**

**6.32 Discuss ways in which the priority inversion problem could be addressed in a real-time system. Also discuss whether the solutions could be implemented within the context of a proportional share scheduler.**
