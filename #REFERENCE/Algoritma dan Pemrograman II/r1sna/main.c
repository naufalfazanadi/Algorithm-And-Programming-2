#include"header.h"

int main(){
	int n;
	int i, j;
	
	scanf("%d", &n);
	data tab1[n];
	for(i=0; i<n; i++){
		scanf("%s", &tab1[i].biner);
	}
	
	data tab2[n];
	for(i=0; i<n; i++){
		scanf("%s", &tab2[i].biner);
	}
	
	data tab3[n];
	for(i=0; i<n; i++){
		scanf("%s", &tab3[i].biner);
	}
	
	data tab4[n];
	for(i=0; i<n; i++){
		scanf("%s", &tab4[i].biner);
	}
	
	scanf("%d", &cari);
	
	for(i=0; i<n; i++){
		tab1[i].desimal=convert(tab1[i].biner);
		tab2[i].desimal=convert(tab2[i].biner);
		tab3[i].desimal=convert(tab3[i].biner);
		tab4[i].desimal=convert(tab4[i].biner);
		// printf("%d ", tab3[i].desimal);
	}
	
	data tab_tampung1[n];
	data tab_tampung2[n];

	for(i=0; i<n; i++){
		tab_tampung1[i].desimal=tambah(tab1[i].desimal, tab2[i].desimal);
		tab_tampung2[i].desimal=tambah(tab3[i].desimal, tab4[i].desimal);
	}
	
	// for(i=0; i<n; i++){
		// tab_tampung1[i].biner=biner2(tab_tampung1[i].desimal);
		// tab_tampung2[i].biner=biner2(tab_tampung2[i].desimal);
	// }
	for(i=0; i<n; i++){
		bubble(tab_tampung1, n);	
		bubble(tab_tampung2, n);	
	}
	
	data tabel3[n+n];
	merge(tab_tampung1, tab_tampung2, tabel3, n);
	for(i=0; i<n+n; i++){
		convert_lagi(i, tabel3, tabel3[i].desimal);
	}
	
	// for(i=0; i<n*2; i++){
		// printf("%s", tabel3[i].biner);
	// }
	
	for(i=0; i<n+n; i++){
		printf("%d ", tabel3[i].desimal);
		printf("%s\n",tabel3[i].biner);
		// printf("%s \n", tab_tampung1[i].biner);
		
		// printf("%d \n", tab_tampung2[i].desimal);
		// printf("%s \n", tab_tampung2[i].biner);
	}
	
	
	return 0;
}