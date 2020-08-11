#include "header.h"
void bubble_sort(int* m, int n)
{
	for(int i=n; i>0; i--)
		for(int j=1; j<i; j++)
			if(m[j-1]>m[j])
			{
				int t;
				t=m[j-1];
				m[j-1]=m[j];
				m[j]=t;
			}
}