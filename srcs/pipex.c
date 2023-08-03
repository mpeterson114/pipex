/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:17:35 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/03 16:21:37 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1(t_pipex pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(pipex.end[1], STDOUT_FILENO);
	close(pipex.end[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		while (pipex.cmd_args[i])
			free(pipex.cmd_args[i++]);
		free(pipex.cmd_args);
		free(pipex.cmd);
		error_exit(CMD_ERR);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_exit(EXECVE_ERR);
}

void	child2(t_pipex pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(pipex.end[0], STDIN_FILENO);
	close(pipex.end[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		while (pipex.cmd_args[i])
			free(pipex.cmd_args[i++]);
		free(pipex.cmd_args);
		free(pipex.cmd);
		error_exit(CMD_ERR);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		error_exit(EXECVE_ERR);
}

/*void	leaks(void)
{
	system("leaks pipex");
}*/

void	exec_children(t_pipex pipex, char *argv[], char *envp[])
{
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		error_exit(FORK_ERR);
	else if (pipex.pid1 == 0)
		child1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		error_exit(FORK_ERR);
	else if (pipex.pid2 == 0)
		child2(pipex, argv, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc == 5)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile < 0)
			error_exit(INFILE_ERR);
		pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (pipex.outfile < 0)
			error_exit(OUTFILE_ERR);
		if (pipe(pipex.end) < 0)
			error_exit(PIPE_ERR);
		//printf("%d\n", pipex.end[0]);
		//printf("%d\n", pipex.end[1]);
		pipex.path = get_path(envp);
		pipex.cmd_paths = ft_split(pipex.path, ':');
		exec_children(pipex, argv, envp);
		close_ends(&pipex);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
		free_parent(&pipex);
	}
	else
		ft_putstr_fd("\033[31mError: Incorrect # of args\n\e[0m", 2);
	return (0);
}
