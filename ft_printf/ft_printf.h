#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		star;
	int		width;
	int		nil;
	int		left;
	int		pcsn;
	char	spfr;
}				t_flags;

t_flags	g_flags;
size_t	g_a;
int		g_slen;
char	*g_s;
char	g_char;

void	reset_flags(void);
void	enter_width(char *str, int i);
void	enter_nil(char *str);
void	enter_star(va_list args, char *str);
void	print_spfr(void);
void	cvsn_spfr(va_list args);
int		enter_pcsn(char *str);
void	handle_strpcsn(va_list args);
void	handle_width(void);
void	handle_diuxXpcsn(void);
int		ft_printf(char const *s, ...);

#endif
