#include "header.h"

int main(){
	int n;
	scanf("%d",&n);
	int i;
	long int detik[n];
	for(i=0;i<n;i++){
		scanf("%ld",&detik[i]);
	}
	hasil(n,detik);
	return 0;
}