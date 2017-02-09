#include "faisal.h"

int main(){
	// Deklarasi variabel yang dibutuhkan
	int n;
	int i,j;
	//Input n
	scanf("%d",&n);
	bungkus sell[100];
	//Input deksripsi barang,nama,jumlah sebanyak n
	for(i=0;i<n;i++){
		scanf(" %s",&sell[i].nama);
		scanf(" %s",&sell[i].barang);
		scanf("%d",&sell[i].jumlah);
	}
	//masuk ke fungsi/prosedur
	sorting(n,sell);
	print(n,sell);
	
	return 0;
}
