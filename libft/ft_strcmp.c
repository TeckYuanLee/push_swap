#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	a;

	a = 0;
	while (s1[a] && (s1[a] == s2[a]))
		a++;
	return ((unsigned char)(s1[a]) - (unsigned char)(s2[a]));
}
