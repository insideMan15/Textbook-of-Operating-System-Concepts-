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

