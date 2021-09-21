#include "libft.h"

void	ft_bintmax(long *s, int n)
{
	int	a;

	a = 0;
	while (a < n)
	{
		s[a] = 2147483648;
		a++;
	}
}