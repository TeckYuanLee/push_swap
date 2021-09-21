#include "libft.h"

size_t	ft_intlen(const long *arr)
{
	int	i;

	i = 0;
	while (arr[i] != 2147483648)
		i++;
	return (i);
}
