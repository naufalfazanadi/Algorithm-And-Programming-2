#include <stdio.h>

int tabInt[10] = {15, 18, 23, 28, 28, 34, 67, 67, 89, 98};

// void binary_search(int n, int arr[], int x_search);
int main(){
	int i; int j; int bil_cari; int k; int ketemu;
	i = 0;
	j = 9; // atau n-1
	bil_cari = 89;
	ketemu = 0;
	while((ketemu == 0) && (i<=j)){
		k = (i + j) / 2;
		if(tabInt[k] == bil_cari){
			ketemu = 1;
		}else{
			if(tabInt[k] > bil_cari){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
	}
	if(ketemu == 1){
		printf("ada pada tabel\n");
	}else{
		printf("tidak ditemukan\n");
	}
	return 0;
}