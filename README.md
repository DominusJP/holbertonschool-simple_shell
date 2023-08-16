# <a> <img src="https://i.ibb.co/m4nTw6h/Twich-Banner-Offline-Ilustrado-Pastel-Morado-Rosa.png" alt="Twich-Banner-Offline-Ilustrado-Pastel-Morado-Rosa" border="0"> Simple Shell

# Table of Contents

[Description](#description)
[Files](#files)
[System and Library calls](#system-and-library-calls)
[Installation](#installation)
[Xtra](#Xtra)

## Description

In computing, a shell is a computer program that exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.
Command-line shells require the user to be familiar with commands and their calling syntax, and to understand concepts about the shell-specific scripting language (for example, bash)

What is a process?

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid. To get the process parent id we use: getppid.

Within the same program execution: getpid() will return the same value.
Across different program executions: getpid() will return different values for each execution, as each execution involves a separate process with a unique PID.

In the same regard, running getppid() multiple times within the same program execution will likely give you the same value, but running it across different executions or instances of the program could result in different values.


**The Simple Life of a Shell**

1. Begin by Starting the Shell
2. Pause and Await User Input
3. Understand and Break Down User Input
4. Carry Out the Command and Share the Outcome
5. Return to Step 2 for More Actions
* To finish using the shell, simply type the exit command at the prompt or use Ctrl-D, which is seen as the end of the file (EOF)

## Files

**`AUTHORS`** : List of contributors
**`builtins.c.c`** : You can change directories, modify or add environment variables, delete environment variables, and also print the list of environment variables. If you wish to terminate the main loop and exit the shell, you also have that option.
 **`main_functions.c`** : Obtain input from the Command Line Interface and subsequently analyze and carry it out.
**`main.h`** : Header File
**`man_1_simple_shell`** : Manual page of the simple shell
**`tokenizers.c `**Define two functions, simple_tokenizer and tokenizerPath, that take an input string and split it into an array of arguments (tokens) using specific delimiters.
**`validators.c`** This code defines two functions: validateInput and validateSpaces. The validateInput
**`executers.c `**Defines two functions: simple_execute and simple_execute_builtins. The simple_execute function forks a process and replaces the child process with a new program specified by the provided arguments
**`helperFunctions.c `**Includes three functions and a signal handler. The sigintH function handles the SIGINT signal (CTRL + C) by printing a specific message to the standard error output
## System and Library calls

`exit` (man 3 exit)
`fork` (man 2 fork
`close` (man 2 close)
`execve` (man 2 execve)
`wait` (man 2 wait)
`va_start` (man 2 va_start)
`va_arg` (man 2 va_arg)
`va_end` (man 2 va_end)
`strtok` (man 3 strtok)
`getline` (man 3 getline)
`malloc` (man 3 malloc)
`isatty` (man 3 isatty)
`strdup` (man 3 strdup)
`stat` (__xstat) (man 2 stat)
`strcpy` (man 3 strcpy)
`strcat` (man 3 strcat)
`strchr` (man 3 strchr) 
`perror` (man 3 perror)
`open` (man 2 open)

## Installation

Clone this repository to your local machine:

```
$ git clone https://github.com/DominusJP/holbertonschool-simple_shell
```
 Go to the repository folder:

```
$ cd holbertonschool-simple_shell
```

Compile it with :

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Run the shell in interactive mode:

```
$ ./hsh
```
Or  non-interactive mode:

```
$ echo "ls -la" | ./hsh
```

## Xtra

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
