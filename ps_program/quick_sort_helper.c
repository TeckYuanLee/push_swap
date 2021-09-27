#include "push_swap.h"

int	checksorted(long *A, int len, int sort_a)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if ((sort_a && A[i] > A[i + 1]) || (!sort_a && A[i] < A[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

long	isMedian(long *A, long a, int len)
{
	int		i;
	long	j;

	i = -1;
	j = 0;
	while (++i < len)
		if (A[i] <= a)
			j++;
	return (j);
}

long	iterateMedian(long *A, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
		if (isMedian(A, A[i], len) == (len / 2) + 1)
			break ;
	return (A[i]);
}
