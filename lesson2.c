/* CPU's have storage locations: Registers
They may store data or instructions
Management of registers is partly the role of the OS
Let us examine a few of the critical registers


A few of the registers in a typical CPU:
Program Counter - Next instruction
Status Register - Array of bits to indicate flags
Instruction register - Instruction most recently fetched.
Stack pointer - Top of the stack
General Purpose Registers - Store data, addresses etc. 

Sources of interrupts: We can put interrupts into four categroies based on their origin:
1 Program
2 Timer
3 Input/Output
4 Hardware Failure 

Interrupts are a way to improve processor utilization.
 CPU time is valuable! When an interrupt take place, the cpu might ignore it (rarely). 
 More commonly: we need to handle it in some way. 
Analogy: Professor in a lecture, student has a question
But if u get an interrupt and want to stop what you are doing and act on it, you need to remember the current state/task you were workign on.
The OS stores the state, handles the interrupt and restores the state.
Sometimes the CPU is in the middle of something uninterruptible. Interrupts may be disabled (temporarily).
Interrupts can have different priorities

The os must store the program state when an interrupt occurs. State: values of registers. Push them onto the tack
Interrrupt finished: restore the state(pop off the stack)
Then execution continues

Trap:
Operating systems run on the basis of interrupts 
A trap is a software generated interrupt
Generated by an error (invalid instruction) or user program request
Sometimes it can be handled, and sometimes it cant

User mode and (Supervisor) Kernel Mode:
Supervisor mode allows all instructions and operations
Even something seeminly simple like reading from disk or writing to console output requries priviledged instructions

These are common operations , but they invovle the OS every time


Modern processors trac waht mode they are in with the mode bit.
At boot up, the computer starts up in kernel mode as the operating system is started and loaded.

User programs are alwasy started in user mode

When a trap or interrupt occurs, and the operating system takes over, the mode bit is set to kernel mode.

When it is finished the system goes back to user mode before the user program reusmes.

There is a definite performance trade off
Switching from user to ernel mode takes time
the performance hit is worht it for the security

*/

//Example: Reading from disk

// ssize_t read(int file_descriptor, void *buffer, size_t count); the function used for reading data from file

//read takes three parameters
//1 the file (a file descriptor from a previous call to open)
//2 Where to read the data to; and
//3 how many bytes to read

//example 
//int bytesRead = read(file, buffer, numBytes); 
//read returns number of bytes succesfully read

//example reading from disk, the OS takes over and control switches to kernel mode, control transfers to a 
//predetermined memory location within the kernel. the trap handler examines the request: it checks the identifier,
//now it knows what system call request handler should execute: read
//that routine executes
//When it is finished, control will be retunered to the read function. Exit the kernel and return to user mode. 
//read finished and returns, and control goes bacl to the user program

//when invoking a system call, the chronological order is as follows:
/* The user program pushes arguments onto the stack
The user program invokes the system call
The system call puts its identifier in the designated location
The system call issues the trap instruction
The os responds to the interrupt and examines the identifier in the designated location
The Os runs the system call handler that matches the identifier
When the handler is finsiehd, control exits the kernel and goes back to the system call (in user mode)
The system call returns control to the user program
