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
