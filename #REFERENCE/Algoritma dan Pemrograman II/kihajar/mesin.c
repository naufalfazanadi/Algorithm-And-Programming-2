#include"header.h"

void mesin(int n){
	int i=2;
	int j;
	int array[100];
	int yes=1;
	while(yes!=n+1){
		int counter=0;
		for(j=1;j<=i;j++){
			if(i%j==0){
				counter++;
			}
		}
		if(counter==2){
			array[yes]=i;
			yes++;
		}
		i++;
	}
	for(i=1;i<=n;i++){
		printf("%d %d\n",i,i*array[i]);
	}
}
