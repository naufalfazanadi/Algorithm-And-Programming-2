#include "header.h"
//mesin prograam
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

void insertion(int n){
	int i; 
	bungkus replace_record; 
	int j;
	for(i=1; i<n; i++){
		replace_record = record[i];
		j = i-1;
		while((replace_record.count < record[j].count) && (j >= 0)){
			// jika data array lebih kecil dari data sisip maka record
			// digeser ke belakang
			record[j+1] = record[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		record[j+1] = replace_record;
	}
}