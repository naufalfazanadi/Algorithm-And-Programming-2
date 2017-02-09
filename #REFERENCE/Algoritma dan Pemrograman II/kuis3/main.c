#include "faisal.h"

int main(){
	//variable
	char cek1[5];
	char cek2[5];
	int find1;
	int find2;
	int i,n,m;

	scanf(" %s",&cek1); // tanda
	scanf(" %d",&find1);
	scanf("%d",&n);
	bungkus tab1[n];
	for(i=0;i<n;i++){
		scanf("%d",&tab1[i].number);
		//kalkulasikan syarat angka dan patokan
		tab1[i].divided = calculate(tab1[i].number,find1);
	}
	//input tanda juga patokan
	scanf(" %s",&cek2);
	scanf(" %d",&find2);
	scanf("%d",&m);
	bungkus tab2[m];
	for(i=0;i<m;i++){
		scanf("%d",&tab2[i].number);
		//kalkulasikan syarat angka dan patokan
		tab2[i].divided = calculate(tab2[i].number,find2);

	}
	//----
	int cari;
	scanf("%d",&cari); //angka yg dicari
	//---
	
	//kondisi jika t maka terurut yang berarti menggunakan binary
	//kondisi jika td maka tidak terurut yang berarti menggunakan sqe
	if(strcmp(cek1,"t")==0){
		binary(n,cari,tab1);
	}else{
		seqsearch(n,cari,tab1);
	}
	if(strcmp(cek2,"t")==0){
		binary(m,cari,tab2);
	}else{
		seqsearch(m,cari,tab2);
	}
	return 0;
}