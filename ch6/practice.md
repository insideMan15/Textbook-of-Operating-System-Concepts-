**6.1 In Section 6.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized.**<br>
- System's clock can be kept by interrupts, as HZ specifies the frequency of timer interrupts. By disabling interrupts the timer may not update. This effect could be minimized by setting higher timer value. <br>

**6.2 What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer.**<br>
- Busy waiting: While a process is in its critical section, any other process that tries to enter its critical section must loop continuously in the call to acquire().
- Besides the spinlock, process can also suspend itself. It's another kind of waiting.
- Busy waiting cannot be completely eliminated. It was limited by the wait() and signal(). Anyway, processes need to wait for critical-section to execute their jobs. <br>

**6.3 Explain why spinlocks are not appropriate for single-processor systems yet are often used in multiprocessor systems.**<br>
- As only one processor is shared among many processes, the spinlock would take up the only processor. In the multiprocessor systems, one core is to be held for spinlock which doesn't need context-switch and left processor cores could run other processes.<br>

**6.4 Show that, if the wait() and signal() semaphore operations are not executed atomically, then mutual exclusion may be violated.**<br>
- If two processes execute wait() at the same semaphore at the same time, the waiting queue update is updated by two process simultaneously, which volates the mutual exclusioin.<br>
 
**6.5 Illustrate how a binary semaphore can be used to implement mutual exclusion among n processes.**<br>
- All processes share a binary semaphore variable mutex,which is initialized to 1. Each process must execute wait(mutex) before entering the critical section and signal(mutex) afterward.

**6.6 Race conditions are possible in many computer systems. Consider a banking system that maintains an account balance with two functions: deposit(amount) and withdraw(amount). These two functions are passed the amount that is to be deposited or withdrawn from the bank account balance. Assume that a husband and wife share a bank account. Concurrently, the husband calls the withdraw() function, and the wife calls deposit(). Describe how a race condition is possible and what might be done to prevent the race condition from occurring.**<br>
- Balance amount updating is a critical-section problem. Hence, the balance amount should only be changed by one process. A mutex lock could be added to the account, where other process should wait until the current running process finished. 
