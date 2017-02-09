#include "header.h"

void read(){
	FILE *data;
	data = fopen("tpita.txt","r");
	fscanf(data,"%499[^\n]s",&pita);
	fclose(data);
}

void replace(char sentences[500]){
	FILE *data;
	data = fopen("tpita.txt","w");
	fprintf(data,"%s",sentences);
	fclose(data);
}

void write(){
	FILE *data;
	data = fopen("toutput.txt","w");
	int i;
	for(i=0;i<row;i++){
		fprintf(data,"%s\n",result[i]);
	}
	fclose(data);
}
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
