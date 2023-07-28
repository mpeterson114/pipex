/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:14 by mpeterso          #+#    #+#             */
/*   Updated: 2023/07/28 18:20:55 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*strjoin(char *line1, char *buff)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!line1)
	{
		line1 = (char *)malloc(sizeof(char) * 1);
		line1[0] = '\0';
	}
	if (!line1 || !buff)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(line1) + f_strlen(buff) + 1)
			* sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	if (line1)
		while (line1[++i] != '\0')
			new_str[i] = line1[i];
	j = 0;
	while (buff[j] != '\0')
		new_str[i++] = buff[j++];
	new_str[i++] = '\0';
	free(line1);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	if (((unsigned char)c) == '\0')
		return ((char *)s);
	return (0);
}
