#include "faisal.h"
//Main
int main(){
	// Deklarasi variabel yang dibutuhkan
	int n;
	int i;
	//Input n
	scanf("%d",&n);
	//Input deksripsi barang,nama,Harga sebanyak n
	for(i=0;i<n;i++){
		scanf(" %s",&sell[i].nama);
		scanf(" %s",&sell[i].barang);
		scanf("%d",&sell[i].harga);
	}
	//masuk ke fungsi/prosedur
	quickSortPivotPinggir(0,n-1);
	print(n,sell);
	
	return 0;
}
