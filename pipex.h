/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:13:24 by mpeterso          #+#    #+#             */
/*   Updated: 2023/07/27 11:33:52 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include "./gnl/get_next_line.h"

typedef struct s_pipex
{
    pid_t pid1;
    pid_t pid2;
    int end[2];
    int infile;
    int outfile;
    char *path;
    char **cmd_paths;
    char **cmd_args;
    char *cmd;
} t_pipex;






#endif