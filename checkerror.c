#include "push_swap.h"

void	freestack(t_stack stack)
{
	free(stack.A);
	free(stack.B);
}

void	exitandfree(t_stack stack)
{
	freestack(stack);
	ft_putstr("out of INT range.\n");
	exit(0);
}

void	checkargc(int argc)
{
	if (argc < 2)
	{
		ft_putstr("not enough arguments.\n");
		exit(0);
	}
}

void	checkstring(void)
{
	ft_putstr("string.\n");
	exit(0);
}
