#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

void	create_pipes(int *end)
{
	int i;
	int cmd_args;

	i = 0;
	while (i < (cmd_args - 1))
	{
		if (pipe(end + 2 * i) < 0)
			exit(1);
		i++;
	}
}

int main()
{
    int i = 0;
    int cmd_args = 4;
    int *end;
    printf("%d\n", create_pipes(end));
    return 0;
}