#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 2123
#define pb push_back
#define pop pop_back

void dfs(int u, vector<int> adj[], int vis[]){
  printf("Visitando %d\n", u);
  for(size_t i = 0; i < adj[u].size(); i++){
    printf("Vertice %d\n", adj[u][i]);
    if(!vis[adj[u][i]]){
      vis[adj[u][i]] = 1;
      dfs(adj[u][i], adj, vis);
    }}}

int main(void){
  int n, m, v, w, p;
  vector<int> adj[MAX];
  int vis[MAX];
  while(scanf("%d %d", &n, &m), n && m){
    for(int i = 0; i < m; i++){
      scanf("%d %d %d", &v, &w, &p);
      adj[v].pb(w);
      if(p > 1)
	adj[w].pb(v);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, adj, vis);
    int ans = 1;
    for(int i = 1; i <= n; i++){
      adj[i].clear();
      if(!vis[i]) ans = 0;
    }
    printf("%d\n", ans);
  }
  return 0;  
}
