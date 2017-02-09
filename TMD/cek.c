#include <stdio.h>
#include <string.h>

int main () {
  char str[32];
  strcpy(str, "##");

  printf("%d\n", str);

  return 0;
}