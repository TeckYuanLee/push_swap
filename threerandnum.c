#include "push_swap.h"

//void	threerandnum(long *A, long *B, int len)
//{
//	if (len == 3 && (int)ft_intlen(A) == 3)
//	{
//		if ((A[0] > A[1] && A[0] < A[2]) || (A[0] > A[1] && A[1] > A[2]) || (A[0] < A[2] && A[1] > A[2]))
//			process_sa(A);
//		if (A[0] > A[1] && A[0] > A[2])
//		{
//			process_ra(A);
//			//printf("here?\n");
//		}
//		if (A[0] < A[1] && A[0] > A[2])
//			process_rra(A);
//	}
//	else if (len == 2)
//	{
//		if (A[0] > A[1])
//			process_sa(A);
//	}
//	else if (len == 3)
//	{
//		while (len != 3 || !(A[0] < A[1] && A[1] < A[2]))
//		{
//			if (len == 3 && A[0] > A[1] && A[2])
//				process_sa(A);
//			else if (len == 3 && !(A[2] > A[0] && A[2] > A[1]))
//			{
//				process_pb(A, B);
//				len--;
//			}
//			else if (A[0] > A[1])
//				process_sa(A);
//			else if (len++)
//				process_pa(A, B);
//		}
//	}
//}

//void	fiverandnum(long *A, long *B)
//{
//	int	i;
//	int	last;
//
//	//if (checksorted(A))
//	//	return ;
//	i = 0;
//	while (A[i])
//	{
//		if (comparealgo(A, A[i]) == 1)
//			last = i;
//		i++;
//	}
//	makesurelargesttoptwo(last, A, B);
//	i = 0;
//	while (A[i])
//	{
//		if (comparealgo(A, A[i]) == 1)
//			last = i;
//		i++;
//	}
//	makesurelargesttoptwo(last, A, B);
//	threerandnum(A);
//	process_pa(A, B);
//	process_ra(A);
//	process_pa(A, B);
//	process_ra(A);
//}
