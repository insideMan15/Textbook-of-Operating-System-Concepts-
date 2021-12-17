**6.7 The pseudocode of Figure 6.15 illustrates the basic push() and pop() operations of an array-based stack. Assuming that this algorithm could be used in a concurrent environment, answer the following questions:**
- a. What data have a race condition?
- b. How could the race condition be fixed?

**6.8 Race conditions are possible in many computer systems. Consider an online auction system where the current highest bid for each item must be maintained. A person who wishes to bid on an item calls the bid(amount) function, which compares the amount being bid to the current highest bid. If the amount exceeds the current highest bid, the highest bid is set to the new amount. This is illustrated below: Describe how a race condition is possible in this situation and what might be done to prevent the race condition from occurring.**

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
This has the effect of summing the elements in the array as a series of partial sums, as shown in Figure 6.16. After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.

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
