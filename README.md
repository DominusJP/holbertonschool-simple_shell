QUE ES fork ??????? ACTUALIZAR LATER, GONNA WORK OUT NOW AND WORK SOON AFTER.














What is a process?

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid. To get the process parent id we use: getppid.

Within the same program execution: getpid() will return the same value.
Across different program executions: getpid() will return different values for each execution, as each execution involves a separate process with a unique PID.

In the same regard, running getppid() multiple times within the same program execution will likely give you the same value, but running it across different executions or instances of the program could result in different values.





What is the function getline good for?

To write a program that prints "$ ", waits for the user to enter a command, and prints it on the next line.

HOW DOES getline WORK??????// UPDATE WITH CHATGPT OR OTHER RESOURCE

















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
