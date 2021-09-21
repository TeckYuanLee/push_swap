#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

void	threerandnum(long *A, long *B, int len)
{
	if (len == 3 && (int)ft_intlen(A) == 3)
	{
		if ((A[0] > A[1] && A[0] < A[2]) || (A[0] > A[1] && A[1] > A[2]) || (A[0] < A[2] && A[1] > A[2]))
			process_sa(A);
		if (A[0] > A[1] && A[0] > A[2])
		{
			process_ra(A);
			//printf("here?\n");
		}
		if (A[0] < A[1] && A[0] > A[2])
			process_rra(A);
	}
	else if (len == 2)
	{
		if (A[0] > A[1])
			process_sa(A);
	}
	else if (len == 3)
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
}

int	quick_sort_b(long *A, long *B, int len)
{
	long	median;
	int	elem_cnt;
	int	push_offset;

	if (checksorted(B))
	{
		while (len--)
			process_pa(A, B);
	}
	if (len <= 3)
	{
		push_threerandnum(A, B, len);
		return (1);
	}
	elem_cnt = len;
	push_offset = 0;
	median = iterateMedian(B, len);
	//printf("%ld\n", median);
	//return (1);
	//printAB(A, B);
	while (len != elem_cnt / 2)
	{
		//printf("len %d elem_cnt/2 %d median %ld\n", len, elem_cnt / 2, median);
		b_moving(A, B, median, &push_offset, &len);
		if (median == 84)
			return (1);
	}
	//printAB(A, B);
	while (elem_cnt / 2 != (int)ft_intlen(B) && push_offset--)
		process_rrb(B);
	return (quick_sort_a(A, B, elem_cnt / 2 + elem_cnt % 2)
		&& quick_sort_b(A, B, elem_cnt / 2));
}

int	quick_sort_a(long *A, long *B, int len)
{
	long	median;
	int	elem_cnt;
	int	push_offset;

	if (checksorted(A))
		return (1);
	elem_cnt = len;
	push_offset = 0;
	if (len <= 3)
	{
		threerandnum(A, B, len);
		return (1);
	}
	median = iterateMedian(A, len);
	//printf("A median%ld\n", median);
	//return (1);
	while (len != elem_cnt / 2 + elem_cnt % 2)
	{
		if (A[0] < median && (len--))
			process_pb(A, B);
		else if (++push_offset)
		{
			process_ra(A);
			//printf("here?\n");
		}
	}
	//printAB(A, B);
	while (elem_cnt / 2 + elem_cnt % 2 != (int)ft_intlen(A) && push_offset--)
		process_rra(A);
	//printAB(A, B);
	//return (1);
	return (quick_sort_a(A, B, elem_cnt / 2 + elem_cnt % 2) 
		&& quick_sort_b(A, B, elem_cnt / 2));
}

int	main(int argc, char **argv)
{
	long	*A;
	long	*B;
	long	i;

	if (argc < 2)
		exit(0);
	i = 0;
	A = ft_calloc(argc, sizeof(long));
	B = ft_calloc(argc, sizeof(long));
	while (i < argc)
		B[i++] = 2147483648;
	i = 0;
	while (argv[++i])
		A[i - 1] = ft_atoi(argv[i]);
	A[argc - 1] = 2147483648;
	B[argc - 1] = 2147483648;
	quick_sort_a(A, B, (int)ft_intlen(A));
	//printAB(A, B);
	free(A);
	free(B);
}