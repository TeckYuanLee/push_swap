#include "libft.h"

size_t	ft_strstrlen(const char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
