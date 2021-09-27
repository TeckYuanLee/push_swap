#include "push_swap.h"
#include <stdio.h>

int	parse_len(char **argv, int argc)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	i = -1;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!j && argv[i][j] != ' ')
				len++;
			else if (argv[i][j] != ' ' && argv[i][j - 1] == ' ')
				len++;
			j++;
		}
	}
	return (len);
}

void	parse_argv(char **argv, t_stack stack)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (argv[1][i] && argv[1][i] != ' ' && i < ft_strlen(argv[1]))
	{
		stack.A[j] = ft_atol(&argv[1][i], stack);
		checkintrange(stack, j + 1);
		checkduplicates(stack, stack.A[j], j);
		while (argv[1][i] != ' ' && argv[1][i])
			i++;
		i++;
		j++;
	}
}

void	freestack(t_stack stack)
{
	free(stack.A);
	free(stack.B);
}
