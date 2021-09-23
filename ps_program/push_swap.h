#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	process_sa(long *a);
void	process_sb(long *b);
void	process_ss(long *a, long *b);
void	process_ra(long *a);
void	process_rb(long *b);
void	process_rr(long *a, long *b);
void	process_rra(long *a);
void	process_rrb(long *b);
void	process_rrr(long *a, long *b);
void	process_pa(long *a, long *b);
void	process_pb(long *a, long *b);
void	exe_fx(char *str, long *A, long *B);
void	instr_list(char *str, long *A, long *B);

void	freestack(t_stack stack);
void	checkintrange(t_stack stack, long i);
void	checkargc(int argc);
void	checkstring(t_stack stack);
void	checkduplicates(t_stack stack, long a, long j);

void	Aisthree(long *A, long *B);
void	partitionisthree(long *A, long *B, int len);
int		threerandnum(long *A, long *B, int len);
void	b_partitionisthree(long *A, long *B, int len);
int		b_threerandnum(long *A, long *B, int len);

int		checksorted(long *A);
long	isMedian(long *A, long a, int len);
long	iterateMedian(long *A, int len);

void	printAB(long *A, long *B);

int		quick_sort_a(t_stack stack, int len);
int		quick_sort_b(t_stack stack, int len);

#endif
