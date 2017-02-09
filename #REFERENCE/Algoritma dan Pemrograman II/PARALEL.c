#include<stdio.h>

int main(){
	int n;
	int i;
	scanf("%d",&n);
	int angka[100];
	for(i=0;i<n;i++){
		scanf("%d",&angka[i]);
	}
	int hasil=0;	for(i=0;i<n;i++){
		hasil=hasil+(1/angka[i]);
	}
	// hasil=1/hasil;
	printf("%d",hasil);
	return 0;
}
