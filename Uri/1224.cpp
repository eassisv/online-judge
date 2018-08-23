#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 11234
#define INF 1LL << 63
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef pair <int, int> ij;

ll ns[MAX];
map < ij, ll > memo;

ll pd(bool p, int i, int j){
  if(i == j) return 0;
  ij index = mp(i, j);
  if(memo.find(index) != memo.end()) { return memo[index]; }
  ll a, b;
  a = pd(!p, i + 1, j) + ns[i] * p;
  b = pd(!p, i, j - 1) + ns[j] * p;
  return memo[index] = p ? max(a, b) : min(a, b);
}

int main(void){
  int n;
  while(scanf("%d", &n) != EOF){
    memo.clear();
    for(int i = 1; i <= n; i++){
      scanf("%lld", ns + i);
    }
    printf("%lld\n", pd(true, 1, n));

  }
  return 0;
}
