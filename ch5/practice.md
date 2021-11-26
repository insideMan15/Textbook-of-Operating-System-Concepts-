**Practice Exercises**
***
**5.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.**
- Possible schedule strategies: FCFS, SJF, RR, Priority scheduling, Multilevel queue scheduling, EDF, Proportional share scheduling<br>

**5.2 Explain the difference between preemptive and nonpreemptive scheduling.**<br>
- preemptive: cpu can be taken away from a process
- nonpreemtive: a process must voluntarily relinquish control of the cpu

**5.3 Suppose that the following processes arrive for execution at the times indicated. Each processwill run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.**
- a. What is the average turnaround time for these processes with the FCFS scheduling algorithm?
- b. What is the average turnaround time for these processes with the SJF scheduling algorithm?
- c. The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling.
