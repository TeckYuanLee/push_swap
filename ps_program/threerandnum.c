#include "push_swap.h"

void	Aisthree(long *A, long *B)
{
	if ((A[0] > A[1] && A[0] < A[2]) || (A[0] > A[1]
			&& A[1] > A[2]) || (A[0] < A[2] && A[1] > A[2]))
		exe_fx("sa", A, B);
	if (A[0] > A[1] && A[0] > A[2])
		exe_fx("ra", A, B);
	if (A[0] < A[1] && A[0] > A[2])
		exe_fx("rra", A, B);
}

void	partitionisthree(long *A, long *B, int len)
{
	while (len != 3 || !(A[0] < A[1] && A[1] < A[2]))
	{
		if (len == 3 && A[0] > A[1])
			exe_fx("sa", A, B);
		else if (len == 3 && !(A[2] > A[0] && A[2] > A[1]))
		{
			exe_fx("pb", A, B);
			len--;
		}
		else if (A[0] > A[1])
			exe_fx("sa", A, B);
		else if (len++)
			exe_fx("pa", A, B);
	}
}

int	threerandnum(long *A, long *B, int len)
{
	if (len == 3 && (int)ft_intlen(A) == 3)
		Aisthree(A, B);
	else if (len == 2)
	{
		if (A[0] > A[1])
			exe_fx("sa", A, B);
	}
	else if (len == 3)
		partitionisthree(A, B, len);
	return (1);
}

void	b_partitionisthree(long *A, long *B, int len)
{
	while (len || !(A[0] < A[1] && A[1] < A[2]))
	{
		if (len == 1 && A[0] > A[1])
			exe_fx("sa", A, B);
		else if (len == 1 || (len >= 2 && B[0] > B[1])
			|| (len == 3 && B[0] > B[2]))
		{
			exe_fx("pa", A, B);
			len--;
		}
		else
			exe_fx("sb", A, B);
	}
}

int	b_threerandnum(long *A, long *B, int len)
{
	if (len == 1)
		exe_fx("pa", A, B);
	else if (len == 2)
	{
		if (B[0] < B[1])
			exe_fx("sb", A, B);
		exe_fx("pa", A, B);
		exe_fx("pa", A, B);
	}
	else if (len == 3)
		b_partitionisthree(A, B, len);
	return (1);
}
