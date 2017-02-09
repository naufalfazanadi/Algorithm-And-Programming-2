#include "header.h"
//mesin 
bungkus fung(int k,int b,bungkus data,int n,int koor1[n],int koor2[n],char kata[100][100]){
	//deklarasi varaibel
	int i,j,l,m;
	//proses kasus
	for(i=0;i<n;i++){
		if(strcmp(kata[i],"tukar")==0){ //Kondisi dalam kasus tukar			
			//pemindahan satu satu angka, di baris yang ditentukan (x,y)
			for(j=0;j<k;j++){
				//e.g: pemindahan baris 0 ke 2, jangan lupa utk pemindahan baris 2 ke 0 juga.
				data.matriks[koor2[i]][j]=data.matriks2[koor1[i]][j];
				data.matriks[koor1[i]][j]=data.matriks2[koor2[i]][j];
			}
			//duplikat data matriks2, sesuai dengan matriks 1 hasil akhir
			for(l=0;l<b;l++){
				for(m=0;m<k;m++){
					data.matriks2[l][m]=data.matriks[l][m];
				}
			}
		}else if(strcmp(kata[i],"atas")==0){ //Kondisi dalam kasus atas
			//prosedure untuk memperkecil pergeseran (jika pergeseran lebih besar dari jumlah baris)
			resize(koor2,n,b);
			//pengulangan sebanyak pergeseran
			for(j=0;j<koor2[i];j++){
				//pergeseran matriks ke atas satu persatu sebanyak pergeseran
				for(l=0;l<b;l++){
					//kondisi else jika pergeseran dari matriks ujung bawah, adalah matriks pertama.
					if(l+1<b){
						data.matriks[l][koor1[i]]=data.matriks2[l+1][koor1[i]];
					}else{
						data.matriks[l][koor1[i]]=data.matriks2[0][koor1[i]];
					}
				}
				//duplikat data matriks2, sesuai dengan matriks 1 hasil akhir
				for(l=0;l<b;l++){
					for(m=0;m<k;m++){
						data.matriks2[l][m]=data.matriks[l][m];
					}
				}
			}
		}else if(strcmp(kata[i],"bawah")==0){//Kondisi dalam kasus bawah
			//prosedure untuk memperkecil pergeseran (jika pergeseran lebih besar dari jumlah baris)
			resize(koor2,n,b);
			//pergeseran matriks ke atas satu persatu sebanyak pergeseran
			for(j=0;j<koor2[i];j++){
				for(l=0;l<b;l++){
					if(l-1<0){
						//kondisi else jika pergeseran dari matriks ujung paling atas, adalah matriks adalah matriks terakhir.
						data.matriks[l][koor1[i]]=data.matriks2[b-1][koor1[i]];
					}else{
						data.matriks[l][koor1[i]]=data.matriks2[l-1][koor1[i]];
					}
				}
				//duplikat data matriks2, sesuai dengan matriks 1 hasil akhir
				for(l=0;l<b;l++){
					for(m=0;m<k;m++){
						data.matriks2[l][m]=data.matriks[l][m];
					}
				}
			}
		}
		
	}
	//mengembalikan bungkusan data, yang terdapat matriks1 hasil
	return data;
}
//prosedure
void resize(int a[100],int n,int b){
	int i;
	//prosedure ketika pergeseran lebih banyak dari panjang ordo matriks
	for(i=0;i<n;i++){
		while(a[i]>b){
			a[i]-=b;
		}
	}
}