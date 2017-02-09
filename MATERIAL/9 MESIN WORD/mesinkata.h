#include <stdio.h>

int indeks;
int panjangkata;
char ckata[50];

void STARTKATA(char pita[]){
  indeks = 0;
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

void RESETKATA(){
  panjangkata = 0;
  ckata[panjangkata] = '\0';
}

void INCKATA(char pita[]){
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
  return ckata;
}

int GETPANJANGKATA(){
  return panjangkata;
}

int EOPKATA(char pita[]){
  if(pita[indeks] == '.'){
    return 1;
  }else{
    return 0;
  }
}