#include "libft.h"

size_t	ft_intlen(const int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
