#include "mesinkata.h"

typedef struct {
  int a, i, u, e, o;
}vokal;

vokal cekVokal(vokal forReturn) {
  int i;

  for (i = 0; i < GETPANJANGKATA(); i++) {
    if (ckata[i] == 'a') {
      forReturn.a++;
    } else if (ckata[i] == 'i') {
      forReturn.i++;
    } else if (ckata[i] == 'u') {
      forReturn.u++;
    } else if (ckata[i] == 'e') {
      forReturn.e++;
    } else if (ckata[i] == 'o') {
      forReturn.o++;
    }
  }

  return forReturn;
}

int main () {
  char pita[300];
  printf("masukkan pada kalimat pada pita\n");
  scanf("%299[^\n]s", &pita);

  int totalPanjangKata = 0;
  vokal sumVokal = {0};

  STARTKATA(pita);
  printf("%s\n", GETCKATA());

  sumVokal = cekVokal(sumVokal);
  totalPanjangKata += GETPANJANGKATA();

  while(EOPKATA(pita) == 0){
    INCKATA(pita);
    printf("%s\n", GETCKATA());

    sumVokal = cekVokal(sumVokal);

    totalPanjangKata += GETPANJANGKATA();
  }


  printf("a : %d\n", sumVokal.a);
  printf("i : %d\n", sumVokal.i);
  printf("u : %d\n", sumVokal.u);
  printf("e : %d\n", sumVokal.e);
  printf("o : %d\n", sumVokal.o);

  printf("%d\n", totalPanjangKata);

  return 0;
}

/*
int main(){
  char pita[300];
  int jkata = 0;
  printf("masukkan pada kalimat pada pita\n");
  scanf("%299[^\n]s", &pita);

  STARTKATA(pita);
  while(EOPKATA(pita) == 0){
    jkata++;
    INCKATA(pita);
  }

  if(GETPANJANGKATA() > 0){
    jkata++;
  }

  printf("%d", jkata);
  return 0;
}
 */