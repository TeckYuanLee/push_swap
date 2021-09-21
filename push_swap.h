#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	long	*A;
	long	*B;
}				t_stack;

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

void	freestack(t_stack stack);
void	exitandfree(t_stack stack);
void	checkargc(int argc);
void	checkstring(void);

void	Aisthree(long *A);
void	partitionisthree(long *A, long *B, int len);
int		threerandnum(long *A, long *B, int len);

int		checksorted(long *A);
long	isMedian(long *A, long a, int len);
long	iterateMedian(long *A, int len);
void	b_moving(t_stack stack, long median, int *p_o, int *len);
void	push_threerandnum(long *A, long *B, int len);
void	printAB(long *A, long *B);

int		quick_sort_a(t_stack stack, int len);
int		quick_sort_b(t_stack stack, int len);

#endif
