**Practice Exercises**
***
**4.8 Provide two programming examples in which multithreading does not provide better performance than a single-threaded solution.**<br>
- dependent tasks

**4.9 Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?**<br>
- it could arrange a thread occuping the single processor, while other threads doing I/O or other execution without processor.

**4.10 Which of the following components of program state are shared across threads in a multithreaded process?**<br>
**a. Register values**<br>
**b. Heap memory**  shared<br>
**c. Global variables** shared<br>
**d. Stack memory**<br>

**4.11 Can a multithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than on a single-processor system? Explain.**<br>
Yes. Multiprocessor allows the parallelism exectuion.

**4.12 In Chapter 3, we discussed Google’s Chrome browser and its practice of opening each new tab in a separate process. Would the same benefits have been achieved if, instead, Chrome had been designed to open each new tab in a separate thread? Explain**<br>
No, because separate process has own PCB and own resource.<br>

**4.13 Is it possible to have concurrency but not parallelism? Explain**<br>
Yes, for example the multithread solution in single-processor system as described in 4.8.<br>

**4.14  Using Amdahl’s Law, calculate the speedup gain for the following applications:**
- 40 percent parallel with (a) eight processing cores and (b) sixteen processing cores
- 67 percent parallel with (a) two processing cores and (b) four processing core
- 90 percent parallel with (a) four processing cores and (b) eight processing cores
calculation results:
- a: 1.54 b: 1.6
- a: 1.50 b: 2.01
- a: 3.08 b: 4.71

**4.15 Determine if the following problems exhibit task or data parallelism:**
• Using a separate thread to generate a thumbnail for each photo in a collection
• Transposing a matrix in parallel
• A networked application where one thread reads from the network and another writes to the network
• The fork-join array summation application described in Section 4.5.2
• The Grand Central Dispatch system
