**Practice Exercises**
***
**3.1 Using the program shown in Figure 3.30, explain what the output will be at LINE A.**<br>
Discuss by different conditions<br>
**Correction**<br>
The result is still 5 as the child updates its copy of value. When control returns to the parent, its value remains at 5.

**3.2 Including the initial parent process, how many processes are created by the program shown in Figure 3.31?**<br>
8 processes

**3.3 Original versions of Apple’s mobile iOS operating system provided no means of concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.**<br>

**3.4 Some computer systems provide multiple register sets. Describe what happens when a context switch occurs if the new context is already loaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?**<br>
A: Changing the pointer to the current register set.
B: The system resorts to copying register data to and from memory. Then as A.<br>
**Correction**<br>
The CPU current-register-set pointer is changed to point to the set containing the new context, which takes very little time. If the context is in memory, one of the contexts in a register set must be chosen and be moved to memory, and the new context must be loaded from memory into the set. This process takes a little more time than on systems with one set of registers, depending on how a replacement victim is selected.<br>

**3.5 When a process creates a newprocess using the fork() operation, which of the following states is shared between the parent process and the child process?**<br>
a. Stack(NO)<br>
b. Heap(NO)<br>
c. Shared memory segments(YES)<br>

**3.6 Consider the “exactly once”semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a network problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.**<br>
As each message is attached with a timestamp, the execution happens only once even if the ACK message lost. The client would resend a message with different timestamp. The "exactly once" should be preserved for improving the server responding speed.<br>
**Correction**<br>
If ACK message lost due to the network problem, the server will receive a duplicated RPC(identified by the timestamp), so it will not perform execution.

**3.7 Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPCs?**<br>
- The client must resend each RPC call periodically until it receives the ACK for that call.
- This semantic can be implemented by attaching a timestamp to each message. The server must keep a history of all the
timestamps of messages it has already processed or a history large enough to ensure that repeated messages are detected.<br>
**Correction**<br>
The server should keep track in stable storage (such as a disk log) information regarding what RPC operations were received, whether they were successfully performed, and the results associated with the operations. When a server crash takes place and a RPC message is received, the server can check whether the RPC had been previously performed and therefore guarantee “exactly once” semanctics for the execution of RPCs.

                                                                  

