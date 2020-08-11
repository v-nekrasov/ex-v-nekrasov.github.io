#include "header.h"
void merge_sort_2(int *a, int n, int *tmp)//сортировка слиянием без рекурсии
{
	int k, k2, i;
	for(k=1;k<n;k*=2)
	{
		for(i=0;i+k<n; i+=2*k)
		{
			k2=n-i-k;
			if(k2>k)
				k2=k;
			merge(a+i, k, a+i+k, k2, tmp+i);
			memcpy(a+i, tmp+i, (k+k2)*sizeof(a[0]));
		}
	}
}
