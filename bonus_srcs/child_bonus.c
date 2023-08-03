#include "../pipex_bonus.h"

static char	*get_command(char **env_paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*env_paths)
	{
		temp = ft_strjoin(*env_paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		env_paths++;
	}
	return (NULL);
}

/*way to simplify dup2 process for child fxn, first repetition redirects to stdin & 
second rep redirects to stdout*/
static void sub_dup2(int zero, int one)
{
    dup2(zero, STDIN_FILENO);
    dup2(one, STDOUT_FILENO);
}

/*Redirects file descriptor inputs and outputs (read & write ends) 
according to command index, then separates each component of each command 
using ft_split and searches the envp paths for the correct command path using
access() in get_command()*/
void    child(t_ppxbonus pipex, char **argv, char **envp)
{
    if (pipex.pid == fork() < 0)
        error_exit(FORK_ERR);
    else if (!pipex.pid)
    {
        if (pipex.index == 0)
            sub_dup2(pipex.infile, pipex.end[2 * pipex.index + 1]);
        else if (pipex.index == pipex.cmd_nbs - 1)
            sub_dup2(pipex.end[2 * pipex.index - 2], pipex.outfile);
        else
            sub_dup2(pipex.end[2 * pipex.index - 2], pipex.end[2 * pipex.index + 1]);
        close_ends(&pipex);
        pipex.cmd_args = ft_split(argv[2 + pipex.heredoc + pipex.index], ' ');
        pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
        if (!pipex.cmd)
	    {
		    free_child(&pipex);
		    error_exit(CMD_ERR);
	    }
        if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		    error_exit(EXECVE_ERR);
    }
}