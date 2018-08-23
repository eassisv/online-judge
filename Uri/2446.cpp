#include <bits/stdc++.h>
using namespace std;
#define MAX 1123
#define MAXL 112345

int memo[MAX][MAXL];

int pd(int v, int m, int ms[]){
  int i, j;
  for(i = 0; i <= m; i++) memo[i][0] = 0;
  for(i = 0; i <= v; i++) memo[0][i] = 0;
  for(i = 1; i <= m; i++)
    for(j = 1; j <= v; j++){
      if(ms[i] <= j)
	memo[i][j] = max(memo[i-1][j], memo[i-1][j-ms[i]] + ms[i]);
      else
	memo[i][j] = memo[i-1][j];
    }
  return memo[m][v];
}

int main(void){
  int v, m, ms[MAX], ans;
  scanf("%d %d", &v, &m);
  for(int i = 1; i <= m; i++)
    scanf("%d", &ms[i]);
  ans = pd(v, m, ms);
  printf("%c\n", (ans == v)? 'S' : 'N' );
  return 0;
}
