/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:50:02 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/04 12:58:16 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_parent(t_ppxbonus *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->heredoc)
		unlink(".heredoc.temp");
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->end);
}

void	free_child(t_ppxbonus *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	free(pipex->cmd_args);
	free(pipex->cmd);
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
