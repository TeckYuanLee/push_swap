#include "ft_printf.h"

void	handle_strpcsn(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	g_slen = ft_strlen(str);
	if (g_flags.pcsn == -1)
		g_flags.pcsn = 0;
	if (g_flags.pcsn < g_slen)
	{
		g_s = ft_substr(str, 0, g_flags.pcsn);
		g_slen = g_flags.pcsn;
		g_flags.pcsn = -2;
	}
	else if (g_flags.pcsn >= g_slen)
		g_s = str;
	g_a += g_slen;
	handle_width();
}

char	*diuxXpcsn_utils(char *s, char c, int i)
{
	int		j;
	int		a;
	size_t	b;
	char	*str;

	a = ft_atoi(s);
	b = ft_atoi_sizet(s);
	j = 0;
	str = ft_calloc(sizeof(char), (g_flags.pcsn - i + 2));
	if ((a < 0 && c != 'u') || (b < 0 && c == 'u'))
	{
		str[j++] = '-';
		g_s = ft_substr(s, 1, i - 1);
		free(s);
		s = g_s;
		i--;
	}
	while (g_flags.pcsn > i)
	{
		str[j++] = '0';
		i++;
	}
	g_s = ft_strjoin(str, s);
	free(str);
	return (s);
}

void	diuxXzero(char c)
{
	g_a -= g_slen;
	if (c == 'd' || c == 'i' || c == 'u')
		free(g_s);
	g_s = 0;
	g_slen = 0;
}

void	handle_diuxXpcsn(void)
{
	char	c;
	char	*s;
	int		i;
	size_t	k;

	c = g_flags.spfr;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
	{
		i = (int)ft_strlen(g_s);
		if (g_flags.pcsn >= i)
		{
			s = g_s;
			k = ft_strlen(s);
			s = diuxXpcsn_utils(s, c, i);
			g_slen = ft_strlen(g_s);
			g_a = g_a - k + g_slen;
			if (c == 'x' || c == 'X')
				g_flags.spfr = 'A';
			if (c == 'd' || c == 'i' || c == 'u')
				free(s);
		}
		if (g_flags.pcsn == -2)
			diuxXzero(c);
	}
}
