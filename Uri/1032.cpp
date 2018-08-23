#include <stdio.h>

#define MAX 60

int primos[MAX];

void crivo(){
  int i, j, primo, ind;
  primos[0] = 2;
  ind = 1;
  for(i = 3; ind < MAX; i++){
    primo = 1;
    for(j = 0; primo && j < ind && primos[j]*primos[j] <= i; j++)
      if(!(i % primos[j]))
        primo = 0;
    if(primo) primos[ind++] = i;
  }
}

int josephus(int n, int k){
  if(n == 1) return 1;
  return (josephus(n-1, primos[k-1]) + primos[k] - 1) % n + 1;
}

int main(void){
  int n;
  crivo();
  while(scanf("%d", &n), n){
    printf("%d\n", josephus(n, n-1));
  }
  return 0;
}
