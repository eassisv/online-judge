#include <stdio.h>

#define MAX 11234
#define MAX2 1123

int memo[MAX][MAX2];

int josephus(int n, int k){
  if(n == 1) return 1;
  if(memo[n][k] != 0) return memo[n][k];
  return memo[n][k] = (josephus(n-1, k) + k -1) %n + 1;
}

int main(void){
  int nc, n, k, i;
  scanf("%d", &nc);
  for(i = 1; i <= nc; i++){
    scanf("%d %d", &n, &k);
    printf("Case %d: %d\n", i, josephus(n, k));
  }
  return 0;
}
