#include <bits/stdc++.h>
using namespace std;

#define ull long long

struct pedra{
  char c; int v;
  pedra() {};
  pedra(char _c, int _v) : c(_c), v(_v) {}
};

int main(void){
  int t, n;
  ull d;
  vector <pedra> vs;
  scanf("%d", &t);
  for(int k = 1; k <= t; k++){
    scanf("%d %lld ", &n, &d);
    char c; int x;
    vs.push_back(pedra('B', 0));
    for(int i = 0; i < n; i++){
      scanf(" %c-%d", &c, &x);
      pedra p(c, x);
      vs.push_back(p);
    }
    vs.push_back(pedra('B', d));
    int ans = 0, pulei = 0, dist = 0;
    for(size_t i = 1; i < vs.size(); i++){
      if(vs[i].c == 'S'){
      	if(pulei) pulei = 0;
      	else{
      	  if((vs[i].v - dist) > ans)
      	    ans = vs[i].v - dist;
      	  dist = vs[i].v;
      	  vs[i].v = -1;
      	  pulei = 1;
      	}
      }else{
      	if((vs[i].v - dist) > ans)
      	  ans = vs[i].v - dist;
      	dist = vs[i].v;
      	pulei = 0;
      }
    }
    dist = 0;
    for(auto i : vs){
      if(i.v != -1){
      	if((i.v - dist) > ans)
      	  ans = i.v - dist;
      	dist = i.v;
      }
    }
    printf("Case %d: %d\n", k, ans);
    vs.clear();
  }
  return 0;
}
