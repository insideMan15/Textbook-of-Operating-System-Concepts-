**Practice Exercises**
***
**2.1 What is the purpose of system calls?**<br>
Providing an interface to the services made available by an OS.<br>

**2.2 What is the purpose of the command interpreter? Why is it usually separate from the kernel?**<br>
Purpose of command interpreter: Allowing users to directly enter commands to be performed by the OS. It is so called User and OS interface.
Most operating systems, including Linux, UNIX , and Windows, treat the command interpreter as a special program that is running when a process is initiated or when a user first logs on (on interactive systems). Command Interpreters have different variations.
**correction**<br>
Command interpreter is usually not part of the kernel since the CI is subject to changes.
<br>

**2.3 What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?**<br>
Process control
**correction**<br>
In Unix systems, a fork system call followed by an exec system call need to be performed to start a new process. The fork call clones the currently executing process, while the exec call overlays a new process based on a different executable over the calling process.
<br>

**2.4 What is the purpose of system programs?**<br>
System services, also known as system utilities,
provide a convenient environment for program development and execution.
**correction**<br>
System programs can be thought of as bundles of useful system calls. They provide basic functionality to users so that users do not need to write their own programs to solve common problems.
<br>

**2.5 What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?**<br>
The Main Advantage: Simplicity of construction and debugging. The layers are selected so that each uses functions (operations) and services of only lower-level layers.
Disadvantage:The overhead of requiring a user program to traverse through multiple layers to obtain an operating-system service
<br>

**2.6 List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.**<br>
**correction**<br>
The five services are:<br>
**a. Program execution**. The operating system loads the contents (orsections) of a file into memory and begins its execution. A user-level program could not be trusted to properly allocate CPU time.<br>
**b. I/O operations**. Disks, tapes, serial lines, and other devices must be communicated with at a very low level. The user need only specify the device and the operation to perform on it, while the system converts that request into device- or controller-specific commands. User-level programs cannot be trusted to access only devices they should have access to and to access them only when they are otherwise unused.<br>
**c. File-system manipulation**. There are many details in file creation, deletion, allocation, and naming that users should not have to perform. Blocks of disk space are used by files and must be tracked. Deleting a file requires removing the name file information and freeing the allocated blocks. Protections must also be checked to assure proper file access. User programs could neither ensure adherence to protection methods nor be trusted to allocate only free blocks and deallocate blocks on file deletion.<br>
**d. Communications**. Message passing between systems requires messages to be turned into packets of information, sent to the network controller, transmitted across a communications medium, and reassembled by the destination system. Packet ordering and data correction must take place. Again, user programs might not coordinate access to the network device, or they might receive packets destined for other processes.<br>
**e. Error detection**. Error detection occurs at both the hardware and software levels. At the hardware level, all data transfers must be inspected to ensure that data have not been corrupted in transit. All data on media must be checked to be sure they have not changed since they were written to the media. At the software level, media must be checked for data consistency; for instance, whether the number of allocated and unallocated blocks of storage match the total number on the device. There, errors are frequently processindependent (for instance, the corruption of data on a disk), so there must be a global program (the operating system) that handles all types of errors. Also, by having errors processed by the operating system, processes need not contain code to catch and correct all the errors possible on a system.<br>


**2.7 Why do some systems store the operating system in firmware, while others store it on disk?**<br>
**correction**<br>
For certain devices, such as handheld PDAs and cellular telephones, a disk with a file system may be not be available for the device. In this situation, the operating system must be stored in firmware.
<br> 

**2.8 How could a system be designed to allow a choice of operating systemsfrom which to boot? What would the bootstrap program need to do?**<br>
**correction**<br>
Consider a system that would like to run both Windows XP and three different distributions of Linux (e.g., RedHat, Debian, and Mandrake). Each operating system will be stored on disk. During system boot-up, a special program (which we will call the boot manager) will determine which operating system to boot into. This means that rather initially booting to an operating system, the boot manager will first run during system startup. It is this boot manager that is responsible for determining which system to boot into. Typically boot managers must be stored at certain locations of the hard disk to be recognized during system startup. Boot managers often provide the user with a selection of systems to boot into; boot managers are also typically designed to boot into a default operating system if no choice is selected by the user.
