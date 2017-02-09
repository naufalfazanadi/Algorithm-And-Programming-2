#include <stdio.h>
#include "mesinkarakter.h"

int main(){
  char pita[50];

  printf("masukkan pada kalimat pada pita\n");
  scanf("%49[^\n]s", &pita);

  START(pita);
  printf("%c\n", GETCC());

  while(EOP() == 0){
    INC(pita);
    printf("%c\n", GETCC());
  }

  return 0;
}