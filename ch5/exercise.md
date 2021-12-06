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

**5.21 Consider a variant of the RR scheduling algorithm in which the entries in the ready queue are pointers to the PCBs.
- a. What would be the effect of putting two pointers to the same process in the ready queue?
- b. What would be two major advantages and two disadvantages of this scheme?
- c. Howwould youmodify the basic RR algorithm to achieve the same effect without the duplicate pointers?**
