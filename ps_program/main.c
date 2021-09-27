#include "push_swap.h"

void	instr_list(char *str, long *A, long *B)
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
}

void	exe_fx(char *str, long *A, long *B)
{
	ft_putstr(str);
	ft_putstr("\n");
	instr_list(str, A, B);
}

int	quick_sort_b(t_stack stack, int len)
{
	long	median;
	int		top_half_len;
	int		rotate;

	if (checksorted(stack.B, len, 0))
		while (len--)
			exe_fx("pa", stack.A, stack.B);
	if (len <= 3)
		return (b_threerandnum(stack.A, stack.B, len));
	top_half_len = len;
	rotate = 0;
	median = iterateMedian(stack.B, len);
	while (top_half_len != len / 2)
	{
		if (stack.B[0] >= median && top_half_len--)
			exe_fx("pa", stack.A, stack.B);
		else if (++rotate)
			exe_fx("rb", stack.A, stack.B);
	}
	while (rotate--)
		exe_fx("rrb", stack.A, stack.B);
	return (quick_sort_a(stack, len / 2 + len % 2)
		&& quick_sort_b(stack, top_half_len));
}

int	quick_sort_a(t_stack stack, int len)
{
	long	median;
	int		btm_half_len;
	int		rotate;

	if (checksorted(stack.A, len, 1))
		return (1);
	if (len <= 3)
		return (threerandnum(stack.A, stack.B, len));
	btm_half_len = len;
	rotate = 0;
	median = iterateMedian(stack.A, len);
	while (btm_half_len != len / 2 + len % 2)
	{
		if (stack.A[0] < median && btm_half_len--)
			exe_fx("pb", stack.A, stack.B);
		else if (++rotate)
			exe_fx("ra", stack.A, stack.B);
	}
	while (rotate--)
		exe_fx("rra", stack.A, stack.B);
	return (quick_sort_a(stack, btm_half_len)
		&& quick_sort_b(stack, len / 2));
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	long	i;
	int		len;

	checkargc(argc);
	len = parse_len(argv, argc);
	stack.A = ft_calloc(len, sizeof(long));
	stack.B = ft_calloc(len, sizeof(long));
	if (len != argc)
		parse_argv(argv, stack);
	else
	{
		i = 0;
		while (argv[++i])
		{
			stack.A[i - 1] = ft_atol(argv[i], stack);
			checkintrange(stack, i);
			checkduplicates(stack, stack.A[i - 1], i - 1);
		}
	}
	quick_sort_a(stack, (int)ft_intlen(stack.A));
	freestack(stack);
}
