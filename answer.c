#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
   	
	temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int A[], int left, int right)
{
    int x;
    int i;
	int	j;
 
    x = A[right];
	i = left - 1;
	j = left;
	while (j <= right - 1)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
		j++;
    }
    swap (&A[i + 1], &A[right]);
    return (i + 1);
}

 

void quickSort(int A[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(A, left, right);
        quickSort(A, left, pivot - 1);
        quickSort(A, pivot + 1, right);
    }
}

int main()
{
    int a[] = {27,16,53,21,31,45};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    	printf("%d\n", a[i]);
    return 0;
}
