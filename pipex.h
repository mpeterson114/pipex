/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:13:24 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/04 12:40:59 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

# define INFILE_ERR "\033[31mInfile Error\n\e[0m"
# define OUTFILE_ERR "\033[31mOutfile Error\n\e[0m"
# define PIPE_ERR "\033[31mPipe Error\n\e[0m"
# define FORK_ERR "\033[31mFork Error\n\e[0m"
# define CMD_ERR "\033[31mCommand Error\n\e[0m"
# define EXECVE_ERR "\033[31mCommand Error\n\e[0m"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		end[2];
	int		infile;
	int		outfile;
}	t_pipex;

/*string functions*/
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

/*utils*/
char	*get_path(char **envp);
char	*get_command(char **env_paths, char *cmd);
void	error_exit(char *err);
void	free_parent(t_pipex *pipex);
void	close_ends(t_pipex *pipex);

/*functions in main*/
void	child1(t_pipex pipex, char **argv, char **envp);
void	child2(t_pipex pipex, char **argv, char **envp);
void	exec_children(t_pipex pipex, char *argv[], char *envp[]);
/*void	leaks(void);*/

#endif