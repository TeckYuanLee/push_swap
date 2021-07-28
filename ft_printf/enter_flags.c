#include "ft_printf.h"

void	enter_width(char *str, int i)
{
	int		a;
	int		b;
	char	*s;

	a = 1;
	while (str[a] && a < i)
	{
		if (!(g_flags.width) && ft_atoi(&str[a]) && str[a - 1] != '.')
		{
			g_flags.width = ft_abs(ft_atoi(&str[a]));
			b = a + 1;
		}
		if (str[a] == '-')
			g_flags.left = 1;
		if (g_flags.width)
		{
			s = ft_substr(str, 0, b);
			if (ft_strchr(s, '0'))
				g_flags.nil = -1;
			free(s);
		}
		a++;
	}
}

void	enter_nil(char *str)
{
	int		a;
	int		b;

	a = g_flags.nil;
	if (a)
	{
		b = 0;
		while (str[b] && b < a)
		{
			if (str[b] == '0')
				g_flags.nil = -1;
			b++;
		}
	}
}

void	enter_star_utils(va_list args, int i)
{
	int		nbr;

	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		nbr = ft_abs(nbr);
		g_flags.left = 1;
	}
	g_flags.width = nbr;
	if (!(g_flags.nil))
		g_flags.nil = i;
}

void	enter_star(va_list args, char *str)
{
	int		a;
	int		nbr;

	a = 1;
	while (str[a])
	{
		if (str[a] == '*' && str[a - 1] == '.')
		{
			nbr = va_arg(args, int);
			if (nbr < 0)
				g_flags.pcsn = 0;
			else if (nbr == 0)
				g_flags.pcsn = -1;
			else
				g_flags.pcsn = nbr;
			g_flags.star = 0;
		}
		else if (str[a] == '*' && str[a - 1] != '.')
			enter_star_utils(args, a);
		a++;
	}
}

int	enter_pcsn(char *str)
{
	int		a;
	int		b;

	a = 0;
	while (str[a])
	{
		if (str[a] == '.')
		{
			b = ft_atoi(&str[a + 1]);
			if (b)
				g_flags.pcsn = b;
			else if (str[a + 1] == g_flags.spfr || b == 0)
				g_flags.pcsn = -1;
			return (a);
		}
		a++;
	}
	return (a);
}
