#include "fun.h"
int main(void)
{
	int n=100000000, *m0, *msave, *tmp, *m, i; time_t t1, t2;
	m0=(int*)malloc(sizeof(m0[0])*n);//отведение памяти
	tmp=(int*)malloc(sizeof(m0[0])*n);
	m=(int*)malloc(sizeof(m0[0])*n);
	msave=(int*)malloc(sizeof(m0[0])*n);
	//--
	for(i=0;i<n;i++)
		m0[i]=rand()%n; //инициализация массива
	//--
	if(n<=100)
	{
		memcpy(msave,m0,n*sizeof(m[0]));
		bubble_sort(msave,n);
	}
	//--
	time(&t1);
	memcpy(m,m0,n*sizeof(m[0]));
	merge_sort(m, n, tmp);
	if(n>100)
		memcpy(msave,m,n*sizeof(m[0]));
	for(i=0;i<n;i++)
		if(m[i]!=msave[i])
			printf("merge_sort: error i=%d\n",i);
	time(&t2);
	printf("merge_sort: dt=%d\n",(int)(t2-t1));
	//--
	time(&t1);
	memcpy(m,m0,n*sizeof(m[0]));
	merge_sort_OMP(m, n, tmp);
	for(i=0;i<n;i++)
		if(m[i]!=msave[i])
			printf("merge_sort_OMP: error i=%d\n",i);
	time(&t2);
	printf("merge_sort_OMP: dt=%d\n",(int)(t2-t1));
	//--
	printf("done\n");
	free(msave); msave=NULL;
	free(m); m=NULL;
	free(m0); m0=NULL;
	free(tmp); tmp=NULL;
	return 0;
}