#include "faisal.h"
//fungsi membagi angka dengan patokan
int calculate(int number,int divided){
	if(number%divided == 0){ //kondisi dilakukan jika dan hanya jika angka tersebut kelipatan dari patokan
		return number/divided; 
	}else{	
		return 0;
	}
}
//sequntial
void seqsearch(int n,int findit,bungkus* a){
	int ketemu = 0;
	int i = 0;
	//ketika ketemu maka berhenti
	while((i<n) && (ketemu == 0)){
		if(findit==a[i].divided){
			//jika data ketemu
			ketemu = 1;
			printf("valid\n");
		}else{
			i = i + 1;
		}
	}
	if(ketemu == 0){
		//jika tidak ketemu
		printf("tidak valid\n");
	}
}
//binary
void binary(int n,int findit, bungkus* a){
	int i = 0;
	int j = n-1;
	int ketemu = 0;
	int k;
	//perulangan berhenti jika angka ke k ketemu
	while((ketemu == 0) && (i<=j)){
		k = (int)(i + j)/2;
		if(a[k].divided == findit){
			ketemu = 1;
		}else{
			//searching ini harus terurut dahulu 
			//jika lebih besar maka perulangan dibagi setengahnya
			if(a[k].divided > findit){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
		// printf("%d\n",k);
	}
	if(ketemu==1){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
}
