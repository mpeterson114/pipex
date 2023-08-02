#include "../pipex_bonus.h"

int args_eval(char *argv, t_ppxbonus *pipex)
{
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        pipex->heredoc = 1;
        return (6);
    }
    else
    {
        pipex->heredoc = 0;
        return (5);
    }
}

void    here_doc(char *argv, t_ppxbonus *pipex)
{
    int file;
    
}