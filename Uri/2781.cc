#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define MAX 1123

vector<int> vs (MAX, 0);

int main(void) {
  int m, n;
  cin >> m >> n;
  int ans = 0, tot = 0;
  for(int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    tot += y;
    vs[z - 1] += y;
    vs[x - 1] -= y;
  }
  for(int i = 0; i < n; i++) {
    ans += max(vs[i], 0);
  }
  printf("%c\n%d\n", ans == tot ? 'N' : 'S', ans);
  return 0;
}
