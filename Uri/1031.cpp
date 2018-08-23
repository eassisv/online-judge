#include <stdio.h>

#define MAX 112

int n;

int josephus(int n, int k){
  if(n == 1) return 1;
  return (josephus(n-1, k) + k-1)%n +1;
}

int main(void){
  int r, i;
  while(scanf("%d", &n), n){
    for(r = 0, i = 1; r != 12; i++)
      r = josephus(n-1, i);
    printf("%d\n", i-1);
  }
	return 0;
}
