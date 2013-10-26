/*
 * for test
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  if (5 < 7)
    printf("error!\n");

  printf("more errors\n");

  char *tab = "";
  strcat(tab, "\t");
  printf("%sTab\n", tab);
}
