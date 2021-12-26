**6.7 The pseudocode of Figure 6.15 illustrates the basic push() and pop() operations of an array-based stack. Assuming that this algorithm could be used in a concurrent environment, answer the following questions:**
- a. What data have a race condition?
- b. How could the race condition be fixed?
<br>**Answers**
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
<br>**Answers**
Assume two thread A and B run concurrently(both amount greater than the highestBid), it is possible that A and B execute if-condition simulatouesly, A updated the highestBid first but then is replaced by B, where the highestBid becomes 90. The correct value should be 100. It could be solved by adding a mutex-lock for bid().

**6.9 The following program example can be used to sum the array values of size N elements in parallel on a system containing N computing cores
(there is a separate processor for each array element):**
```
for j = 1 to log 2(N) {
  for k = 1 to N {
    if ((k + 1) % pow(2,j) == 0) {
      values[k] += values[k - pow(2,(j-1))]
    }
  }
}
```
**This has the effect of summing the elements in the array as a series of partial sums, as shown in Figure 6.16. After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.**

**6.10 The compare and swap() instruction can be used to design lock-free data structures such as stacks, queues, and lists. The program example shown in Figure 6.17 presents a possible solution to a lock-free stack using CAS instructions, where the stack is represented as a linked list of Node elements with top representing the top of the stack. Is this implementation free from race conditions?**

**6.11 One approach for using compare and swap() for implementing a spinlock is as follows:***
```
void lock spinlock(int *lock) {
  while (compare and swap(lock, 0, 1) != 0)
    ; /* spin */
}
```
**A suggested alternative approach is to use the “compare and compareand-swap” idiom, which checks the status of the lock before invoking the compare and swap() operation. (The rationale behind this approach is to invoke compare and swap()only if the lock is currently available.) This strategy is shown below:**
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
Does this “compare and compare-and-swap” idiom work appropriately for implementing spinlocks? If so, explain. If not, illustrate how the integrity of the lock is compromised.

**6.12 Some semaphore implementations provide a function getValue() that returns the current value of a semaphore. This functionmay, for instance, be invoked prior to calling wait() so that a process will only call wait() if the value of the semaphore is > 0, thereby preventing blocking while waiting for the semaphore. For example:**
```
  if (getValue(&sem) > 0)
    wait(&sem);
```
**Many developers argue against such a function and discourage its use. Describe a potential problem that could occur when using the function getValue() in this scenario.**

**6.13 The first known correct software solution to the critical-section problem for two processes was developed by Dekker. The two processes, P0 and P1, share the following variables:**
```
  boolean flag[2]; /* initially false */
  int turn;
```
**The structure of process Pi (i == 0 or 1) is shown in Figure 6.18. The other process is Pj (j == 1 or 0). Prove that the algorithm satisfies all three requirements for the critical-section problem.**

**6.14 The first known correct software solution to the critical-section problem for n processes with a lower bound on waiting of n − 1 turns was presented by Eisenberg andMcGuire. The processes share the following variables:**
```
enum pstate {idle, want in, in cs};
pstate flag[n];
int turn;
```
**All the elements of flag are initially idle. The initial value of turn is immaterial (between 0 and n-1). The structure of process Pi is shown in Figure 6.19. Prove that the algorithm satisfies all three requirements for the critical-section problem.**

**6.15 Explain why implementing synchronization primitives by disabling interrupts is not appropriate in a single-processor system if the synchronization primitives are to be used in user-level programs.**

**6.16 Consider how to implement a mutex lock using the compare and swap() instruction. Assume that the following structure defining the mutex lock is available:**
```
typedef struct {
int available;
} lock;
```
**The value (available == 0) indicates that the lock is available, and a value of 1 indicates that the lock is unavailable. Using this struct, illustrate how the following functions can be implemented using the compare and swap() instruction:**
- ```void acquire(lock *mutex)```
- ```void release(lock *mutex)```<br>
**Be sure to include any initialization that may be necessary.**

**6.17 Explain why interrupts are not appropriate for implementing synchronization primitives in multiprocessor systems.**

**6.18 The implementation of mutex locks provided in Section 6.5 suffers from busy waiting. Describe what changes would be necessary so that a process waiting to acquire a mutex lock would be blocked and placed into a waiting queue until the lock became available.**

**6.19 Assume that a system has multiple processing cores. For each of the following scenarios, describe which is a better locking mechanism—a spinlock or a mutex lock where waiting processes sleep while waiting for the lock to become available:**
- The lock is to be held for a short duration.
- The lock is to be held for a long duration.
- Athread may be put to sleep while holding the lock.

**6.20 Assume that a context switch takes T time. Suggest an upper bound (in terms of T) for holding a spinlock. If the spinlock is held for any longer, a mutex lock (where waiting threads are put to sleep) is a better alternative.**

**6.21 A multithreaded web server wishes to keep track of the number of requests it services (known as hits). Consider the two following strategies to prevent a race condition on the variable hits. The first strategy is to use a basic mutex lock when updating hits:**
```
int hits;
mutex lock hit lock;
hit lock.acquire();
hits++;
hit lock.release();
```
**Asecond strategy is to use an atomic integer:**
```
atomic t hits;
atomic inc(&hits);
```
**Explain which of these two strategies is more efficient.**

**6.20 Consider the code example for allocating and releasing processes shown  in Figure 6.20.**
- a. Identify the race condition(s).
- b. Assume you have a mutex lock named mutex with the operations acquire() and release(). Indicatewhere the locking needs to be
placed to prevent the race condition(s).
- c. Could we replace the integer variable 
      <br>```int number of processes = 0```<br>
   with the atomic 
     <br>```integer atomic t number of processes = 0```<br>
  to prevent the race condition(s)?
