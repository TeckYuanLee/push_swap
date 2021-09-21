#include "push_swap.h"

int	checksorted(long *A)
{
	int	i;

	i = 0;
	while (i < (int)ft_intlen(A))
	{
		if (A[i] < A[i + 1])
			i++;
		else
			break ;
	}
	if (i == (int)ft_intlen(A) - 1)
		return (1);
	else
		return (0);
}

long	isMedian(long *A, long a, int len)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (A[i] <= a)
			j++;
		i++;
	}
	return (j);
}

long	iterateMedian(long *A, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(isMedian(A, A[i], len) == (len / 2) + 1))
			i++;
		else
			break ;
	}
	return (A[i]);
}
