#include "../ps_program/push_swap.h"

void	process_pa(long *a, long *b)
{
	long	temp;
	long	i;
	long	n;

	i = 0;
	n = ft_intlen(b);
	temp = b[i];
	while (i < n - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = 2147483648;
	i = ft_intlen(a);
	while (i >= 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
}

void	process_pb(long *a, long *b)
{
	long	temp;
	long	i;
	long	n;

	i = 0;
	n = ft_intlen(a);
	temp = a[i];
	while (i < n - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 2147483648;
	i = ft_intlen(b);
	while (i >= 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
}
