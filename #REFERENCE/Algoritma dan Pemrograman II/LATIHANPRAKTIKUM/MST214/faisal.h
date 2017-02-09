#include<stdio.h>
typedef struct{
	char nama[100];
	char kartu[100];
}bungkus;
bungkus array1[50];
bungkus array2[50];
bungkus array3[100];
void quickSortPivotPinggir(int l,int r,bungkus* a);
void mergetable(int n,int m);