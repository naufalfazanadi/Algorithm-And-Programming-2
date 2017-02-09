#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	//printf("%d",n);
	char nama[100][500];
	for(i=0;i<n;i++){
		scanf(" %[^\n]s",&nama[i]);
	}
	int minIndeks;
	char temp[100];
	for(i=0; i<(n-1); i++){
		/*inisialisasi indeks elemen minimum*/
		minIndeks = i;
		/*perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen
		array*/
		for(j=(i + 1); j<n; j++){
			if(strcmp(nama[j],nama[minIndeks])==-1){
				minIndeks = j;
			}
		}
		// menukar posisi elemen
		strcpy(temp,nama[i]);
		strcpy(nama[i],nama[minIndeks]);
		strcpy(nama[minIndeks],temp);
	}
	for(i=0;i<n;i++){
		printf("%s\n",nama[i]);
	}

	return 0;
}