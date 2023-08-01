/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:08 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/01 18:42:23 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	f_strlen(const char *s);
char	*strjoin(char *line1, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_line(char *str);
char	*ft_after_line(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);

#endif
