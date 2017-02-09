#include "header.h"

int main(){
	int n;			//variabel banyak angka yang akan ditampilkan
	int i;
	int a,b,c,d;	//untuk inut basis
	
	//proses input dan pemanggil fungsi rekursif serta tampilannya
	scanf("%d %d %d %d",&a, &b, &c, &d);
	scanf("%d",&n);
	
	int m1[n+1];	//array biasa
	
	for(i=0;i<n;i++){
		m1[i]=cek(i,a,b,c,d);
		if(i==n-1){
			printf("%d",m1[i]);
		}else{
			printf("%d ",m1[i]);
		}
	}
	printf("\n");
	return 0;
}
