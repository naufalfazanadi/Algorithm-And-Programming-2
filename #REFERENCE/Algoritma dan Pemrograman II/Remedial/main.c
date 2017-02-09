#include "header.h"
//main program
int main(){
	int i;
	//define index as a,i,u,e,o
	record[0].letter = 'a';
	record[1].letter = 'i';
	record[2].letter = 'u';
	record[3].letter = 'e';
	record[4].letter = 'o';
	//define every array is 0
	for(i=0;i<5;i++){
		record[i].count = 0;
	}
	
	char pita[500];
	int index;
	scanf("%499[^\n]s",&pita);
	//mulai mesin kata!
	start(pita);
	while(EOP() == 0){
		//jika current character bertemu dengan kondisi letter maka counter bertambah
		if(getcc() == record[0].letter){
			record[0].count++;
		}else if(getcc() == record[1].letter){
			record[1].count++;
		}else if(getcc() == record[2].letter){
			record[2].count++;
		}else if(getcc() == record[3].letter){
			record[3].count++;
		}else if(getcc() == record[4].letter){
			record[4].count++;
		}
		inc(pita);
	}
	//insertion algorithm
	insertion(5);
	for(i=0;i<5;i++){
		printf("%c %d\n",record[i].letter,record[i].count);
	}
	return 0;
}