#include "ft_printf.h"

char	char_ampsn(va_list args, char c)
{
	char	a;

	if (c == 'c')
		a = (char)va_arg(args, int);
	else
		a = '%';
	g_a++;
	g_slen = 1;
	return (a);
}

char	*hex(va_list args, char c)
{
	long	nbr;
	char	*ascii;

	nbr = va_arg(args, int);
	if (nbr < 0)
		nbr = UINT_MAX + nbr + 1;
	if (c == 'x')
		ascii = ft_decToHexa(nbr);
	else
		ascii = ft_decToHexaBig(nbr);
	if (g_flags.pcsn == -1 && nbr == 0)
		g_flags.pcsn = -2;
	g_slen = ft_strlen(ascii);
	g_a += g_slen;
	return (ascii);
}

char	*strptr(va_list args, char c)
{
	void	*ptr;
	size_t	nb;
	char	*ascii;

	nb = 0;
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		nb = (size_t)ptr;
		ascii = ft_strjoin("0x", ft_decToHexa(nb));
	}
	else
	{
		ascii = va_arg(args, char *);
		if (!ascii)
			ascii = "(null)";
	}
	g_slen = ft_strlen(ascii);
	g_a += g_slen;
	return (ascii);
}

char	*decuint(va_list args, char c)
{
	int		nbr;
	long	nb;
	char	*ascii;

	if (c == 'd' || c == 'i')
	{
		nbr = va_arg(args, int);
		ascii = ft_itoa(nbr);
	}
	else
	{
		nb = va_arg(args, int);
		if (nb < 0)
			nb = UINT_MAX + nb + 1;
		ascii = ft_itoa_long(nb);
	}
	if (g_flags.pcsn == -1 && ft_atoi(ascii) == 0)
		g_flags.pcsn = -2;
	g_slen = ft_strlen(ascii);
	g_a += g_slen;
	return (ascii);
}

void	cvsn_spfr(va_list args)
{
	char	c;

	c = g_flags.spfr;
	if (c == 'c' || c == '%')
		g_char = char_ampsn(args, c);
	else if (c == 'd' || c == 'i' || c == 'u')
		g_s = decuint(args, c);
	else if (c == 's' || c == 'p')
		g_s = strptr(args, c);
	else
		g_s = hex(args, c);
}
