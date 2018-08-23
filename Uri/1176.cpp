#include<stdio.h>

long long int fib[61];

void fibonacci(){
  int i;
  fib[0] = 0; fib[1] = 1;
  for(i = 1; i < 61; i++)
    fib[i+1] = fib[i-1] + fib[i];
}


int main(){
  int t, i, ind;

  scanf("%d", &t);
  fibonacci();
  for(i = 0; i < t; i++){
    scanf("%d", &ind);
    printf("Fib(%d) = %lld\n", ind, fib[ind]);
  }
  return 0;
}
