#include<stdio.h>

typedef struct{
	int x;
	int y;
	int z;
}bungkus;
bungkus array[50];
void urut(int a,int b,int c,int i){
	int x,y,z;
	if ((c>b) && (b>a)){
		z = c;
		y = b;
		x = a;
	}else{
		if(a>b){
			if(a>c){
				z = a;
				if(b>c){
					y=b;
					x=c;
				}else{
					y=c;
					x=b;
				}
			}
		}else if(b>a){
			if(b>c){
				z = b;
				if(c>a){
					y = c;
					x = a;
				}else{
					y = a;
					x = c;
				}
			}
		}else if(c>a){
			if(c>b){
				z = c;
				if(a>b){
					y = a;
					x = b;
				}else{
					y = b;
					x = a;
				}
			}
		}
	}
	array[i].z = z;
	array[i].y = y;
	array[i].x = x;
}
int main(){
	int n;
	int i;
	int multiple;
	scanf("%d",&n);
	// 1 3 2
	// 1 2 3
	for(i=0;i<n;i++){
		scanf("%d",&array[i].x);
		scanf("%d",&array[i].y);
		scanf("%d",&array[i].z);
	}
	scanf("%d",&multiple);
	int ketemu  = 0;
	for(i=0;i<n;i++){
		urut(array[i].x,array[i].y,array[i].z,i);
		if(multiple*array[i].x == array[i].z){
			ketemu = 1;
		}
	}
	if(ketemu == 1){
		printf("valid\n");
	}else{
		printf("tidak valid\n");
	}
	return 0;
}