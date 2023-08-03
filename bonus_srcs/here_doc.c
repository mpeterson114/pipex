#include "../pipex_bonus.h"

int	args_eval(char *argv, t_ppxbonus *pipex)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
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

void	here_doc(char *argv, t_ppxbonus *pipex)
{
    int		temp_fd;
    int		stdin_fd;
	char	*line;

	temp_fd = open(".heredoc.temp", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		error_exit(HEREDOC_ERR);
	line = "";
	while(1)
	{
		ft_putstr_fd("here_doc >", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (!ft_strncmp(argv, line, ft_strlen(argv + 1)))
			close(stdin_fd);
		else 
			ft_putstr_fd(line, temp_fd);
		free(line);
	}
	close(temp_fd);
}