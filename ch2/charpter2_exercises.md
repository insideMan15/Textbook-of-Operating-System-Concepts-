**Charpter 2 Exercises**
***
**2.9 The services and functions provided by an operating system can be
divided into two main categories. Briefly describe the two categories,
and discuss how they differ.**
<a> Processes terminated after completing tasks
<b> Constantly running system-program processes(background process)
  <br>
**2.10 Describe three general methods for passing parameters to the operating system**
  <1> command line
  <2> GUI
  <3> touch screen
    <br>
**2.11 Describe how you could obtain a statistical profile of the amount of time a program spends executing different sections of its code. Discuss the importance of obtaining such a statistical profile.**
  <1> Counters
- Per-Process
  -  **ps**—reports infos for a single process of selection of processes
  - **top**--reports real-time statistics for current processes
- System-Wide
  - vmstat--memory-usage statistics
  - netstat--statistics for network interfaces
  - iostat--I/O usage for disks

<2> Tracing
  - Per-Process
    - strace--traces systems call invoked by a process
    - gdb--a source-level debugger
  - System-Wide
    - perf-a collection of Linux performance tools
    - tcpdump--collects network packets
<br>

  **2.12 What are the advantages and disadvantages of using the same system-call interface for manipulating both files and devices?**
**Advantages**: Easy for system design. Simplify the logic. In fact, the similarity between I/O devices and files is so great that many operating systems, including UNIX , merge the two into a combined file –device structure. In this case, a set of system calls is used on both files and devices. Sometimes, I/O devices are identified by special file names, directory placement, or file
attributes.
**Disadvantages:** 
  
  **2.13 Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?**
  It's possible as system calss provides an interface to the services made available by an OS.
<br>
  
  **2.14 Describe why Android uses ahead-of-time ( AOT ) rather than just-in-time( JIT ) compilation.**
AOT compilation allows more efficient application execution as well as reduced power consumption, features that are crucial for mobile systems.
<br>

**2.15 What are the two models of interprocess communication? What are the strengths and weaknesses of the two approaches?**
- shared memory: suitable for sharing big object, huge resources. The speed is fast. Whereas the diffculty exists in the local and global value update.
- messaging queues: suitable for small object updating. The data security can be proved.
<br>

**2.16 Contrast and compare an application programming interface ( API ) and an application binary interface ( ABI ).**
API: specifing certain functions at the application level
ABI: defining how different components of binary code can interface for a given os on a given architecture, at the architecture level.
<br>
  
**2.17 Why is the separation of mechanism and policy desirable?**
Mechanisms determine how to do something; policies determine what will be done.
The separation of policy and mechanism is important for flexibility. Policies are likely to change across places or over time. In the worst case, each change in policy would require a change in the underlying mechanism. A general mechanism flexible enough to work across a range of policies is preferable. A change in policy would then require redefinition of only certain parameters
of the system.
Policy decisions are important for all resource allocation. Whenever it is necessary to decide whether or not to allocate a resource, a policy decision must be made. Whenever the question is how rather than what, it is a mechanism that must be determined.