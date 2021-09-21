#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

int	quick_sort_b(t_stack stack, int len)
{
	long	median;
	int		elem_cnt;
	int		push_offset;

	if (checksorted(stack.B))
	{
		while (len--)
			process_pa(stack.A, stack.B);
	}
	if (len <= 3)
	{
		push_threerandnum(stack.A, stack.B, len);
		return (1);
	}
	elem_cnt = len;
	push_offset = 0;
	median = iterateMedian(stack.B, len);
	while (len != elem_cnt / 2)
		b_moving(stack, median, &push_offset, &len);
	while (elem_cnt / 2 != (int)ft_intlen(stack.B) && push_offset--)
		process_rrb(stack.B);
	return (quick_sort_a(stack, elem_cnt / 2 + elem_cnt % 2)
		&& quick_sort_b(stack, elem_cnt / 2));
}

int	quick_sort_a(t_stack stack, int len)
{
	long	median;
	int		elem_cnt;
	int		push_offset;

	if (checksorted(stack.A))
		return (1);
	elem_cnt = len;
	push_offset = 0;
	if (len <= 3)
		return (threerandnum(stack.A, stack.B, len));
	median = iterateMedian(stack.A, len);
	while (len != elem_cnt / 2 + elem_cnt % 2)
	{
		if (stack.A[0] < median && (len--))
			process_pb(stack.A, stack.B);
		else if (++push_offset)
			process_ra(stack.A);
	}
	while (elem_cnt / 2 + elem_cnt % 2
		!= (int)ft_intlen(stack.A) && push_offset--)
		process_rra(stack.A);
	return (quick_sort_a(stack, elem_cnt / 2 + elem_cnt % 2)
		&& quick_sort_b(stack, elem_cnt / 2));
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	long	i;

	checkargc(argc);
	i = 0;
	stack.A = ft_calloc(argc, sizeof(long));
	stack.B = ft_calloc(argc, sizeof(long));
	while (i < argc)
		stack.B[i++] = 2147483648;
	i = 0;
	while (argv[++i])
	{
		stack.A[i - 1] = ft_atol(argv[i]);
		if (stack.A[i - 1] < -2147483648 || stack.A[i - 1] > 2147483647)
			exitandfree(stack);
	}
	stack.A[argc - 1] = 2147483648;
	quick_sort_a(stack, (int)ft_intlen(stack.A));
	printAB(stack.A, stack.B);
	freestack(stack);
}
