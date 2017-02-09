#include <stdio.h>
typedef struct{
	int a;
	int b;
}bungkus;
int main(){
	 bungkus tabel1[4];
	 bungkus tabel2[4];
	 bungkus tabel3[8];
	 int i;
	for(i=0; i<4;i++){
		printf("masukkan angka:\n");
		scanf("%d",&tabel1[i].a);
		scanf("%d",&tabel1[i].b);
		printf("\n");
	}
	for(i=0; i<4;i++){
		printf("masukkan angka:\n");
		scanf("%d",&tabel2[i].a);
		scanf("%d",&tabel2[i].b);
		printf("\n");
	}
	for(i=0; i<4;i++){
		tabel3[i] = tabel1[i];
	}

	for(i=4; i<8;i++){
		tabel3[i] = tabel2[i-4];
	}
	for(i=0; i<8;i++){
		printf("%d ",tabel3[i].a);
		printf("%d\n",tabel3[i].b);
	} 
	 return 0;
}