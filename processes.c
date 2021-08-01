#include "push_swap.h"

void	process_ss(int *a, int *b)
{
	int	temp;

	if (a)
	{
		temp = a[1];
		a[1] = a[0];
		a[0] = temp;
	}
	if (b)
	{
		temp = b[1];
		b[1] = b[0];
		b[0] = temp;
	}
	if (a && b)
		ft_putstr("ss\n");
	else if (a && !b)
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

void	process_rr(int *a, int *b, int n)
{
	int	temp;
	int	i;

	if (a)
	{
		i = 0;
		temp = a[0];
		while (i < n)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[n - 1] = temp;
	}
	if (b)
	{
		i = 0;
		temp = b[0];
		while (i < n)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[n - 1] = temp;
	}	
	if (a && b)
		ft_putstr("rr\n");
	else if (a && !b)
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
}

void	process_rrr(int *a, int *b, int n)
{
	int	temp;
	int	i;

	if (a)
	{
		i = n - 2;
		temp = a[n - 1];
		while (i >= 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[0] = temp;
	}
	if (b)
	{
		i = n - 2;
		temp = b[n - 1];
		while (i >= 0)
		{
			b[i + 1] = b[i];
			i--;
		}
		b[0] = temp;
	}	
	if (a && b)
		ft_putstr("rrr\n");
	else if (a && !b)
		ft_putstr("rra\n");
	else
		ft_putstr("rrb\n");
}

void	process_pa(int *a, int *b)
{
	int	temp;
	int	i;
	int	n;

	i = 0;
	n = ft_intlen(b);
	temp = b[i];
	while (i < n - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = '\0';
	i = ft_intlen(a) - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = temp;
	ft_putstr("pa\n");
}

void	process_pb(int *a, int *b)
{
	int	temp;
	int	i;
	int	n;

	i = 0;
	n = ft_intlen(a);
	temp = a[i];
	while (i < n - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = '\0';
	i = ft_intlen(b) - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = temp;
	ft_putstr("pb\n");
}
