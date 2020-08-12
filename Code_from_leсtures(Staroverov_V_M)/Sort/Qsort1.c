#include "header.h"
#define SWAP(a,b){t=(a); (a)=(b); (b)=t;}
void Qsort_1(int *a, int p, int q)
{
	int i, j, t;
	if(p>=q) return;
	i=p; j=q;
	//M=a[j], [p,i-1]<=M<=[j,q]
	for(;;)
	{
		while(a[i]<a[j]) i++; //M=a[j], [p,i-1]<=M<=[j,q]
		SWAP(a[i],a[j]);  //M=a[i], [p,i]<=M<=[j,q]
		j--;//M=a[i], [p,i]<=M<=[j+1,q]
		if(i>=j)
		{
			//i==j M=a[i], [p,i-1]<=M<=[i+1,q]
			//i=j+1 M=a[i], [p,i-1]<=M<=[i+1,q]
			Qsort_1(a, p, i-1);
			Qsort_1(a, i+1, q);
			return;
		}
		while(a[i]<a[j]) j--; //M=a[i], [p,i]<=M<=[j+1,q]
		SWAP(a[i], a[j]); //M=a[j], [p,i]<=M<=[j,q]
		i++; //M=a[j], [p,i-1]<=M<=[j,q]
		if(i>=j)
		{
			//i==j M=a[j], [p,j-1]<=M<=[j+1,q]
			//i=j+1 M=a[j], [p,j-1]<=M<=[j+1,q]
			Qsort_1(a, p, j-1);
			Qsort_1(a, j+1, q);
			return;
		}
	}
}