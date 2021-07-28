#include "ft_printf.h"

int	spfr_checker(char spfr)
{
	if (spfr == 'c' || spfr == 's' || spfr == 'p'
		|| spfr == 'd' || spfr == 'i' || spfr == '%'
		|| spfr == 'u' || spfr == 'x' || spfr == 'X')
	{
		g_flags.spfr = spfr;
		return (1);
	}
	return (0);
}

void	enter_flags(va_list args, char *str)
{
	int	i;

	i = enter_pcsn(str);
	enter_width(str, i);
	enter_star(args, str);
	enter_nil(str);
}

void	process_str(va_list args)
{
	if (g_flags.pcsn && g_flags.spfr == 's')
		handle_strpcsn(args);
	else
	{
		cvsn_spfr(args);
		handle_diuxXpcsn();
		handle_width();
	}
}

void	read_str(va_list args, const char *s)
{
	int		i;
	int		a;
	char	*sub;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			a = i++;
			while (!spfr_checker(s[i]))
				i++;
			sub = ft_substr(s, a, i - a + 1);
			enter_flags(args, sub);
			process_str(args);
			free(sub);
			reset_flags();
			i++;
		}
		else
		{
			ft_putchar(s[i++]);
			g_a++;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	reset_flags();
	g_a = 0;
	va_start(args, s);
	read_str(args, s);
	va_end(args);
	return (g_a);
}
