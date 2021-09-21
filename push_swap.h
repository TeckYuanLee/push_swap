#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

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

void	threerandnum(long *A, long *B, int len);
void	fiverandnum(long *A, long *B);
int		comparealgo(long *A, long a);

int		checksorted(long *A);
long	isMedian(long *A, long a, int len);
long	iterateMedian(long *A, int len);
void	b_moving(long *A, long *B, long median, int *p_o, int *len);
void	push_threerandnum(long *A, long *B, int len);
void	printAB(long *A, long *B);

void	makesurelargesttoptwo(long last, long *A, long *B);
long	findsmallestoftwenty(long *A);
void	movesmallesttotop(long *A, long *B, long i);
void	recursivealgo(long *A, long *B);

int		quick_sort_a(long *A, long *B, int len);
int		quick_sort_b(long *A, long *B, int len);

#endif
