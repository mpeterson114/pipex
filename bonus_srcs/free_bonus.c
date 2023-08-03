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
	int i;

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