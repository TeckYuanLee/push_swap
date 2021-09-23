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
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
