# Pipex

This project is a part of the 42 School curriculum. The objective is to recreate the shell pipe mechanism (`|`) using C programming and system calls.

## 📋 About
`pipex` takes four arguments: two files and two shell commands. It reads from the first file, executes the first command with that input, passes the output to the second command, and writes the final result to the second file.

It behaves exactly like the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
🛠️ Usage
Compiling
You can compile the project using the provided Makefile:

Bash
make
Running the program
Bash
./pipex file1 cmd1 cmd2 file2
Example
Bash
./pipex infile "grep a1" "wc -w" outfile
This is equivalent to the shell command:

Bash
< infile grep a1 | wc -w > outfile
⚙️ Skills & Concepts
System Calls & Functions: pipe, fork, dup2, execve, access, waitpid

Process Management: Parent and child processes communication

Error Handling: Managing input/output errors and memory leaks

Developed as a student at 42 School.
