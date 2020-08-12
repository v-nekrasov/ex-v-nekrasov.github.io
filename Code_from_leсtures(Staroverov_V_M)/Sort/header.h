#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
void bubble_sort(int* m, int n);
void merge(int *a, int n, int *b,int m, int *r);
void merge_sort(int *a, int n, int *tmp);
void merge_sort_OMP(int *a, int n, int *tmp);
void merge_sort_2(int *a, int n, int *tmp);
void merge_sort_2_OMP(int *a, int n, int *tmp);
void Qsort_1(int *a, int p, int q);