#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void bubble_sort(int* m, int n);
void print_m(int* m, int n);
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
void print_m(int* m, int n)
{
	for(int i = 0; i<10; i++)
		printf("%d ", m[i]);
	puts("");
}
int main(void)
{
	int m[10];
	for(int i = 0; i<10; i++)
		m[i]=10-i;
	print_m(m, 10);
	bubble_sort(m,10);
	print_m(m, 10);
	return 0;
}