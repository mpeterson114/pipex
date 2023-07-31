#include "pipex.h"

void    child_process(t_pipex pipex, char **argv, char **envp)
{
    int i;

    i = 0;
    printf("In Child Process\n");
    dup2(pipex.end[1], STDOUT_FILENO);
    close(pipex.end[0]);
    dup2(pipex.infile, STDIN_FILENO);
    pipex.cmd_args = ft_split(argv[2], ' ');
    pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
    if (!pipex.cmd)
    {
        while(pipex.cmd_args[i])
            free(pipex.cmd_args[i++]);
        free(pipex.cmd_args);
        free(pipex.cmd);
        //error message
        //exit(1);
    }
    close(pipex.end[1]);
    if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		exit(1);
}

void    parent_process(t_pipex pipex, char **argv, char **envp)
{
    int i;

    i = 0;
    printf("In Parent Process\n");
    dup2(pipex.end[0], STDIN_FILENO);
    close(pipex.end[1]);
    dup2(pipex.outfile, STDOUT_FILENO);
    pipex.cmd_args = ft_split(argv[3], ' ');
    pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
    if (!pipex.cmd)
    {
        while(pipex.cmd_args[i])
            free(pipex.cmd_args[i++]);
        free(pipex.cmd_args);
        free(pipex.cmd);
        //error message
        //exit(1);
    }
    close(pipex.end[0]);
    if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		exit(1);
}

void	leaks(void)
{
	system("leaks pipex");
}

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    atexit(leaks);
    /*if(argc != 5)
    {
        //error function & message
    }*/
    pipex.infile = open(argv[1], O_RDONLY);
    if (pipex.infile < 0)
    {
        exit(1);
        //error function & message, exit
    }
    pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);  //permissions? test & compare w/shell command outputs later   
    if (pipex.outfile < 0)
    {
        exit(1);
        //error function & message, exit
    }
    if (pipe(pipex.end) < 0)
    {
        exit(1);
    }
        //error fxn-message, exit
    pipex.path = get_path(envp);
    printf("Path is: %s\n", pipex.path);
    pipex.cmd_paths = ft_split(pipex.path, ':');
    /*int i = 0;
    while (pipex.cmd_paths[i])
    {
        printf("Cmd path:%s\n", pipex.cmd_paths[i]);
        i++;
    }*/
    pipex.pid1 = fork();
    printf("Pid: %d\n", pipex.pid1);
    if (pipex.pid1 == 0)
        child_process(pipex, argv, envp);
    waitpid(pipex.pid1, NULL, 0);
    printf("hey\n");
    parent_process(pipex, argv, envp);
    //free parent-close open files
}