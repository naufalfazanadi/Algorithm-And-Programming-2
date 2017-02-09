#include <stdio.h>

int search_huruf (int n, char arr[n][32]) {
	int i = 0;
	int bol = 0;

	while (i < n && bol < 2) {
		if (arr[i][0] == 'A' || arr[i][0] == 'a') {
			bol++;
		} 

		i++;		
	}

	return bol;
}

int main () {
	int n;

	scanf("%d", &n);

	char arr[n][32];

	int i;
	for (i = 0; i < n; i++) {
		printf("Isi Array ke %d : ", i+1);
		scanf("%s", &arr[i]);
	}

	int stats = search_huruf(n, arr);

	if (stats >= 2) {
		printf("Ada data mahasiswa yg dicari\n");
	} else {
		printf("Data tidak dapat ditemukan\n");
	}

	return 0;
}