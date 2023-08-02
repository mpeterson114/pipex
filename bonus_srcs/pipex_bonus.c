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
	
