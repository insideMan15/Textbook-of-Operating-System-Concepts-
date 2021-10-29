**Practice_Exercises**
***
**1.1 What are the three main purposes of an operating system?**
  <1> Provides an environment within which other programs can do useful work
  <2> Ease of use for users
  <3> Resources allocator as system view
  $\color{red} correction:$
  <2> As a control programs it servers two major functions: (1) supervision of the execution of user programs to prevent errors and improper use of the computer, and (2) management of the operation and control
of I/O devices 
  <br>
**1.2 We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to “waste” resources? Why is such a system not really wasteful?**

   E.g: A client-server system, the server need to response each request rapidly. It is always in sake of space for higher response speed. Such a system perform his best for the job.
     $\color{red} correction:$
Single-user systems should maximize use of the system for the user. A GUI might “waste” CPU cycles, but it optimizes the user’s interaction with the system.
   <br>
  **1.3 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?**
  (From p46) A real-time system has well-defined, fixed **time constraints**. Processing must be done within the defined constraints, or the system will fail.
  <br>
**1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as Web browsers and mail programs. Argue both that it should and that it should not, and support your answers**
Reason for should: Better for system user, improving their convience.
Reason for not: Not a necessary part for kernel. As system view does not allocate resource
$\color{red} correction:$
Reason for not: (1) the applications are applications - and not part of an
operating system, (2) any performance benefits of running within the
kernel are offset by security vulnerabilities, (3) it leads to a bloated
operating system.
<br>
**1.5 How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security) system?**
Mode bit: A bit is added to the hardware to distinguish user mode(1) and kernel mode(0).
Systems boots in kernel mode. When user program runs, the system always switches to user mode before passing control to a user program.
Privileged instructions: Some instructions may do harm to systems, which can only be executed in kernel mode.
$\color{red} correction:$
Control over when interrupts could be enabled or disabled is also possible only when the CPU is in kernel mode. Consequently, the
CPU has very limited capability when executing in user mode, thereby
enforcing protection of critical resources.

**1.6 Which of the following instructions should be privileged?
a. Set value of timer.
b. Read the clock.
c. Clear memory.
d. Issue a trap instruction.
e. Turn off interrupts.
f. Modify entries in device-status table.
g. Switch from user to kernel mode.
h. Access I/O device.**
a, c, d, e, g, h
$\color{red} correction:$
a,c,e,f,h
Trap is software-generated issue.
f, h are about device-control, which are privileged.

**1.7 Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job
or the operating system itself. Describe two difficulties that you think
could arise with such a scheme.**
<1> Hard to use system as seperated in a memory partition without access.
<2> 
$\color{red} correction:$
The data required by the operating system (passwords, access controls,
accounting information, and so on) would have to be stored in or passed
through unprotected memory and thus be accessible to unauthorized
users.
<br>
**1.8 Some CPU s provide for more than two modes of operation. What are two possible uses of these multiple modes?**
<1> For more user groups
<2> To support virtualization 
$\color{red} correction:$
Another possibility would be to provide different distinctions within
kernel code.
<br>
**1.9 Timers could be used to compute the current time. Provide a short
description of how this could be accomplished.**
A timer can be set to interrupt the computer after a specified period. The period may be fixed (for example, 1/60 second) or variable (for example, from 1 millisecond to 1 second).
Variable timers ticks and interrupt occurs when it reaches 0. When timers interrupts, control transfers automatically to the OS.
<br>
**1.10 Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?**
<1> Hold the instructions that CPU to be excuted next, improving speed.
<2> Putting copy of source that would be used again soon
Solving problem
<1> Without this cache, the CPU would have to wait several cycles while an instruction was fetched frommain memory.
Causing problem
<1>Multiple cpus works parallely, so we must ensure cached value is immediatedly reflected in all other caches of cpus.(cache coherency)
Why cannot make it as big as disk?
<1> It would be very difficult to maintain the value in cache.
$\color{red} correction:$
**Useful caches:** Caches are useful when two or more components need to exchange data, and the components perform transfers at differing speeds. Caches solve the transfer problem by providing a buffer of intermediate speed between the components.
**Data consistent problem:** The data in the cache must
be kept consistent with the data in the components.
**Why not replace components by cache**: <1> the cache couldn't retain as disk(for example) <2> expensive
<br>
**1.11 Distinguish between the client–server and peer-to-peer models of distributed systems.**
In client-server systems, every node has only one clear character, either client or server. In contrast, node can be both client and server in p2p system. 



