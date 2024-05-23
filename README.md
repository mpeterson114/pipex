# 🔗 Pipex
> C program that replicates the shell's pipe '|' functionality. Implemented using C and various system calls, such as fork, pipe, dup2, and execve.

The program reads input from a file, runs two commands as separate child processes, and then sends the output of the first command as input to the second command. The output is then written to another file. 

The program should mimick the behavior of the following shell command:

```< file1 cmd1 | cmd2 > file2```

## ⚙️ Usage
### Mandatory Part
Enter into the cloned repository and compile with ```make```

Execute using the following syntax:
```
./pipex input_file cmd1 cmd2 output_file
```

The output will be written to the specified output file. If the output file already exists, its contents will be overwritten.

### Bonus Part
Inside the cloned repository, compile with ```make bonus```

Execute with two or more commands:
```
./pipex input_file cmd1 cmd2 ... cmdN output_file
```
You can also execute the bonus portion with a Heredoc:
```
./pipex here_doc LIMITER cmd1 cmd2 ... cmdN output_file
```
You will then be prompted to input text which will be used as input for the commands. The result will be appended to the output file, rather than overwriting its contents.



