#include "../ps_program/push_swap.h"

void	process_rra(long *a)
{
	int	temp;
	int	i;
	int	n;

	n = (int)ft_intlen(a);
	i = n - 2;
	temp = a[n - 1];
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = temp;
}

void	process_rrb(long *b)
{
	int	temp;
	int	i;
	int	n;

	n = (int)ft_intlen(b);
	i = n - 2;
	temp = b[n - 1];
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = temp;
}

void	process_rrr(long *a, long *b)
{
	process_rra(a);
	process_rrb(b);
}
