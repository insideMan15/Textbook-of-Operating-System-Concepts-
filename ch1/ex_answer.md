**Answers**
***
*1.1 three main purpose of OS*
  <1> Provides an environment within which other programs can do useful work
  <2> Ease of use for users
  <3> Resources allocator as system view
  
*1.2*
   E.g: A client-server system, the server need to response each request rapidly. It is always in sake of space for higher response speed. Such a system perform his best for the job.、
   
  *1.3*
  (From p46) A real-time system has well-defined, fixed time constraints. Processing must be done within the defined constraints, or the system will fail.
  
  
*1.4*
Reason for should: Better for system user, improving their convience.
Reason for not: Not a necessary part for kernel. As system view does not allocate resource

*1.5*
Mode bit: A bit is added to the hardware to distinguish user mode(1) and kernel mode(0).
Systems boots in kernel mode. When user program runs, the system always switches to user mode before passing control to a user program.
Privileged instructions: Some instructions may do harm to systems, which can only be executed in kernel mode.

*1.6*
a, c, d, e, g, h

*1.7*
<1> Hard to use system as seperated in a memory partition without access.
<2> 

*1.8*
<1> For more user groups
<2> To support virtualization 

*1.9*
A timer can be set to interrupt the computer after a specified period. The period may be fixed (for example, 1/60 second) or variable (for example, from 1 millisecond to 1 second).
Variable timers ticks and interrupt occurs when it reaches 0. When timers interrupts, control transfers automatically to the OS.

*1.10*
Why Cache useful?
<1> Hold the instructions that CPU to be excuted next, improving speed.
<2> Putting copy of source that would be used again soon
Solving problem
<1> Without this cache, the CPU would have to wait several cycles while an instruction was fetched frommain memory.
Causing problem
<1>Multiple cpus works parallely, so we must ensure cached value is immediatedly reflected in all other caches of cpus.(cache coherency)
Why cannot make it as big as disk?
<1> It would be very difficult to maintain the value in cache.

*1.11*
In client-server systems, every node has only one clear character, either client or server. In contrast, node can be both client and server in p2p system. 

*1.12*
Multiprocessor systems: having more than 2 processors, share the computer bus and sometimes the clock, memory, and peripheral devices.
Clustered systems differ from the multiprocessor systems described in Section 1.3.2 in that they are composed of two or more individual systems—or nodes—joined together; each node is typically a multicore system.
