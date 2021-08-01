#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*A;
	int	*B;
	int	i;
	//int	j;

	i = 0;
	A = ft_calloc(argc, sizeof(int));
	B = ft_calloc(argc, sizeof(int));
	while (argv[++i])
	{
		A[i - 1] = ft_atoi(argv[i]);
		//printf("%d\n", A[i - 1]);
	}
	//process_ss(A, NULL);
	//process_rrr(A, NULL, argc - 1);
	process_pb(A, B);
	process_pb(A, B);
	process_pb(A, B);
	i = 0;
	while (A[i])
	{
		printf("A %d\n", A[i]);
		i++;
	}
	i = 0;
	while (B[i])
	{
		printf("B %d\n", B[i]);
		i++;
	}
	free(A);
	free(B);
}
