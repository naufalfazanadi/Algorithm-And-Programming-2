#include <stdio.h>
#include <string.h>
typedef struct{
	int stok;
	char barang[100];
	char nama[100];
}bungkus;
void sort(bungkus* a,int n){
	int i; bungkus temp; int tukar;
	do{
	/*inisialisasi nilai tukar sebelum ada pertukaran diset false */
		tukar = 0;
		/*pengulangan dan memeriksa apakah ada pertukaran */
		for(i=0; i<(n-1); i++){
		/*jika ada nilai yang dipertukarkan */
			if(a[i].stok < a[i+1].stok){
				/* menukar posisi elemen */
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				tukar = 1;
			}
		}
	}while(tukar == 1);
}
int main(){
	int n;
	int i;
	int temp;

	scanf("%d",&n);
	bungkus data[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&data[i].stok);
		scanf(" %s",&data[i].barang);
		scanf(" %s",&data[i].nama);
	}
	sort(data,n);
	for(i=0;i<n;i++){
		printf("%d",data[i].stok);
		printf(" %s",data[i].barang);
		printf(" %s",data[i].nama);
	}
	
	return 0;
}