#include "../ps_program/push_swap.h"

void	process_ra(long *a)
{
	int	temp;
	int	i;
	int	n;

	i = 0;
	n = (int)ft_intlen(a);
	temp = a[0];
	while (i < n)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[n - 1] = temp;
}

void	process_rb(long *b)
{
	int	temp;
	int	i;
	int	n;

	i = 0;
	n = (int)ft_intlen(b);
	temp = b[0];
	while (i < n)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[n - 1] = temp;
}

void	process_rr(long *a, long *b)
{
	process_ra(a);
	process_rb(b);
	ft_putstr("rr\n");
}
