/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:13:24 by mpeterso          #+#    #+#             */
/*   Updated: 2023/07/31 12:40:54 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
//# include <sys/types.h>
//# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include "./gnl/get_next_line.h"

typedef struct s_pipex
{
    pid_t pid1;
    int end[2];
    int infile;
    int outfile;
    char *path;
    char **cmd_paths;
    char **cmd_args;
    char *cmd;
} t_pipex;

int ft_strlen(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t len);
char *get_path(char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_command(char **env_paths, char *cmd);
void    child_process(t_pipex pipex, char **argv, char **envp);
void    parent_process(t_pipex pipex, char **argv, char **envp);
void	leaks(void);





#endif