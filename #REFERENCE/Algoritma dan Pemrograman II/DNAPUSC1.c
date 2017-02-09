#include<stdio.h>
#include<string.h>

int main(){
	int n,i,j,k,m[100],o,l[100];
	int arah[100];
	scanf("%d",&n);
	//input
	for(i=0;i<n;i++){
		scanf("%d",&m[i]); //input dna
		scanf("%d",&o);
		//input arah
		for(j=0;j<o;j++){
			scanf("%d",&l[j]);
			scanf("%s",&arah);
		}
	}
	int arr[n][100];
	int c1;
	int c2;
	int c3;
	int counter;
	int digit[100];
	for(i=0;i<n;i++){
		c2=m[i];
		digit[i]=0;
		c1=m[i];
		while(m[i]!=0){
			m[i]=m[i]/10;
			digit[i]++;
		}
		counter=digit[i]-1;
		printf("!!%d\n",counter);
		for(j=0;j<digit[i];j++){
			c1=c1/10;
			arr[i][counter]=(c2-(c1*10));
			c2=c1;
			counter--;
		}
	}
	char dna[n][100];
	int panjang;
	for(i=0;i<n;i++){
		panjang=0;
		for(j=0;j<digit[i];j++){
			if(arr[i][j]==1){
				
			}
		}
	}
	
	return 0;
}