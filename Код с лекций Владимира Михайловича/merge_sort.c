#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void merge(int *a, int n, int *b,int m, int *r);
void merge_sort(int *a, int n, int *tmp);
void print_a(int *a, int n);
void merge(int *a, int n, int *b, int m, int *r)
{
	int i,j,k;
	for(i=0,j=0,k=0; i<n&&j<m;)
		if(a[i]<b[j])
			r[k++]=a[i++];
		else
			r[k++]=b[j++];
	while(i<n)
		r[k++]=a[i++];
	while(j<m)
		r[k++]=b[j++];
}
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
void print_a(int *a, int n)
{
	for(int i = 0; i<10; i++)
		printf("%d ", a[i]);
	puts("");
}
int main(void)
{
	int a[10], tmp[10];
	for(int i = 0; i<10; i++)
		a[i]=10-i;
	print_a(a, 10);
	merge_sort(a,10,tmp);
	print_a(a, 10);
	return 0;
}