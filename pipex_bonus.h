/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:19:10 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/02 17:25:11 by mpeterso         ###   ########.fr       */
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
# define FD_ERR "\033[31mPipe Fd Error\n\e[0m"
# define FORK_ERR "\033[31mFork Error\n\e[0m"
# define CMD_ERR "\033[31mCommand Error\n\e[0m"
# define EXECVE_ERR "\033[31mCommand Error\n\e[0m"

typedef struct s_ppxbonus
{
	pid_t	pid1;
	pid_t	pid2;
	int		heredoc;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		end[2];
	int		infile;
	int		outfile;
}	t_ppxbonus;


int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int 	args_eval(char *argv, t_ppxbonus *pipex);
void    here_doc(char *argv, t_ppxbonus *pipex);
void	get_infile(char **argv, t_ppxbonus *pipex);
void	get_outfile(char **argv, t_ppxbonus *pipex);





char	*get_path(char **envp);
char	*get_command(char **env_paths, char *cmd);
void	child1(t_pipex pipex, char **argv, char **envp);
void	child2(t_pipex pipex, char **argv, char **envp);
/*void	leaks(void);*/
void	error_exit(char *err);

void	free_parent(t_pipex *pipex);
void	close_ends(t_pipex *pipex);
void	exec_children(t_pipex pipex, char *argv[], char *envp[]);

#endif