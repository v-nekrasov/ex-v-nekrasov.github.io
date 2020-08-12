#include "header.h"
void merge_sort(int *a, int n, int *tmp)
{
	int n1, n2;
	n1=n/2; n2=n-n1;
	if(n<2)
		return;
	merge_sort(a, n1, tmp);
	merge_sort(a+n1, n2, tmp);
	merge(a, n1, a+n1, n2, tmp);
	memcpy(a, tmp, n*sizeof(a[0]));
}
