#include <stdio.h>
int main(){
	 int tabel1[4];
	 int tabel2[4];
	 int tabel3[8];
	 int penghitung;
	for(penghitung=0; penghitung<4;penghitung++){
		printf("masukkan angka:\n");
		scanf("%d",&tabel1[penghitung]);
		printf("\n");
	}
	for(penghitung=0; penghitung<4;penghitung++){
		printf("masukkan angka:\n");
		scanf("%d",&tabel2[penghitung]);
		printf("\n");
	}
	for(penghitung=0; penghitung<4;penghitung++){
		tabel3[penghitung] = tabel1[penghitung];
	}

	for(penghitung=4; penghitung<8;penghitung++){
		tabel3[penghitung] = tabel2[penghitung-4];
	}
	for(penghitung=0; penghitung<8;penghitung++){
		printf("%d",tabel3[penghitung]);
	} 
	 return 0;
}