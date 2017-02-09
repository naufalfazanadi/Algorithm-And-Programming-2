#include "header.h"

int main(){
	char pita[300];
	scanf("%299[^\n]s",&pita);
	int spasi = 1;
	start(pita);
	printf("%c\n",getcc());
	int i,j;
	i=0;
	int status = 0;
	while(EOP() == 0){
		inc(pita);
		// if(i%2==0){
			while(status == 0){
				if(getcc()==' '){
					status = 1;
				}
				if(status == 1){
					inc(pita);
					status = 0;
				}
				for(j=0;j<spasi;j++){
					printf(" ");
				}
				printf("%c\n",getcc());
				wait(5.0);
				inc(pita);
				spasi++;
			}
		// }
		// else{
		// for(j=0;j<spasi;j++){
			// printf(" ");
		// }
		
		// while(getcc()!=' '){
			
			// printf("%c",getcc());
			// inc(pita);
			// wait(3.0);
			
		// }
		printf("\n");
		// }
		// i++;
	}
	return 0;
}