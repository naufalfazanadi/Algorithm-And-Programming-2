#include "faisal.h"
//mesin kata
void start(char pita[]){
	indeks = 0;
	cc = pita[indeks];
}
void inc(char pita[]){
	indeks++;
	cc = pita[indeks];
}
void adv(char pita[]){
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
	if(cc=='.'){
		return 1;
	}else{
		return 0;
	}
}
