#include "header.h"
// main program
int main(){
	//deklarasi indeks variabel
	int n;
	scanf("%d",&n); //input jumlah data 1
	int i,j;
	bungkus tab[n]; //variabel array sebanyak data 1
	for(i=0;i<n;i++){
		scanf(" %s",&tab[i].nama);
		scanf("%d",&tab[i].hari);
		scanf(" %s",&tab[i].bulan);
		scanf("%d",&tab[i].tahun);
	}
	int m;
	scanf("%d",&m); //input jmlh data 2
	bungkus tab2[m]; //variabel array sebanyak data 2
	for(i=0;i<m;i++){
		scanf(" %s",&tab2[i].nama);
		scanf("%d",&tab2[i].hari);
		scanf(" %s",&tab2[i].bulan);
		scanf("%d",&tab2[i].tahun);
	}
	//----------------------------------------------------------------------
	bungkus tab3[n+m];
	//----------------------------------------------------------------------
	// konversi bulan dalam setiap tabel ke dalam integer
	konversi(tab,n); 
	konversi(tab2,m);
	//----------------------------------------------------------------------
	// urutkan tabel sesuai dengan yang diminta
	insertion(tab,n);
	insertion(tab2,m);
	//----------------------------------------------------------------------
	//gabungkan kedua tabel tersebut menggunakan prosedur
	mergetable(tab,tab2,tab3,n,m);
	
	for(i=0;i<m+n;i++){
		printf("%s %d %s %d\n",tab3[i].nama,tab3[i].hari,tab3[i].bulan,tab3[i].tahun); //keluaran yg di minta
	}
	return 0;
}