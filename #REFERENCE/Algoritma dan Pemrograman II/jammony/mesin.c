#include "header.h"

void hasil(int n,long int a[n]){
	int i;
	int j;
	int temp;
	int status;
	int jam[n];
	int menit[n];
	int detik[n];
	for(i=i;i<n;i++){
		temp = a[i];
		j=i-1;
		while((temp<a[j]) && (j>=0)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;i++){
		jam[i]=0;
		menit[i]=0;
		detik[i]=0;
		status=0;
		j=0;
		while(status!=1){
			if(jam[i]==100){
				jam[i]=0;
				menit[i]=0;
				detik[i]=0;
			}
			if(a[i]>=3600){
				a[i]-=3600;
				jam[i]++;
			}else{
				status=1;
			}
		}
		status=0;
		while(status!=1){
			if(a[i]>=60){
				a[i]-=60;
				menit[i]++;
			}else{
				status=1;
			}
		}
		detik[i]=a[i];
		printf("%.2d:%.2d:%.2d\n",jam[i],menit[i],detik[i]);
	}
}