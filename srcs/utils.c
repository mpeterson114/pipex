#include "../pipex.h"

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

