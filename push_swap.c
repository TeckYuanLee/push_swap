#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*A;
	long	*B;
	long	i;

	i = 0;
	A = ft_calloc(argc, sizeof(long));
	B = ft_calloc(argc, sizeof(long));
	while (argv[++i])
		A[i - 1] = ft_atoi(argv[i]);
	A[argc - 1] = 2147483648;
	B[argc - 1] = 2147483648;
	//printf("%ld\n", A[argc - 1]);
	if (argc == 4)
		threerandnum(A);
	if (argc == 6)
		fiverandnum(A, B);
	if ((int)ft_intlen(A) == 5 && checksorted(A))
		printf("ok\n");
	if (argc == 21)
	{
		recursivealgo(A, B);
		fiverandnum(A, B);
		i = 0;
		while (i < 15)
		{
			process_pa(A, B);
			i++;
		}
	}
	//i = 0;
	//while (A[i] != 2147483648)
	//{
	//	printf("A %ld\n", A[i]);
	//	i++;
	//}
	//i = 0;
	//while (B[i] != 2147483648)
	//{
	//	printf("B %ld\n", B[i]);
	//	i++;
	//}
	free(A);
	free(B);
}
