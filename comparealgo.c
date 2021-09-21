#include "push_swap.h"

int	comparealgo(long *A, long a)
{
	int	i;

	i = 0;
	while (i < (int)ft_intlen(A))
	{
		if (a >= A[i])
			i++;
		else
			break ;
	}
	if (i == (int)ft_intlen(A))
		return (1);
	else
		return (0);
}

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

void	makesurelargesttoptwo(long last, long *A, long *B)
{
	if ((int)ft_intlen(A) == 5)
	{
		if (last == 1)
			process_sa(A);
		else if (last == 2)
		{
			process_ra(A);
			process_ra(A);
		}
		else if (last == 3)
		{
			process_rra(A);
			process_rra(A);
		}
		else if (last == 4)
			process_rra(A);
	}
	if ((int)ft_intlen(A) == 4)
	{
		if (last == 1)
			process_sa(A);
		else if (last == 2)
			{
				process_ra(A);
				process_ra(A);
			}
		else if (last == 3)
			process_rra(A);
	}
	process_pb(A, B);
}

long	findsmallestoftwenty(long *A)
{
	long	smallest;
	int	i;

	i = 1;
	smallest = A[0];
	while (A[i] != 2147483648)
	{
		if (A[i] < smallest)
			smallest = A[i];
		i++;
	}
	return (smallest);
}

void	movesmallesttotop(long *A, long *B, long i)
{
	int	j;

	j = 0;
	while (A[j] != 2147483648)
	{
		if (A[j] == i)
			break ;
		j++;
	}
	//printf("nah %d  %ld\n", j, A[j]);
	if (j <= 9 && j > -1)
	{
		while (A[0] != i)
		{
			process_ra(A);
			//printf("%ld\n", A[0]);
		}
	}
	else if (j > 9 && j <= 19)
	{
		while (A[0] != i)
			process_rra(A);
	}
	process_pb(A, B);
}

void	recursivealgo(long *A, long *B)
{
	long	smallest;

	if ((int)ft_intlen(A) == 5)
		return ;
	smallest = findsmallestoftwenty(A);
	//printf("smallest %ld\n", smallest);
	movesmallesttotop(A, B, smallest);
	recursivealgo(A, B);
}

long	isMedian(long *A, long a, int len)
{
	int	i;
	long	j;

	i = 0;
	j = 0;
	//while (A[i] != 2147483648)
	while (i < len)
	{
		if (A[i] <= a)
			j++;
		i++;
	}
	//printf("j %ld\n", j);
	return (j);
}

long	iterateMedian(long *A, int len)
{
	int	i;

	i = 0;
	//while (A[i] != 2147483648)
	while (i < len - 1)
	{
		if (!(isMedian(A, A[i], len) == (len / 2) + 1))
			i++;
		else
			break ;
	}
	//printf("i %d len %d\n", i, len);
	return (A[i]);
}

void	printAB(long *A, long *B)
{
	int	i;

	i = 0;
	while (A[i] != 2147483648)
	{
		printf("A %ld\n", A[i]);
		i++;
	}
	i = 0;
	while (B[i] != 2147483648)
	{
		printf("B %ld\n", B[i]);
		i++;
	}
}

void	push_threerandnum(long *A, long *B, int len)
{
	if (len == 1)
		process_pa(A, B);
	else if (len == 2)
	{
		if (B[0] < B[1])
			process_sb(B);
		//printf("lollll");
		//printAB(A, B);
		//exe_instr(stacks, fun_list, "pa pa", is_print);
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
				//printAB(A, B);
			}
			else
			{
				process_sb(B);
				//printf("ughhhhh\n");
				//printAB(A, B);
			}
		}
	}
}

void	b_moving(long *A, long *B, long median, int *p_o, int *len)
{
	if (B[0] >= median)
	{
		process_pa(A, B);
		(*len)--;
		//printf("loll\n");
	}
	else if (++(*p_o))
	{
		process_rb(B);
		//printf("hehehe\n");
		//printf("thisssss\n");
		//printAB(A, B);
	}
}

