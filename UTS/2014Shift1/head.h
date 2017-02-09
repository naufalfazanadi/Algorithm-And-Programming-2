#include <stdio.h>
#include <string.h>

typedef struct {
    char str[64];
    int konsonan;
} pack;

int cek_konso (char str[]);

void insertion_sort (int n, pack arr[]);
void selection_sort (int n, pack arr[]);
void bubble_sort (int n,  pack arr[]);
void quick_sort (int l, int r, pack arr[]);

void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]);
