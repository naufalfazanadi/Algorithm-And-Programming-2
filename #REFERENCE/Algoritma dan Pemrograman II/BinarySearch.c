#include<stdio.h>
int tabInt2[10] = {15, 18, 23, 28, 28, 34, 67, 67, 89, 98};
int tabInt[10];
int main(){
	int i; int j; int bil_cari; int k; int ketemu;
	for(i=0;i<10;i++){
		tabInt[i] = tabInt2[j];
		j--;
	}
	i = 0;
	j = 9;
	bil_cari = 20;
	ketemu = 0;
	while((ketemu == 0) && (i<=j)){
		k = (int)(i + j) / 2;
		if(tabInt[k] == bil_cari){
			ketemu = 1;
		}else{
			if(tabInt[k] < bil_cari){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
		printf("%d\n",k);
	}
	if(ketemu == 1){
		printf("ada pada tabel\n");
	}else{
		printf("tidak ditemukan\n");
	}
	return 0;
}
