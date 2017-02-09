#include "header.h"
//Main Program
int main(){
	//deklarasi variabel
	int n,i,j;
	int find; //desimal yg dicari
	char replacewith[50]; //kata yg digantikan
	scanf("%d",&n);
	// Untuk inputannya menggunakan for dan array2 dimensi, tidak menggunakan pertabel
	for(i=0;i<4;i++){
		for(j=0;j<n;j++){
			scanf("%s",&data[i][j].biner);
			//fungsi membuat desimal dari biner inputan
			data[i][j].decimal = konversi(i,j,data[i][j].biner);
		}
	}
	//input desimal yg dicari
	scanf("%d",&find); scanf(" %s",&replacewith);
	//tambahkan tabel
	//di prosedur ini tabel di kerucutkan menjadi 2 tabel 
	tambahkan(0,1,0,n);
	tambahkan(2,3,1,n);
	
	//konversi kembali decimal dari pertambahan menjadi biner
	//lalu sorting setiap tabel baru.
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			konversi2(i,j,datanew[i][j].decimal);
		}
		sort(n,datanew[i]);
	}
	//gabungkan 2 tabel berikut menjadi 1 tabel.
	mergetable(n,datanew[0],datanew[1],lasttable);
	//cari bilangan yg dicari di tabelakhir
	binarysearch(find,n*2,lasttable,replacewith);
	return 0;
}