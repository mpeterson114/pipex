/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:17:43 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/01 18:45:07 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	free_parent(t_pipex *pipex)
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

void	close_ends(t_pipex *pipex)
{
	close(pipex->end[1]);
	close(pipex->end[0]);
}
