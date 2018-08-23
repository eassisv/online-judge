#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int p[MAX], v[MAX], memo[MAX][6*MAX];

int pd(int n, int k){
  int i, j;
  for(i = 0; i <= n; i++) memo[i][0] = 0;
  for(i = 0; i <= k; i++) memo[0][i] = 0;
  for(i = 1; i <= n; i++)
    for(j = 1; j <= k; j++)
      if(p[i] > j)
	memo[i][j] = memo[i-1][j];
      else
	memo[i][j] = max(memo[i-1][j], v[i] + memo[i][j-p[i]]);
  return memo[n][k];  
}

int main(void){
  int n, t, i = 1;
  while(scanf("%d %d", &n, &t), n){
    for(int j = 1; j <= n; j++)
      scanf("%d %d", &p[j], &v[j]);
    printf("Instancia %d\n%d\n\n", i++, pd(n, t));
  }
  return 0;
}
