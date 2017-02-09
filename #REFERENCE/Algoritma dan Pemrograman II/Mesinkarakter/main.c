#include "faisal.h"

int main(){
	char pita[50];
	int jumvok;
	printf("Masukkan pada kalimat pada pita\n");
	scanf("%49[^\n]s", &pita);
	
	start(pita);
	// vokal(getcc());
	printf("%c\n", getcc());
	
	while(EOP()==0){
		inc(pita);
		if( getcc()=='a' || getcc()=='i' || getcc()=='e' || getcc()=='o' || getcc()=='u' ){
		jumvok++;
	}
		printf("%c\n", getcc());
	}
	printf("%d\b",jumvok);
	return 0;
}