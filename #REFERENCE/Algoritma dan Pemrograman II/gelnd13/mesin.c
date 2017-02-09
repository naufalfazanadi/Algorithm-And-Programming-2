#include "faisal.h"

void putar(int m,bungkus data[100]){
	int i;
	int j;
	int k;
	int putar;
	int temp[100][100];
	for(i=0;i<m;i++){
		for(putar=0;putar<data[i].urut;putar++){
			for(j=0;j<2;j++){
				for(k=0;k<2;k++){
					temp[j][k]=data[i].array[2-k-1][j];
				}
			}
			for(j=0;j<2;j++){
				for(k=0;k<2;k++){
					data[i].array[j][k]=temp[j][k];
				}
			}
		}
	}
	int semen;
	bungkus semen2;
	for(i=0;i<(m-1);i++){
		semen=i;
		for(j=(i+1);j<m;j++){
			if(data[semen].array[1][1]>data[j].array[1][1]){
				semen = j;
			}
		}
		semen2 = data[i];
		data[i] = data[semen];
		data[semen] = semen2;
	}
	for(i=0;i<m;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				printf("%d",data[i].array[j][k]);
				if((j==1) && (k==1)){
				}else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}