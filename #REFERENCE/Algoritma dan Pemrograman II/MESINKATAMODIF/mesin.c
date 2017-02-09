#include "header.h"
void STARTKATA(char pita[]){
	//STARTKATA
	indeks = 0;
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		//ckata terus maju hingga spasi atau titik
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}
void RESETKATA(){
	//reset all
	panjangkata = 0;
	ckata[panjangkata] = '\0';
}
void INCKATA(char pita[]){
	//increment kata
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}
char* GETCKATA(){
	//getckata disini bisa dibilang sebagai variabel yg dapat digunakan
	return ckata;
}
int GETPANJANGKATA(){
	//dapatkan kata terpanjang
	return panjangkata;
}
int EOPKATA(char pita[]){
	//end of kalimat
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}

int find(){
	// int counter = 0;
	// char kata[50] = GETCKATA();
	int i;
	for(i=0;i<GETPANJANGKATA();i++){
		if(ckata[i] == 'a'){
			return 1;
		}
	}
	return 0;
}
void makespace(int lebar,char* temp){
	int i;
	for(i=0;i<lebar;i++){
		temp[i] = '-';
	}
}