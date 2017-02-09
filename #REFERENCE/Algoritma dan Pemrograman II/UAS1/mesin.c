#include "header.h"

void start(char pita[]){
	//awali mesin dengan prosedur ini
	indeks = 0;
	cc = pita[indeks];
}
void inc(char pita[]){
	//increment
	indeks++;
	cc = pita[indeks];
}
void adv(char pita[]){
	//skip character, blank space
	indeks++;
	cc = pita[indeks];
	while((cc==' ') && (EOP() == 0)){
		indeks++;
		cc = pita[indeks];
	}
}
char getcc(){
	return cc;
}
int EOP(){
	//end of process
	if(cc=='.'){
		return 1;
	}else{
		return 0;
	}
}