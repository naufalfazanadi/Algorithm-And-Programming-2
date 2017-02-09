#include "header.h"

int cek(int i, int a, int b, int c, int d){
	int temp;
	//basis
	if(i==0){
		temp=a;
	}
	else if(i==1){
		temp=b;
	}
	else if(i==2){
		temp=c;
	}
	else if(i==3){
		temp=d;
	}
	//memakai rekursif
	else{
		temp=cek(i-2,a,b,c,d)+cek(i-4,a,b,c,d);
	}
	
	return temp;
}