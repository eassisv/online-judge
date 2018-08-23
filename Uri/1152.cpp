#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
typedef pair <int, int> ii;

vector <ii> adj[MAX];
bool v[MAX];

int prim(int m){
  for(int i = 0; i < m; i++)
    v[i] = false;
  priority_queue <ii> pq;
  pq.push(make_pair(0, 0));
  int ans = 0;
  ii  w, u;
  while(!pq.empty()){
    w = pq.top();
    pq.pop();
    if (v[w.second]) continue;
    v[w.second] = true;
    ans += (-w.first);
    for(int i = 0; i < (int)adj[w.second].size(); i++){
      pq.push(adj[w.second][i]);
    }
  }
  return ans;
}

int main(void){
  int m, n;
  while(scanf("%d %d", &m, &n), m && n){
    int ans = 0, x, y, z;
    for(int i = 0; i < n; i++){
      scanf("%d %d %d", &x, &y, &z);
      adj[x].push_back(make_pair(-z,y));
      adj[y].push_back(make_pair(-z,x));
      ans += z;
    }
    printf("%d\n", ans - prim(m));
    for(int i = 0; i < m; i++)
      adj[i].clear();
  }
  return 0;
}
