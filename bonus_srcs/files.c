#include "../pipex_bonus.h"

void	get_infile(char **argv, t_ppxbonus *pipex)
{
	if(ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argv[2], pipex);        //argv[2] to be able to compare to limiter in heredoc
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			error_exit(INFILE_ERR);
	}
}

void	get_outfile(char **argv, t_ppxbonus *pipex)
{	
	if(pipex->heredoc)
		pipex->outfile = open(argv, O_APPEND | O_CREAT | O_WRONLY, 0644);
	else
		pipex->outfile = open(argv, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->outfile < 0)
			error_exit(OUTFILE_ERR);
}