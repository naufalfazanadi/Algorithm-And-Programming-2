#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	char nim[10];
	char nama[32];
	float nilai;
} pack;

typedef struct {
	int bol;
	int index;
} statsandindex;

statsandindex search (int n, char x[], pack arr[]) {
	int i = 0;

	statsandindex stats;
	stats.bol = FALSE;

	while (i < n && stats.bol == FALSE) {
		if (strcmp(arr[i].nim, x) == 0) {
			
			stats.bol = TRUE;
			stats.index = i;
		
		} else {
			i++;
		}
	}

	return stats;
}

int main () {
	int n;

	scanf("%d", &n);

	pack arr[n];

	int i;
	for (i = 0; i < n; i++) {
		printf("Isi Array ke %d : ", i+1);
		scanf("%s %s %f", &arr[i].nim, &arr[i].nama, &arr[i].nilai);
	}

	// Cari nim
	char x[10];
	scanf("%s", &x);

	statsandindex stats = search(n, x, arr);

	if (stats.bol == TRUE) {
		printf("Nim : %s\nNama : %s\nNilai : %0.2f\n", arr[stats.index].nim, arr[stats.index].nama, arr[stats.index].nilai);
	} else {
		printf("Angka tidak dapat ditemukan\n");
	}

	return 0;
}
