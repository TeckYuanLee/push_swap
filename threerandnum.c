#include "push_swap.h"

void	Aisthree(long *A)
{
	if ((A[0] > A[1] && A[0] < A[2]) || (A[0] > A[1]
			&& A[1] > A[2]) || (A[0] < A[2] && A[1] > A[2]))
		process_sa(A);
	if (A[0] > A[1] && A[0] > A[2])
		process_ra(A);
	if (A[0] < A[1] && A[0] > A[2])
		process_rra(A);
}

void	partitionisthree(long *A, long *B, int len)
{
	while (len != 3 || !(A[0] < A[1] && A[1] < A[2]))
	{
		if (len == 3 && A[0] > A[1] && A[2])
			process_sa(A);
		else if (len == 3 && !(A[2] > A[0] && A[2] > A[1]))
		{
			process_pb(A, B);
			len--;
		}
		else if (A[0] > A[1])
			process_sa(A);
		else if (len++)
			process_pa(A, B);
	}
}

int	threerandnum(long *A, long *B, int len)
{
	if (len == 3 && (int)ft_intlen(A) == 3)
		Aisthree(A);
	else if (len == 2)
	{
		if (A[0] > A[1])
			process_sa(A);
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

int	b_threerandnum(long *A, long *B, int len)
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
		b_partitionisthree(A, B, len);
	return (1);
}
