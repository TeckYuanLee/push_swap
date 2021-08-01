#include "push_swap.h"
#include <stdio.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	main(int argc, char *argv[])
{
	char	**A;
	char	**B;
	int		i;
	int		j;

	i = 0;
	A = ft_calloc(argc, sizeof(char *));
	B = ft_calloc(argc, sizeof(char *));
	while (argv[++i])
	{
		A[i - 1] = ft_calloc(ft_strlen(argv[i]) + 1, sizeof(char));
		B[i - 1] = ft_calloc(ft_strlen(argv[i]) + 1, sizeof(char));
		j = 0;
		while (argv[i][j] != '\0')
		{
			A[i - 1][j] = argv[i][j];
			j++;
		}
		printf("%d  %s  %p\n", i - 1, A[i - 1], A[i - 1]);
	}
	//process_ss(A, NULL);
	process_rrr(A, NULL, argc - 1);
	i = 0;
	while (A[i])
	{
		printf("%d  %s  %p\n", i, A[i], A[i]);
		i++;
	}
	free_str(A);
}
