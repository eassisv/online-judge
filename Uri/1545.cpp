#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 11234

typedef pair < int, int > ij;
typedef long long ll;

ll ns[MAX], table[MAX];qua
map < ij, ll > memo;

/*
ll pd(bool p, int i, int j){
  if(i == j) return 0;
  ij ind = make_pair(i, j);
  if(memo.find(ind) != memo.end()) return memo[ind];
  ll a, b;
  a = pd(!p, i + 1, j) + ns[i] * p;
  b = pd(!p, i, j - 1) + ns[j] * p;
  return memo[ind] = max(a, b);
}
*/

ll pd(int n){
  for(int i = 0; i < n; ++i){
    table[i] = 0;
  }
  for(int j = n-1, dir = 1; j >= 0; --j, ++dir){
    for(int i = 0; i < j; ++i){
      ll a, b;
      a = table[i + 1] + ns[i] * (dir & 1);
      b = table[i] + ns[i + dir] * (dir & 1);
      table[i] = max(a, b);
    }
  }
  return table[0];
}

int main(void){
  int n;
  while(scanf("%d", &n) != EOF){
    memo.clear();
    for(int i = 0; i < n; i++){
      scanf("%lld", ns + i);
    }
    printf("%lld\n", pd(n));

  }
  return 0;
}
