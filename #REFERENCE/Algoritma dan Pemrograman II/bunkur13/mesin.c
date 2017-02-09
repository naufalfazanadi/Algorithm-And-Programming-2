#include "faisal.h"

void putar(int m,bungkus data[100]){
	int i;
	int j;
	int k;
	int temp[100];
	int counter;
	bungkus semen2;
	int semen;
	int tempo;
	//sort
	for(i=0;i<m;i++){
		counter=0;
		//jadikan temp
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				temp[counter]=data[i].array[j][k];
				counter++;
			}
		}
		//sorting matriks
		for(j=0;j<(4-1);j++){
			semen=j;
			for(k=(j+1);k<4;k++){
				if(temp[semen]>temp[k]){
					semen = k;
				}
			}
			tempo = temp[j];
			temp[j] = temp[semen];
			temp[semen] = tempo;
		}
		//kembalikan ke matriks
		counter=0;
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				data[i].array[j][k]=temp[counter];
				counter++;
			}
		}
		data[i].array[1][1]=data[i].array[1][1]*data[i].kali;
		
	}
	
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