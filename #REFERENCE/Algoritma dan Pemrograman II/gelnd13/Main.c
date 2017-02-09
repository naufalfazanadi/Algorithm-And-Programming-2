#include "faisal.h"

int main(){
	char string[100];
	int n;
	int i,j,k;
	
	scanf("%s",&string);
	scanf("%d",&n);
	bungkus data[100];
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				// printf("+");
				scanf("%d",&data[i].array[j][k]);
			}
		}
		// printf("-");
		scanf("%d",&data[i].urut);
	}
	int batas;
	scanf("%d",&batas);
	int m;
	scanf("%d",&m);
	m=m+n;
	for(i=n;i<m;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				scanf("%d",&data[i].array[j][k]);
			}
		}
		scanf("%d",&data[i].urut);
	}
	putar(m,data);
	return 0;
}