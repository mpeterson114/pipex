#include "../pipex_bonus.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (envp[i] + 5);
}

char	*get_command(char **env_paths, char *cmd)
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

void	error_exit(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	free_parent(t_ppxbonus *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	free_pipe(t_ppxbonus *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->heredoc)
		unlink(".heredoc.temp");
	free(pipex->end);
	error_exit(ENVP_ERR);
	exit(1);

}

void	close_ends(t_ppxbonus *pipex)
{
	close(pipex->end[1]);
	close(pipex->end[0]);
}
