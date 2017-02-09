#include "header.h"

int main(){
	int i;
	read();
	// printf("%s\n",pita);
	char process[50];
	char reWith[500];
	char delWith;
	scanf("%s",&process);
	
	if(strcmp(process,"replace") == 0){
		scanf(" %499[^\n]s",&reWith);
		replace(reWith);
	}else if(strcmp(process,"delete")==0){
		scanf(" %c",&delWith);
		//------------------------------------------------
		int counter = 0;
		row = 0;
		STARTKATA(pita);
		for(i=0;i<GETPANJANGKATA();i++){
			if(ckata[i]!=delWith){
				result[row][counter] = ckata[i];
				counter++;
			}
		}
		result[row][counter]='\0';
		row++;
		// write(temp);
		while(EOPKATA(pita) == 0){
			counter = 0;
			INCKATA(pita);
			for(i=0;i<GETPANJANGKATA();i++){
				if(ckata[i]!=delWith){
					result[row][counter] = ckata[i];
					counter++;
				}
			}
			result[row][counter]='\0';
			row++;
		}
		write();
	}else{
		printf("FAIL INPUT!!");
	}
	return 0;
}