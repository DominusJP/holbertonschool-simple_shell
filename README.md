What is a process?

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid. To get the process parent id we use: getppid.

Within the same program execution: getpid() will return the same value.
Across different program executions: getpid() will return different values for each execution, as each execution involves a separate process with a unique PID.

In the same regard, running getppid() multiple times within the same program execution will likely give you the same value, but running it across different executions or instances of the program could result in different values.





What is the function getline good for?

To write a program that prints "$ ", waits for the user to enter a command, and prints it on the next line.





What is strtok good for?

To write a function that splits a string and returns an array of each word of the string.





Executing a program:

The system call execve allows a process to execute another program (man 2 execve). Note that this system call does load the new program into the current process’ memory in place of the “previous” program: on success execve does not return to continue the rest of the “previous” program.





Creating processes

The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process that calls fork). Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.





What is wait good for?

The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.





What is stat good for?

The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.





What is _wich filename good for?

To write a program that looks for files in the current PATH.





Main function prototypes we may use:

int main(void);
int main(int ac, char **av);
int main(int ac, char **av, char **env);


Where:

ac: Number of items on av.

av: a NULL terminated array of strings. av[0] usualy contains the name used to invoke the current program and av[1], av[2] and so on contain the actual arguments of the program.

env: Array of environment variables.


Note that:

In a program, environment variables are like little notes that the operating system keeps to tell the program something important about its execution environment. For instance, they might contain information about the current username, the location of certain files, or specific configurations.

In this main function, env contains information about the system's environment variables. By adding char **env as a parameter, you allow your program to access and utilize these variables. This could be helpful if your program needs to adjust its behavior based on the environment it's running in.

For example, imagine a program that needs to know the user's home directory to save files there. Instead of asking the user to manually input that information, your program could query the "HOME" environment variable and automatically obtain the home directory.

In summary, char **env gives you access to the system's environment variables, which can be useful for tailoring your program's behavior based on the environment it's running in.
