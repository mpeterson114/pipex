#include "../pipex.h"

void	child_process(t_pipex pipex, char **argv, char **envp)
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
	    error_exit(CMD_ERR);
	}
	close(pipex.end[1]);
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_exit(EXECVE_ERR);
}

void	parent_process(t_pipex pipex, char **argv, char **envp)
{
	int i;	
	i = 0;
	//atexit(leaks);
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
		error_exit(CMD_ERR);
	}
	close(pipex.end[0]);
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_exit(EXECVE_ERR);
}

void	leaks(void)
{
	system("leaks pipex");
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;

	atexit(leaks);
	if(argc == 5)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		//pipex.infile = -1;
		if (pipex.infile < 0)
			error_exit(INFILE_ERR);
		pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644); 
		//pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000);  //still works, O_RDWR overrides 0000 permissions
		//pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT, 0000); //here will not work, nothing will be written to outfile
		//pipex.outfile = -1;   
		if (pipex.outfile < 0)
			error_exit(OUTFILE_ERR);
		if (pipe(pipex.end) < 0)
			error_exit(FD_ERR);
		pipex.path = get_path(envp);
		pipex.cmd_paths = ft_split(pipex.path, ':');
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			error_exit(FORK_ERR);
		else if (pipex.pid1 == 0)
			child_process(pipex, argv, envp);
		waitpid(pipex.pid1, NULL, 0);
		parent_process(pipex, argv, envp);
		//free parent-close open files??-opened files are already being closed at end of parent fxn
	}
	else 
		ft_putstr_fd("\033[31mError: Incorrect # of args\n\e[0m", 2);
	return(0);
}
