#include "pipex.h"

int ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int i = 0;
	int j = 0;

	while((s1[i] || s2[j]) && len > 0)
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
		len--;
	}
	return 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_str = (char *)malloc(len);
	if (new_str == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}	
	j = 0;
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

char *get_path(char **envp)
{
    int i;
    
    i = 0;
    while(ft_strncmp(envp[i], "PATH=", 5))
        i++;
    return (envp[i] + 5);
}

char *get_command(char **env_paths, char *cmd)
{
	char *temp;
	char *command;

	while (*env_paths)
	{
		temp = ft_strjoin(*env_paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		env_paths++;
	}
	return (NULL);
}

