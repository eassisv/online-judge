#include <stdio.h>
#include <string.h>

#define MAX 112345

int p[MAX], pt[MAX];

void Make(int n){
  int i;
  for(i = 1; i <= n; i++) p[i] = i;
}

int Find(int i){
  return (p[i] == i)? i: (p[i] = Find(p[i]));
}

void Union(int _x, int _y){
  int x = Find(_x), y = Find(_y);
  if(x != y){
    p[y] = x;
    pt[x] += pt[y];
    pt[y] += pt[x];
  }
}

int main(void){
  int n, m, q, a, b, i, ans;
  while(scanf("%d %d", &n, &m), n){
    ans = 0; Make(n);
    for(i = 1; i <= n; i++) scanf("%d", &pt[i]);
    while(m--){
      scanf("%d %d %d", &q, &a, &b);
      if(q == 1) Union(a, b);
      else{
	if(Find(a) == Find(1)) ans += (pt[Find(a)] > pt[Find(b)]);
	if(Find(b) == Find(1)) ans += (pt[Find(b)] > pt[Find(a)]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
