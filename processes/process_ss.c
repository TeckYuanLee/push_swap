#include "push_swap.h"

void	process_sa(long *a)
{
	int	temp;

	temp = a[1];
	a[1] = a[0];
	a[0] = temp;
	ft_putstr("sa\n");
}

void	process_sb(long *b)
{
	int	temp;

	temp = b[1];
	b[1] = b[0];
	b[0] = temp;
	ft_putstr("sb\n");
}

void	process_ss(long *a, long *b)
{
	process_sa(a);
	process_sb(b);
	ft_putstr("ss\n");
}
