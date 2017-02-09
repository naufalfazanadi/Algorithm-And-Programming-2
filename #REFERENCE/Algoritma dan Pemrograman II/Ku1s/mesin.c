#include"header.h"

int cek(bungkus* a, int n){
	int i;
	int status=0;
	int status2=0;
	/* int genap;
	genap=(%2=0); */
	
	for(i=0; i<n; i++){
		if((strcmp(a[i].kata, "Genap")==0)){
			if((a[i].angka %2 == 0)){
				status++;
			}
				// i++; 
		}else if((strcmp(a[i].kata, "Ganjil")==0)){
			if((a[i].angka %2 == 1)){
				status++;
			}
				// i++;
			
		}
	}
	return status;
}


/* void cek(bungkus* a, int n){
	int i;
	int status=0;
	int status2=0;
	// int genap;
	// genap=(%2=0);
	
	for(i=0; i<n; i++){
		if((strcmp(a[i].kata, "Genap")==0)){
			if((a[i].angka %2 == 0)){
				status=1;
			}else{
				i++;
			} 
		}else if((strcmp(a[i].kata, "Ganjil")==0)){
			if((a[i].angka %2 == 1)){
				status=1;
			}else{
				i++;
			}
		}
	}
} */

// int cek(bungkus* a, int n){//prosedur mencari data
	// int status = 0;//status sebelum data ketemu
	// int i = 0;//iterasi (counter)
	
	/* readFile();//dibaca dulu file nya, yang terbaru */
	
	// while(status == 0 && i<n){//perulangan sepanjang n, dan jika status masih belum ketemu (m)
		// if(strcmp(a[i].kata, "Genap") == 0 && a[i].angka %2 ==0){//proses pembandingan, jika nim yang dimasukkan sama dengan nim yang ada pada data maka, status akan berubah jadi 1
			// status++;//artinya ketemu
		// }else if(strcmp(a[i].kata, "Ganjil") == 0 && a[i].angka %2 ==1){
			// status++;
		// }
		
		// else{//jika tidak ketemu yaa langusng maju
			// i++;//langsung next
		// }
	// }
	
	// return status;//melempar fungsi status
// }

void mergetable(bungkus* array1,bungkus* array2,bungkus* array3,int n,int m){
	//deklarasi indeks awal setiap tabel
	int i;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	//i1 berkorelasi dengan n
	//i2 berkorelasi dengan m
	// ketika i1 belum melampaui n dan juga i2
	while((i1 < n) && (i2 < m)){
		//kondisi ketika elemen pada array 1 lebih besar dari array2
		if(strcmp(array1[i].kata,array2[i].kata)==-1){
			//memasukan elemen tsb ke array baru
			array3[i3] = array1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
		//kondisi ketika lebih kecil
		}else if(strcmp(array1[i].kata,array2[i].kata)==1){
			//memasukan elemen tsb ke array baru
			array3[i3] = array2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		//kondisi jika sama
		}else{
			//memasukan kedua elemennya ke aarray baru
			array3[i3] = array1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
			array3[i3] = array2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		}
	}
	//------------------------------------------------------------
	//sisa jika i tsb paling kecil dari i lainnya
	if(i1 < n){
		for(i=i1; i<n; i++){
			//memasukkan sisa ke array 3
			array3[i3] = array1[i];
			i3 = i3 + 1;
		}
	}
	//sisa jika i2 belum dimasuki semua
	if(i2 < m){
		for(i=i2; i<m; i++){
			//memasukan sisa ke array 3
			array3[i3] = array2[i];
			i3 = i3 + 1;
		}
	}

}