#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long	*A;
	long	*B;
}				t_stack;

void		ft_putchar(char c);
void		ft_putstr(char *s);

long		ft_atol(const char *str, t_stack stack);
long		*ft_calloc(size_t count, size_t size);
size_t		ft_intlen(const long *arr);

#endif
