#include <stdio.h>

int main(void){
  int h, p;

  scanf("%d %d", &h, &p);
  printf("%.2lf\n", (double)h / p);

  return 0;
} 
