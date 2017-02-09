#include "header.h"
//prosedur konveri biner -> decimal
int konversi(int a,int b,char biner[]){
	int i,j,k; int multiplier; int total=0;
	if(strlen(biner) == 9){
	//jika binernya sembilan digit
		multiplier = 256;
		for(i=0;i<9;i++){
			if(biner[i]=='1'){
				total+= multiplier;
			}
			multiplier/=2;
		}
	}else if(strlen(biner) == 8){
	//jika binernya delapan digit
		multiplier = 128;
		for(i=0;i<8;i++){
			if(biner[i]=='1'){
				total+= multiplier;
			}
			multiplier/=2;
		}
	}
	return total; //kembalikan total ke main
}
//prosedur pertambahan tabel
void tambahkan(int a, int b,int indeksnew,int n){	
	int i;
	for(i=0;i<n;i++){
		datanew[indeksnew][i].decimal = data[a][i].decimal + data[b][i].decimal;
	}
}
//prosedur dari desimal ke biner
void konversi2(int a,int b,int desimal){
	int i;
	int multiplier;
	if(desimal > 255 ){
		//jika desimal lebih dari max 8 bit
		strcpy(datanew[a][b].biner,"000000000");
		multiplier = 256;
		i=0;
		while(desimal!=0 && i < 9 ){
			if(desimal >= multiplier){
				desimal -= multiplier;
				datanew[a][b].biner[i] = '1';
			}
			multiplier/=2;
			i++;
		}
		int cont=0;
		char temp[10];
		strcpy(temp,datanew[a][b].biner);
		for(i=0;i<8;i++){
			datanew[a][b].biner[i] = temp[i+1];
		}
		//null kan digit ke 8
		datanew[a][b].biner[8] = '\0';
		//biner kan kembali
		datanew[a][b].decimal = konversi(a,b,datanew[a][b].biner);
	}
	else{
	//jika desimal masih dibawah nilai max 8 bit
		strcpy(datanew[a][b].biner,"00000000");
		multiplier = 128;
		i=0;
		while(desimal!=0 && i < 8 ){
			if(desimal >= multiplier){
				desimal -= multiplier;
				datanew[a][b].biner[i] = '1';
			}
			multiplier/=2;
			i++;
		}
	}
	
}
//prosedur merge tabel terurut
void mergetable(int n,bungkus tabel1[],bungkus tabel2[],bungkus *tabel3){
	int i;
	int i1;
	int i2;
	int i3;
	i1 = 0;
	i2 = 0;
	i3 = 0;
	//kondisi ketika semua counter kurang dari jumlah data
	while((i1 < n) && (i2 < n)){
		//kondisi elemen tabel1 lebih kecil
		if(tabel1[i1].decimal < tabel2[i2].decimal){
			tabel3[i3] = tabel1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
		//elemen tabel 2 lebih kecil
		}else if(tabel2[i2].decimal < tabel1[i1].decimal){
			tabel3[i3] = tabel2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		}else{
		//kondisi ketika elemen sama
			tabel3[i3] = tabel1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
			tabel3[i3] = tabel2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		}
	}
	//SISA
	if(i1 < n){
		for(i=i1; i<n; i++){
			tabel3[i3] = tabel1[i];
			i3 = i3 + 1;
		}
	}
	if(i2 < n){
		for(i=i2; i<n; i++){
			tabel3[i3] = tabel2[i];
			i3 = i3 + 1;
		}
	}
	
}
//prosedur insertion sort untuk tiap tabel
void sort(int n,bungkus* a){
	int i; bungkus data_sisip; int j; int k;
	for(k=0;k<2;k++){
		for(i=1; i<n; i++){
		data_sisip = a[i];
		j = i-1;
		while((data_sisip.decimal < a[j].decimal) && (j >= 0)){
			/*jika data array lebih kecil dari data sisip maka data array
			digeser ke belakang*/
			a[j+1] = a[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		a[j+1] = data_sisip;
		}
	}
	
}
//prosedur pencarian
void binarysearch(int bil_cari,int n,bungkus tabInt[],char replace[]){
	//variabel
	int i; int j; int k; int ketemu;
	i = 0;
	j = n-1;
	ketemu = 0;
	while((ketemu == 0) && (i<=j)){
		//pencarian dari tengah ke sisi
		k = (int)(i + j) / 2;
		if(tabInt[k].decimal == bil_cari){
			ketemu = 1;
		}else{
			if(tabInt[k].decimal < bil_cari){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
	}
	//jika ketemu maka replace biner tsb dengan kata ganti
	if (ketemu == 1){
		for(i=0;i<n;i++){
			if (i==k){
				printf("%s\n",replace);
			}else{
				printf("%s\n",tabInt[i].biner);
			}	
		}
	}else{
		for(i=0;i<n;i++){
			printf("%s\n",tabInt[i].biner);		
		}
	}
	
}