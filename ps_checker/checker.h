#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	process_sa(long *a);
void	process_sb(long *b);
void	process_ra(long *a);
void	process_rb(long *b);
void	process_rra(long *a);
void	process_rrb(long *b);
void	process_pa(long *a, long *b);
void	process_pb(long *a, long *b);

char	*read_instr(void);
void	checker(t_stack stack);
int		exe_instr(long *A, long *B, char *str);
int		checker_list(char *str, long *A, long *B);

void	freestack(t_stack stack);
void	checkintrange(t_stack stack, long i);
void	checkargc(int argc);
void	checkstring(t_stack stack);
void	checkduplicates(t_stack stack, long a, long j);

#endif