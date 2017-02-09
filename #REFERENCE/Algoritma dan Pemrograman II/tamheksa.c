#include<stdio.h>
#include<string.h>

typedef struct{
	char angka[100][100];
}bung;
int main(){
	char data[100][100];
	int i,j,k;
	int n;
	scanf("%d",&n);
	char input[n][100];
	bung hasil[n];
	for(i=0;i<n;i++){
		scanf(" %s",&input[i]);
	}
	int counter[100];
	int c1;
	int c2;
	int c3;
	int total[n];
	for(i=0;i<n;i++){
		counter[i]=0;
		c1=0;
		for(j=0;j<strlen(input[i]);j++){
			if(input[i][j]!='+'){
				hasil[i].angka[counter[i]][c1]=input[i][j];
				c1++;
			}else{
				counter[i]++;
				c1=0;
			}
		}
		counter[i]++;
		hasil[i].angka[counter[i]][c1]=input[i][strlen(input[i])-1];
		total[i]=0;
		for(j=0;j<counter[i];j++){
			c2=65;
			c3=10;
			for(k=0;k<6;k++){
				if(hasil[i].angka[j][0]==c2){
					total[i]+=c3;
				}
				c3++;
				c2++;
			}
			c2=48;
			c3=0;
			for(k=0;k<10;k++){
				if(hasil[i].angka[j][0]==c2){
					total[i]+=c3;
				}
				c3++;
				c2++;
			}
		}
		c2=10;
		c3=65;
		if(total[i]>10 && total[i]<16){
			for(j=0;j<6;j++){
				if(total[i]==c2){
					printf("%c\n",c3);
				}
				c2++;
				c3++;
			}
		}else{
			printf("%d\n",total[i]);
		}
	}

	return 0;
}