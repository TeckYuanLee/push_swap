#include "./ps_program/push_swap.h"
#include <stdio.h>

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
