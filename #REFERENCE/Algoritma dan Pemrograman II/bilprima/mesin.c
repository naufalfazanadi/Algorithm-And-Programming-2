#include "header.h"
bungkus digat(int b,int a[b]){
	bungkus fungsi;
	int i;
	for(i=0;i<b;i++){
		int c1=a[i];
		c1++;
		fungsi.digit[i]=0;
		while(c1!=0){
			c1/=10;
			fungsi.digit[i]++;
		}
	}
	return fungsi;
}
bungkusan reverse(bungkus c,int b,int a[b]){
	bungkusan fungsi;
	int angka[b][100];
	int i,j;
	int c1;
	int c2;
	int puluhan;
	int counter[100];
	for(i=0;i<b;i++){
		counter[i]=1;
		for(j=0;j<c.digit[i]-1;j++){
			counter[i]*=10;
		}
	}
	for(i=0;i<b;i++){
		a[i]++;
		fungsi.rev[i]=0;
		for(j=0;j<c.digit[i];j++){
			c1=a[i];
			c2=a[i]/10;
			angka[i][j]=c1-(c2*10);
			a[i]=c2;
			fungsi.rev[i]=fungsi.rev[i]+(angka[i][j]*counter[i]);
			counter[i]/=10;
		}
	}
	return fungsi;
}
void hasil(int b,int a[b],bungkusan d){
	int i,j;
	int yes;
	int yes2;
	int c3;
	int c4;
	for(i=0;i<b;i++){
		int c1=a[i];
		c1++;
		int c2=c1;
		yes=0;
		yes2=0;
		c3=d.rev[i];
		c4=c3;
		for(j=1;j<=c1;j++){
			if(c2%j==0){
				yes++;
			}
		}
		for(j=1;j<=c3;j++){
			if(c4%j==0){
				yes2++;
			}
		}
		if(yes==2 && yes2==2){
			printf("%d\n",c1);
		}else{
			printf("0\n");
		}
	} 
}