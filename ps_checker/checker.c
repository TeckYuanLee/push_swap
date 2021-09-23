#include "checker.h"

int	checker_list(char *str, long *A, long *B)
{
	if (!(ft_strcmp(str, "sa")))
		process_sa(A);
	else if (!(ft_strcmp(str, "sb")))
		process_sb(B);
	else if (!(ft_strcmp(str, "ra")))
		process_ra(A);
	else if (!(ft_strcmp(str, "rb")))
		process_rb(B);
	else if (!(ft_strcmp(str, "rra")))
		process_rra(A);
	else if (!(ft_strcmp(str, "rrb")))
		process_rrb(B);
	else if (!(ft_strcmp(str, "pa")))
		process_pa(A, B);
	else if (!(ft_strcmp(str, "pb")))
		process_pb(A, B);
	else
		return (0);
	return (1);
}

int	exe_instr(long *A, long *B, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (str[++i])
	{
		j = 2;
		while (str[i] == '\n')
			i++;
		if (str[i + 2] != '\n')
			j++;
		tmp = ft_substr(str, i, j);
		checker_list(tmp, A, B);
		free(tmp);
		i += j;
	}
	return (1);
}

void	checker(t_stack stack)
{
	int		i;

	if ((int)ft_intlen(stack.B))
	{
		ft_putstr("KO\n");
		return ;
	}
	i = -1;
	while (++i < (int)ft_intlen(stack.A) - 1)
	{
		if (!(stack.A[i] < stack.A[i + 1]))
		{
			ft_putstr("KO\n");
			return ;
		}
	}
	ft_putstr("OK\n");
}

char	*read_instr(void)
{
	char	buf[1024];
	char	*temp;
	char	*str;
	int		i;

	i = read(0, buf, 1024);
	str = malloc(sizeof(char));
	if (!str)
		str = NULL;
	while (i > 0)
	{
		buf[i] = '\0';
		temp = ft_strjoin(str, buf);
		free(str);
		str = temp;
		i = read(0, buf, 1024);
		if (i < 0)
		{
			ft_putstr("Read Error\n");
			exit(-1);
			break ;
		}
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	long	i;
	char	*instr;

	checkargc(argc);
	i = 0;
	stack.A = ft_calloc(argc, sizeof(long));
	stack.B = ft_calloc(argc, sizeof(long));
	while (argv[++i])
	{
		stack.A[i - 1] = ft_atol(argv[i], stack);
		checkintrange(stack, i);
		checkduplicates(stack, stack.A[i - 1], i - 1);
	}
	instr = read_instr();
	exe_instr(stack.A, stack.B, instr);
	checker(stack);
	freestack(stack);
	free(instr);
}
