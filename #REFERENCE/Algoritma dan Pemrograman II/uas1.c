#include<stdio.h>
#include<string.h>
int indeks;
int panjangkata;
char ckata[50];
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

int main(){
	int i;
	char pita[500];
	scanf("%499[^\n]",&pita);
	int counter = 0;
	STARTKATA(pita);
	for(i=0;i<GETPANJANGKATA();i++){
		if(ckata[i]=='_'){
			if(ckata[i+1] == '_'){
				counter++;
				INCKATA(pita);
			}
		}
	}
	while(EOPKATA(pita) == 0){
		// printf("%s\n",GETCKATA());
		INCKATA(pita);
		for(i=0;i<GETPANJANGKATA();i++){
			if(ckata[i]=='_'){
				if(ckata[i+1] == '_'){
					counter++;
					INCKATA(pita);
				}
			}
		}
	}
	printf("%d",counter);
	return 0;
}