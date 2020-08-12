#include "header.h"
void merge_sort_2_OMP(int *a, int n, int *tmp)//сортировка слиянием без рекурсии+OMP
{
	int k, k2, i;
	for(k=1;k<n;k*=2)
	{
		#pragma OMP parallel for private(k2)
		for(i=0;i<n-k; i+=2*k)
		{
			k2=n-i-k;
			if(k2>k)
				k2=k;
			merge(a+i, k, a+i+k, k2, tmp+i);
			memcpy(a+i, tmp+i, (k+k2)*sizeof(a[0]));
		}
	}
}
