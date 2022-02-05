**7.1 Explain why Windows and Linux implement multiple locking mechanisms. Describe the circumstances under which they use spinlocks, mutexlocks, semaphores, and condition variables.In each case,explain why the mechanism is needed**

**7.2 Windows provides a lightweight synchronization tool called slim reader-writer locks. Whereas most implementation of reader-writer locks favor either readers or writers, or perhaps order waiting threads using a FIFO policy, slim reader-writer locks favor neither readers nor writers, nor are waiting threads ordered in a FIFO queue. Explain the benefits of providing such a synchronization tool.**

**7.3 Describe what changes would be necessary to the producer and consumer processes in Figure 7.1 and Figure 7.2 so that a mutex lock could be used instead of a binary semaphore.**

**7.4 Describe how deadlock is possible with the dining-philosophers problem.**

**7.5 Explain the difference between signaled and non-signaled states with Windows dispatcher objects.**

**7.6 Assume val is an atomic integer in a Linux system. What is the value of val aftrer the following operations have been completed?**
```
atomicset(&val,10);
atomicsub(8,&val);
atomicinc(&val);
atomicinc(&val);
atomicadd(6,&val);
atomicsub(3,&val);
```
