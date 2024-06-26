/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:19:10 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/04 12:59:20 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "./gnl/get_next_line.h"

# define INFILE_ERR "\033[31mInfile Error\n\e[0m"
# define OUTFILE_ERR "\033[31mOutfile Error\n\e[0m"
# define PIPE_ERR "\033[31mPipe Error\n\e[0m"
# define FORK_ERR "\033[31mFork Error\n\e[0m"
# define CMD_ERR "\033[31mCommand Error\n\e[0m"
# define EXECVE_ERR "\033[31mExecve Error\n\e[0m"
# define HEREDOC_ERR "\033[31mHeredoc Error\n\e[0m"
# define ENVP_ERR "\033[31mENVP Path Error\n\e[0m"

typedef struct s_ppxbonus
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		heredoc;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_nbs;
	int		pipe_nbs;
	int		*end;
	int		index;
}	t_ppxbonus;

/*string functions*/
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

/*file management*/
void	get_infile(char **argv, t_ppxbonus *pipex);
void	get_outfile(char *argv, t_ppxbonus *pipex);

/*heredoc functions*/
int		args_eval(char *argv, t_ppxbonus *pipex);
void	here_doc(char *argv, t_ppxbonus *pipex);

/*child*/
void	child(t_ppxbonus pipex, char **argv, char **envp);

/*utils_bonus*/
char	*get_path(char **envp);
void	error_exit(char *err);

/*free*/
void	free_pipe(t_ppxbonus *pipex);
void	free_child(t_ppxbonus *pipex);
void	free_parent(t_ppxbonus *pipex);

/*functions in main*/
void	leaks(void);
void	close_ends(t_ppxbonus *pipex);
void	init_children(t_ppxbonus pipex, char **argv, char **envp);

#endif