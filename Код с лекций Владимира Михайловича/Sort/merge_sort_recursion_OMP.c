#include "header.h"
void merge_sort_OMP(int *a, int n, int *tmp)
{
	int nn1, nn2, n1, n2, n3, n4;
	nn1=n/2; nn2=n-nn1; n1=nn1/2; n2=nn1-n1; n3=nn2/2; n4=nn2-n3;
	if(n<10) bubble_sort(a,n);
	else
	{
		#pragma omp parallel sections
		{
			#pragma omp section
			{merge_sort(a+0, n1, tmp+0);}
			#pragma omp section
			{merge_sort(a+n1, n2, tmp+n1);}
			#pragma omp section
			{merge_sort(a+nn1, n3, tmp+nn1);}
			#pragma omp section
			{merge_sort(a+nn1+n3, n4, tmp+nn1+n3);}
		}
		#pragma omp parallel sections
		{
			#pragma omp section
			{merge(a+0, n1, a+n1, n2, tmp+0); memcpy(a+0, tmp+0, nn1*sizeof(a[0]));}
			#pragma omp section
			{merge(a+nn1,n3,a+nn1+n3, n4, tmp+nn1);memcpy(a+nn1, tmp+nn1, nn2*sizeof(a[0]));}
		}
		merge(a, nn1, a+nn1, nn2, tmp);
		memcpy(a, tmp, n*sizeof(a[0]));
	}//END else
}