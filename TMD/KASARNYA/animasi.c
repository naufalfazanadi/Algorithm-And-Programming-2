#include <stdio.h>
#include <time.h>

void wait(float x) {
  time_t start;
  time_t current;
  time(&start);

  do {
    time(&current);
  } while (difftime(current,start) < x);
}

int main () {
  int i;

  printf("Sorry nothing to display...\n\n");
  printf("Back to menu, Please Wait.");
  for (i = 3; i >= 1; i--) {
    wait(0.5);
    printf(" .");
  }

  return 0;
}