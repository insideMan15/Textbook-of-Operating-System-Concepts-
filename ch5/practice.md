**Practice Exercises**
***
**5.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.**
- Possible schedule strategies: FCFS, SJF, RR, Priority scheduling, Multilevel queue scheduling, EDF, Proportional share scheduling<br>

***Correction***
- n!

**5.2 Explain the difference between preemptive and nonpreemptive scheduling.**<br>
- preemptive: cpu can be taken away from a process
- nonpreemtive: a process must voluntarily relinquish control of the cpu

**5.3 Suppose that the following processes arrive for execution at the times indicated. Each processwill run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.**
- a. What is the average turnaround time for these processes with the FCFS scheduling algorithm?
- b. What is the average turnaround time for these processes with the SJF scheduling algorithm?
- c. The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling.
**My Answers**
- a::(8+12+13)/3 = 11
- b::(2+6+14)/3 = 7.3 
- c::(2+6+13)/3 = 7

***Correction***


**5.4 Consider the following set of processes, with the length of the CPU burst time given in milliseconds:**
The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.<br>
- a. Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).
- b. What is the turnaround time of each process for each of the scheduling algorithms in part a?
- c. What is the waiting time of each process for each of these scheduling algorithms?
- d. Which of the algorithms results in the minimum average waiting time (over all processes)?
**My Answers**
- a
  - FCFS: 0_P1_2_P2_3_P3_11_P4_15_P5_20
  - SJF: 0_P2_1_P2_3_P4_7_P5_12_P3_20
  - nonpreemptive priority(larger priority by number): 0_P3_8_P2_9_P1_11_P4_15_P5_20 (false)
  - RR(quantum=2): 0_P1_2_P2_3_P3_5_P3_7_P3_9_P3_11_P4_13_P4_15_P5_17_P5_19_P5_20
- b
  - FCFS: (2+3+11+15+20)/5 = 10.2
  - SJF: (1+3+7+12+20)/5 = 8.6
  - nonpreemptive priority: (8+9+11+15+20)/5 = 12.6
  - RR: (2+3+11+15+20)/5 = 10.2
- c
  - FCFS: (0+2+3+11+15)/5 = 6.2
  - SJF: (0+1+3+7+12)/5 = 4.6
  - nonpreemtive priority: (0+8+9+11+15)/5 = 8.6
  - RR: (0+2+3+11+15)/5 = 6.2
- d
  - SJF

***Correction***
- a
 - nonpreemtive priority: 0_P3_8_P5_13_P1_15_P4_19_P2_20
 - RR: 0_P1_2_P2_3_P3_5_P4_7_P5_9_P3_11_P4_13_P5_15_P3_17_P5_18_P3_20 (RR is that the process must release the cpu when its time slice finsihed)
- b
 - nonpreemtive priority: 8+13+15+19+20
 - RR: 2+3+13+18+20
- c
 - nonpreemtive priority: 0+8+13+15+19
 - RR: 0+2+9+12+13
 
**5.5 The following processes are being scheduled using a preemptive, roundrobin scheduling algorithm.**
Each process is assigned a numerical priority,with a higher number indicating a higher relative priority. In addition to the processes listed below, the system also has an idle task (which consumes no CPU resources and is identified as Pidle). This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.
- a. Show the scheduling order of the processes using a Gantt chart.
  - 0_P1_10_P1_20_Pidle_25_P2_35_P2_45_P2_50_P3_60_P4_70_P4_75_P3_85_P3_90_Pidle_100_P5_105_P6_115_P5_120 
- b. What is the turnaround time for each process?
  - P1: 20
  - P2: 25
  - P3: 40
  - P4: 15
  - P5: 20
  - P6: 10
- c. What is the waiting time for each process?
  - P1: 0
  - P2: 0
  - P3: 15
  - P4: 0
  - P5: 10
  - P6: 0
- d. What is the CPU utilization rate?
  - (20+25+25+15+10+10)/120 = 87.5%

***Correction***
- a
  - 0_P1_10_P1_20_IDLE_25_P2_35_P3_45_P2_55_P3_60_P4_75_P2_80_P3_90_IDLE_100_P5_105_P6_115_P5_120
- b
  - P2: 55
  - P3: 60
- c
  - P2: 40
  - P3: 35   

**5.6 What advantage is there in having different time-quantum sizes at different levels of a multilevel queueing system?**
- reduce the context-switching time
***Correction***
- Giving different types of processes with differernt alogrithm for bettew service

**5.7 Many CPU-scheduling algorithms are parameterized. For example, the RR algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithms for each queue, the criteria used to move rocesses between queues, and so on.**<br>
**These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the FCFS algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?**
- a. Priority and SJF
  - SJF is giving less estimated "short process" with higher priority.  
- b. Multilevel feedback queues and FCFS
  - FCFS is used in each level queue of Multilevel feedback queues
- c. Priority and FCFS
  - Using FCFS for same priority processes   
- d. RR and SJF
  - SJF using RR to check whether to switch at each time slice
***Correction***
- c: FCFS gives the highest priority to the job that has been in existence the longest
- d: none

**5.8 Suppose that a CPU scheduling algorithm favors those processes that have used the least processor time in the recent past. Why will this algorithm favor I/O-bound programs and yet not permanently starve CPU-bound programs?**
- I/O bound programs used less processor time so it would be favored
- It could switch to another program when the current running process is waiting I/O.

**5.9 Distinguish between PCS and SCS scheduling**

**5.10 The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second
using the following function:**
  <br>Priority = (recent CPU usage / 2) + base
**where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage for process P1 is 40, for process P2 is 18, and for process P3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?**
- P1: 40/2 + 60 = 80
- P2: 18/2 + 60 = 69
- P3: 10/2 + 60 = 65
- By such alogrithm, the cpu-bound process with higher recent CPU usage 
