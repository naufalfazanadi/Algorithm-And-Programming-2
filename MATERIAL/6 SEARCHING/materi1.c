#include <stdio.h>

#define TRUE 1
#define FALSE 0

int search (int n, int x, int arr[]) {
	int i = 0;
	int bol = FALSE;

	while (i < n && bol == 0) {
		if (arr[i] == x) {
			bol = TRUE;
		} else {
			i++;
		}
	}

	return bol;
}

int main () {
	int n;

	scanf("%d", &n);

	int arr[n];

	int i;
	for (i = 0; i < n; i++) {
		printf("Isi Array ke %d : ", i+1);
		scanf("%d", &arr[i]);
	}

	int x;
	scanf("%d", &x);

	int stats = search(n, x, arr);

	if (stats == TRUE) {
		printf("Angka %d ada dalam array\n", x);
	} else {
		printf("Angka tidak dapat ditemukan\n");
	}

	return 0;
}