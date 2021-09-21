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

void	push_threerandnum(long *A, long *B, int len)
{
	if (len == 1)
		process_pa(A, B);
	else if (len == 2)
	{
		if (B[0] < B[1])
			process_sb(B);
		process_pa(A, B);
		process_pa(A, B);
	}
	else if (len == 3)
	{
		while (len || !(A[0] < A[1] && A[1] < A[2]))
		{
			if (len == 1 && A[0] > A[1])
				process_sa(A);
			else if (len == 1 || (len >= 2 && B[0] > B[1])
				|| (len == 3 && B[0] > B[2]))
			{
				process_pa(A, B);
				len--;
			}
			else
				process_sb(B);
		}
	}
}

void	b_moving(t_stack stack, long median, int *p_o, int *len)
{
	if (stack.B[0] >= median)
	{
		process_pa(stack.A, stack.B);
		(*len)--;
	}
	else if (++(*p_o))
		process_rb(stack.B);
}
