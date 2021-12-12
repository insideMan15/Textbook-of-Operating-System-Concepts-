**5.11 Of these two types of programs:**
- a. I/O-bound
- b. CPU-bound
<br>**which is more likely to have voluntary context switches, and which is more likely to have nonvoluntary context switches? Explain your answer.**<br>
- I/O-bound is more likely to have voluntary context switches, because its occuping processor-time is less and always need to wait for long i/o. So such programs would often yield the cpu voluntarily.
- CPU-bound is more likely to have nonvoluntary context switches, as it takes up cpu for long time. The context switches is always triggered by dispatcher, not itself.

**5.12 Discuss how the following pairs of scheduling criteria conflict in certain settings.**
- a. CPU utilization and response time
- b. Average turnaround time and maximum waiting time
- c. I/O device utilization and CPU utilization
<br>**My answers**<br>
- a: To improve CPU utilization, a system need to reduce the context switches as it result in much cpu idle time. However, at the purpose of having less response time, the system need to handle more requests and reduce the total waiting time, where the context switches will increase.
- b: Average turnaround time would improve the waiting time for the short processes but decrease the waiting time for the long processes. Maximum waiting time doesn't concern such balance.
- c: A program couldn't do I/O and CPU at the same time. Higher CPU utilization means lower I/O device utilization, reversely too.

**5.13 One technique for implementing lottery schedulingworks by assigning processes lottery tickets, which are used for allocating CPU time. Whenever a scheduling decision has to be made, a lottery ticket is chosen at random, and the process holding that ticket gets the CPU. The BTV operating system implements lottery scheduling by holding a lottery 50 times each second, with each lottery winner getting 20 milliseconds of CPU time (20 milliseconds × 50 = 1 second). Describe how the BTV scheduler can ensure that higher-priority threads receive more attention from the CPU than lower-priority threads.**
- Giving higher-priority more lottery tickets.

**5.14 Most scheduling algorithms maintain a run queue,which lists processes eligible to run on a processor. On multicore systems, there are two general options: (1) each processing core has its own run queue, or (2) a single run queue is shared by all processing cores. What are the advantages and disadvantages of each of these approaches?**
- (1) 
  - advantages: less race conditions for differenct processes
  - disadvantages: reducing the total cpu utlization ratio
- (2)
  - advantages: improving the total cpu utlization (if a processor high load, the scheduler could assign jobs to other cores
  - disadvantages: race condition

**5.15 Consider the exponential average formula used to predict the length of the next CPU burst. What are the implications of assigning the following values to the parameters used by the algorithm?
<br>a. α = 0 and τ0 = 100 milliseconds
<br>b. α = 0.99 and τ0 = 10 milliseconds**
- according to:  τn+1 = α tn + (1 − α)τn.
- a. α = 0 -> τn+1 = τn -> τn+1 = τ0 = 100ms. meaning that recent history has no effect on current CPU burst
- b. α = 0.99 -> τn+1 = 0.99tn + 0.01τn, meaning that only the most recent CPU burst matters

**5.16 A variation of the round-robin scheduler is the regressive round-robin scheduler. This scheduler assigns each process a time quantum and a priority. The initial value of a time quantum is 50 milliseconds. However, every time a process has been allocated the CPU and uses its entire time quantum (does not block for I/O), 10 milliseconds is added to its time quantum, and its priority level is boosted. (The time quantum for a process can be increased to a maximum of 100 milliseconds.) When a process blocks before using its entire time quantum, its time quantum is reduced by 5 milliseconds, but its priority remains the same. What type of process (CPU-bound or I/O-bound) does the regressive round-robin scheduler favor? Explain.**
- It favors CPU-bound jobs. As the time quantum of a process could increase by longer block, the priority remains and the time quantum reduce slightly. Which could still get a large time quantum after a longer time quantum.

**5.17 Consider the following set of processes, with the length of the CPU burst given in milliseconds:**
<br>The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.
- a. Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).
- b. What is the turnaround time of each process for each of the scheduling algorithms in part a?
- c. What is the waiting time of each process for each of these scheduling algorithms?
- d. Which of the algorithms results in the minimum average waiting time (over all processes)?
<br>**My answers**
- a time chart:
  - FCFS: 0_P1_5_P2_8_P3_9_P4_16_P5_20
  - SJF: 0_P3_1_P2_4_P5_8_P1_13_P4_20
  - non-preemptive priority: 0_P1_5_P5_9_P3_10_P4_17_P2_20
  - RR(quantum=2): 0_P1_2_P2_4_P3_5_P4_7_P5_9_P1_11_P2_12_P4_14_P5_16_P1_17_P4_19_P4_20
- b turnaround time:
  - FCFS: P1:5, P2:8, P3:9, P4:16, P5:20
  - SJF: P1:13, P2:4, P3:1, P4:20, P5:8
  - non-preemtive priority: P1:5, P2:20, P3:10, P4:17, P5:9
  - RR(quantum=2):  P1:17, P2:12, P3:5, P4:20, P5:16
- c waiting time:
  - FCFS: P1: 0, P2:5, P3: 8, P4: 9, P5:16
  - SJF: P1: 8, P2:1, P3:0, P4:13, P5:4
  - non-preemtive priority: P1:0, P2:17, P3:9, P4:10, P5:5
  - RR(quantum=2): P1:7, P2:7, P3:4, P4:13, P5:12
- d avaerage waiting time:
  - FCFS: (0+5+8+9+16)/5 = 7.6
  - SJF: (8+1+0+13+4)/5 = 5.2 (best solution)
  - non-preemptive priority: (0+17+9+10+5)/5 = 8.2
  - RR(quantum=2): (7+7+4+13+12)/5 = 8.6

**5.18 The following processes are being scheduled using a preemptive, priority-based, round-robin scheduling algorithm.**
Each process is assigned a numerical priority,with a higher number indicating a higher relative priority. The scheduler will execute the highestpriority process. For processes with the same priority, a round-robin scheduler will be used with a time quantum of 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.
- a. Show the scheduling order of the processes using a Gantt chart.
- b. What is the turnaround time for each process?
- c. What is the waiting time for each process?
<br>**My answers**
- a: 0_P1_10_P1_15_P2_20_P3_30_P4_40_P3_45_P5_50_P4_55_P6_65_P6_70_P2_80_P3_85_P4_90_P2_95
- b: P1:15, P2:95, P3:65, P4:65, P5:5, P6:15
- c: P1:0, P2:75, P3:45, P4:45, P5:0, P6:0 

**5.19 The nice command is used to set the nice value of a process on Linux, as well as on other UNIX systems. Explain why some systems may allow any user to assign a process a nice value >= 0 yet allow only the root (or administrator) user to assign nice values < 0.**
- Nice value — Nice values are user-space values that we can use to control the priority of a process. The nice value range is -20 to +19 where -20 is highest, 0 default and +19 is lowest. The system does it because every process wants to get high priority. However, priority improving should only be executed by root. But reducing the priority is open to user, which is good for the system.

**5.20 Which of the following scheduling algorithms could result in starvation?**
- a. First-come, first-served
- b. Shortest job first
- c. Round robin
- d. Priority
**Possible starvation: b, d**

**5.21 Consider a variant of the RR scheduling algorithm in which the entries in the ready queue are pointers to the PCBs.**
- a. What would be the effect of putting two pointers to the same process in the ready queue?
- b. What would be two major advantages and two disadvantages of this scheme?
- c. How would you modify the basic RR algorithm to achieve the same effect without the duplicate pointers?
- **Try Answers**
- PCB is used to save process state, putting two pointers to the same process cause unnecessary state saving and restoring. Duplicate pointers.

**5.22 Consider a system running ten I/O-bound tasks and one CPU-bound task. Assume that the I/O-bound tasks issue an I/O operation once for every millisecond of CPU computing and that each I/O operation takes 10 milliseconds to complete. Also assume that the context-switching overhead is 0.1 millisecond and that all processes are long-running tasks. Describe the CPU utilization for a round-robin scheduler when:**
- a. The time quantum is 1 millisecond   
- b. The time quantum is 10 milliseconds
- **Try Answers**
- a: 1ms-time quantum is good for the I/O-bound tasks as the context switch happens frequently. It could ensure every task get proper CPU slice and avoid starvation.
- b. 10ms-time quantum is good for the CPU-bound tasks. As the major tasks are I/O bound. In this system, the CPU maybe occupied by CPU-bound task for long time. Starvation may happens in some I/O-bound tasks.

**5.23 Consider a system implementing multilevel queue scheduling. What strategy can a computer user employ to maximize the amount of CPU time allocated to the user’s process?**
- Arrange the queue priority by the process running time, long-time process with higher priority

**5.24 Consider a preemptive priority scheduling algorithm based on dynamically changing priorities. Larger priority numbers imply higher priority. When a process is waiting for the CPU (in the ready queue, but not running), its priority changes at a rate α. When it is running, its priority changes at a rate β. All processes are given a priority of 0 when they enter the ready queue. The parameters α and β can be set to give many different scheduling algorithms.**
- a. What is the algorithm that results from β > α > 0?
- b. What is the algorithm that results from α < β < 0?
- a: Round-Robin, process get higher priority after execution. The running process cannot keep its running state.
- b: priority preemptive. The running process would not down as its priority is always higher.

**5.25 Explain the how the following scheduling algorithms discriminate either in favor of or against short processes:**
- a. FCFS
- b. RR
- c. Multilevel feedback queues
- **Try Answers**
- a. FCFS could combines with short-first strategy or with long-first strategy to in favor of or discriminate short process.
- b. RR could reduce the time quantum to in favor of short process or improve the time quantum to against short process.
- c. Arrange the multilevel by estimated running time.

**5.26 Describe why a shared ready queue might suffer from performance problems in an SMP environment.**
- In SMP environment, each processor is self-scheduling We have a possible race condition on the shared ready queue and therefore must ensure that two separate processors do not choose to schedule the same thread and that threads are not lost from the queue.

**5.27 Consider a load-balancing algorithm that ensures that each queue has approximately the same number of threads, independent of priority. How effectively would a priority-based scheduling algorithm handle this situation if one run queue had all high-priority threads and a second queue had all low-priority threads?**
- Balancing the thread numbers of both queues, regardless of the priority.

**5.28 Assume that an SMP system has private, per-processor run queues. When a new process is created, it can be placed in either the same queue as the parent process or a separate queue.**
- a. What are the benefits of placing the new process in the same queue as its parent?
- b. What are the benefits of placing the new process in a different queue?
- **Try Answers**
- a: Better for the new process to share resources with its parent
- b. The new process could run faster without a competitor(the parent process).

**5.29 Assume that a thread has blocked for network I/O and is eligible to run again. Describe why a NUMA-aware scheduling algorithm should reschedule the thread on the same CPU on which it previously ran.**
- Migrating a thread between processors may incur a penalty on NUMAsystems, where a thread may be moved to a processor
that requires longer memory access times.
- The benefit of keeping a thread running on the same processor is that the thread can take advantage of its data being in that processor’s cache memory.

**5.30 Using the Windows scheduling algorithm, determine the numeric priority of each of the following threads.**
- a. A thread in the REALTIME PRIORITY CLASS with a relative priority of NORMAL
- b. A thread in the ABOVE NORMAL PRIORITY CLASS with a relative priority of HIGHEST
- c. A thread in the BELOW NORMAL PRIORITY CLASS with a relative priority of ABOVE NORMAL

**5.31 Assuming that no threads belong to the REALTIME PRIORITY CLASS and that none may be assigned a TIME CRITICAL priority, what combination of priority class and priority corresponds to the highest possible relative priority inWindows scheduling?**

**5.32 Consider the scheduling algorithm in the Solaris operating system for time-sharing threads.**
- a. What is the time quantum (in milliseconds) for a thread with priority 15? With priority 40?
- b. Assume that a thread with priority 50 has used its entire time quantum without blocking. What new priority will the scheduler assign this thread?
- c. Assume that a thread with priority 20 blocks for I/O before its time quantum has

**5.33 Assume that two tasks, A and B, are running on a Linux system. The nice values of A and B are −5 and +5, respectively. Using the CFS scheduler as a guide, describe how the respective values of vruntime vary between the two processes given each of the following scenarios:**
- Both A and B are CPU-bound.
- A is I/O-bound, and B is CPU-bound.
- A is CPU-bound, and B is I/O-bound.
- **Try Answers**
- vruntime: A < B, reason: priority
- vruntime: A << B, reason: priority, A has short CPU-execution period and with higher priority.
- vruntime: A > B: reason: I/O bound with short CPU-period whereas the CPU-bound will exhaust its time period.

**5.34 Provide a specific circumstance that illustrates where rate-monotonic scheduling is inferior to earliest-deadline-first scheduling in meeting real-time process deadlines?**
- A system that must response every request before the deadline, where no time-out is more important than running fast.

**5.35 Consider two processes, P1 and P2, where p1 = 50, t1 = 25, p2 = 75, and t2 = 30.**
- a. Can these two processes be scheduled using rate-monotonic scheduling? Illustrate your answer using a Gantt chart such as the ones in Figure 5.21–Figure 5.24. 
- b. Illustrate the scheduling of these two processes using earliest-deadline-first (EDF) scheduling.
- **Try Answers**
- a. No. rate-monotonic assign p1 higher priority than p2, where p2 will miss the first deadline:::0_P1_25_P2_50_P1_75_P2_80
- b. 0_P1_25_P2_55_P1_80_P2_110_P1_135_P2_165

**5.36 Explain why interrupt and dispatch latency times must be bounded in a hard real-time system.**
- Hard real-time systems have stricter requirements. Atask must be serviced by its deadline; service after the deadline has expired is the same as no service at all.

**5.37 Describe the advantages of using heterogeneous multiprocessing in a mobile system.**
- assign low performance demanding tasks like background tasks to little cores, to preserve a battery charge
- assign interactive but short-running apps to big cores
- if the mobile device is in a power-saving mode, energy-intensive big cores can be disabled and the system can rely solely on energy-efficient little cores
