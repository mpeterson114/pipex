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