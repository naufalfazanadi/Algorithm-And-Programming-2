#include<stdio.h>

int main(){
	int n;
	int i,j;
	int yes;
	int prima[60];
	int counter=0;
	scanf("%d",&n);
	for(i=2;i<=100;i++){
		int c1=i;
		yes=0;
		for(j=1;j<=i;j++){
			if(c1%j==0){
				yes++;
			}
		}
		if(yes==2){
			prima[counter]=c1;
			counter++;
		}
	}
	// for(i=0;i<counter;i++){
		// printf("%d ",prima[i]);
	// }
	for(i=0;i<prima[n-1];i++){
		printf("Wilujeng Sumping.\n");
	}
	return 0;
}