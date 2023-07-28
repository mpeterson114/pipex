#include "pipex.h"

void    child_process(t_pipex pipex, char **argv, char **envp)
{
    int i;

    i = 0;
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
    execve(pipex.cmd, pipex.cmd_args, envp);
}

void    parent_process(t_pipex pipex, char **argv, char **envp)
{
    int i;

    i = 0;
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
    //execute fxn w/ (argv[3])
    //execve(pipex.cmd, pipex.cmd_args, envp);       or enough to just leave execve out of parent?
}





int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    if(argc != 5)
    {
        //error function & message
    }
    pipex.infile = open(argv[1], O_RDONLY);
    if (pipex.infile < 0)
    {
        //error function & message, exit
    }
    pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);  //permissions? test & compare w/shell command outputs later   
    if (pipex.outfile < 0)
    {
        //error function & message, exit
    }
    if (pipe(pipex.end) < 0)
        //error fxn-message, exit
    pipex.path = get_path(envp);
    pipex.cmd_paths = ft_split(pipex.path, ':');
    pipex.pid1 = fork();
    if (pipex.pid1 == 0)
        //child process
        
    waitpid(pipex.pid1, NULL, 0);
    parent_process(pipex, argv, envp);
    //free parent-close open files
}