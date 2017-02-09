#include"header.h"

void hasil(char a[100]){
	int yes=0;
	int i;
	for(i=1;i<strlen(a)-1;i++){
		if(a[i]==' '){
			if(a[i-1]!=32 && a[i-1]!=46){
				if(a[i+1]!=32 && a[i+1]!=46){
						yes++;
				}
			}
		}
		
	}
	printf("%d\n",yes);
	
}