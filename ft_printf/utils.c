#include "ft_printf.h"

void	reset_flags(void)
{
	g_flags.star = 0;
	g_flags.width = 0;
	g_flags.nil = 0;
	g_flags.left = 0;
	g_flags.pcsn = 0;
	g_flags.spfr = 0;
	g_s = 0;
}

void	print_spfr(void)
{
	char	c;

	c = g_flags.spfr;
	if (g_s)
		ft_putstr(g_s);
	else if (c == 'c' || c == '%')
		ft_putchar(g_char);
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'A')
		free(g_s);
	if (g_flags.pcsn == -2 && c == 's')
		free(g_s);
}

void	print_space(char c)
{
	ft_putchar(c);
	(g_flags.width)--;
	g_a++;
}

void	handle_width_util(void)
{
	char	*sub;

	if ((g_flags.spfr == 'd' || g_flags.spfr == 'i')
		&& ft_atoi(g_s) < 0)
	{
		ft_putchar('-');
		sub = ft_substr(g_s, 1, ft_strlen(g_s) - 1);
		free(g_s);
		g_s = sub;
	}
	while (g_flags.width > g_slen)
		print_space('0');
	print_spfr();
}

void	handle_width(void)
{
	if (g_flags.left)
	{
		print_spfr();
		while (g_flags.width > g_slen)
			print_space(' ');
	}
	else if (g_flags.nil == -1 && g_flags.pcsn == 0)
		handle_width_util();
	else
	{
		while (g_flags.width > g_slen)
			print_space(' ');
		print_spfr();
	}
}
