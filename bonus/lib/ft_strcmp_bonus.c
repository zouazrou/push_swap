#include "../includes/checker_bonus.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (404);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
	}
	return (0);
}
