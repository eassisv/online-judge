#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ball;

int memo[51][112];

int pd(vector<ball> v, int n, int k){
  if(n < 0) return 0;
  if(memo[n][k] != -1) return memo[n][k];
  if(v[n].second > k)
    return memo[n][k] = pd(v, n-1, k);
  else
    return memo[n][k] = max(pd(v, n-1, k), pd(v, n-1, k-v[n].second) + v[n].first);
}

int main(void){
  int C, N, K, R;
  vector <ball> V;
  scanf("%d", &C);
  while(C--){
    int x, y;
    memset(memo, -1, sizeof(memo));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
      scanf("%d %d", &x, &y);
      V.push_back(make_pair(x, y));
    }
    int ans;
    scanf("%d", &K);
    ans = pd(V, N-1, K);
    scanf("%d", &R);
    if(ans < R) printf("Falha na missao\n");
    else printf("Missao completada com sucesso\n");
    V.clear();
  }
  return 0;
}
