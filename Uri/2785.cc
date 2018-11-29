#include<bits/stdc++.h>
using namespace std;

#define MAX 112

int cxs[MAX][MAX], mm[MAX][MAX];

int sum(int i, int j, int k) {
  int t = 0;
  for( ; j <= k; j++) t += cxs[i][j];
  return t;
}

int pd(int n){
  for(int i = n ; i--; ){
    for(int j = 0; j + i < n; j++){
      if(i == n - 1){
        mm[i][j] = sum(i, j, i + j);
        continue;
      }
      int s = sum(i, j, j + i);
      if(!j) { mm[i][j] = s + mm[i + 1][j]; continue; }
      if(j + i == n - 1) { mm[i][j] = s + mm[i + 1][j - 1]; continue; }
      mm[i][j] = min(s + mm[i + 1][j], s + mm[i + 1][j - 1]);
    }
  }
  int ans = mm[0][0];
  for(int i = 1; i < n; i++) ans = min(ans, mm[0][i]);
  return ans;
}

int main(void){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int x;
      scanf("%d", &x);
      cxs[i][j] = x;
    }
  }
  printf("%d\n", pd(n));
  return 0;
}
