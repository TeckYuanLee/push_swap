#include "push_swap.h"

void	checkinstr(t_stack stack)
{
	ft_putstr("Error : invalid instruction.\n");
	freestack(stack);
	exit(0);
}

void	checkintrange(t_stack stack, long i)
{
	if (stack.A[i - 1] < -2147483648 || stack.A[i - 1] > 2147483647)
	{
		ft_putstr("Error : out of INT range.\n");
		freestack(stack);
		exit(0);
	}
}

void	checkargc(int argc)
{
	if (argc < 2)
		exit(0);
}

void	checkstring(t_stack stack)
{
	ft_putstr("Error : non-integer detected.\n");
	freestack(stack);
	exit(0);
}

void	checkduplicates(t_stack stack, long a, long j)
{
	long	i;

	i = -1;
	while (++i < j)
	{
		if (stack.A[i] == a)
		{
			ft_putstr("Error : duplicate!\n");
			freestack(stack);
			exit(0);
		}
	}
}
