#include "pipex.h"

char *get_path(char **envp)  //try
{
    int i;
    
    i = 0;
    while(ft_strncmp(envp[i], "PATH=", 5))
        i++;
    return (envp[i] + 5);
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
}