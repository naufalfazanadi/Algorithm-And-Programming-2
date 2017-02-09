#include "faisal.h"
//prosedur sorting
void sorting(int n,bungkus* a){
	//Variabel yg dibutuhkan
	int i,j;
	bungkus tmp;
	//algoritma insertion
	for(i=1;i<n;i++){
		//data sisip
		tmp=a[i];
		//dibandingkand dengan belakangnya
		j=i-1;
		//jika sama nama nya, atau sama nama tetapi berbeeda barang maka!
		while(((strcmp(tmp.nama,a[j].nama)==1) || ((strcmp(tmp.nama,a[j].nama)==0) && (strcmp(tmp.barang,a[j].barang)==1)))&&(j>=0)){
			a[j+1]=a[j];
			j--;
		}
		//data sisip disimpan ke array
		a[j+1]=tmp; 
	}
}
//prosedur print
void print(int n,bungkus a[n+1]){
	int i;
	//print hasil
	for(i=0;i<n;i++){
		printf("%s %s %d\n",a[i].nama,a[i].barang,a[i].jumlah);
	}
}
