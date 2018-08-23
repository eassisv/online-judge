#include<stdio.h>

int main(){
  int a, b, c, x, i, n;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    x = 10; c = 0;
    if(a < b) printf("nao encaixa\n");
    else if(a > b){
      while(c < b){
	c = a % x;
	x *= 10;
      }
      if(c == b) printf("encaixa\n");
      else printf("nao encaixa\n");
    }
    else printf("encaixa\n");
  }
  return 0;
}
