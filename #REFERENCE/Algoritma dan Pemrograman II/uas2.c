#include<stdio.h>
#include<string.h>
int indeks;
// int panjanghuruf;
char cc;
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
// -aku -
int main(){
	char pita[500];
	scanf("%499[^\n]s",&pita);
	// int counter = 0;
	int result = 0;
	char q,w,e,r;
	start(pita);
	q = getcc();
	inc(pita);
	w = getcc();
	inc(pita);
	e = getcc();
	inc(pita);
	r = getcc();
	// aku---adalah--anak
	while(EOP()==0){
		if(q != '-'){
			if(w == '-'){
				if(e == '-'){
					if(r != '-' || r != '.'){
						printf("!!!! %c %c %c %c\n",q,w,e,r);
						result++;
					}
				}
			}
		}
		printf("%c",q);
		q = w;
		w = e;
		e = r;
		inc(pita);
		r = getcc();
	}
	printf("%d\n",result);
	return 0;
}