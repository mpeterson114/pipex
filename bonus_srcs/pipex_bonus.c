#include "../pipex_bonus.h"

int main(int argc, char **argv, char **envp)
{
	t_ppxbonus	pipex;
	int			i;

	if (argc < args_eval(argv[1], &pipex))
	{
		ft_putstr_fd("\033[31mError: Incorrect # of args\n\e[0m", 2);
		return(1);
	}
	get_infile(argv, &pipex);
	get_outfile(argv, &pipex);
	pipex.cmd_nbs = argc - 3 - pipex.heredoc;
	pipex.pipe_nbs = 2 * (pipex.cmd_nbs - 1);
	pipex.end = (int *)malloc(sizof(int) * pipex.pipe_nbs);
	if (!pipex.end)
		error_exit(PIPE_ERR);
	pipex.path = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	if (!pipex.cmd_paths)
		free_pipe(&pipex);




}
