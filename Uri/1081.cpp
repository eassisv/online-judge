#include <bits/stdc++.h>
using namespace std;

#define MAX 21

int adj[MAX][MAX], vis[MAX];
int n, v, e;

void dfs(int u, int id){
  vis[u] = 1;
  for(int i = 0; i < v; i++){
    if(adj[u][i]){
      int w = i;
      for(int j = 0; j < id; j++) printf(" ");
      printf("%d-%d", u, w);
      if(vis[w] == -1){
      	printf(" pathR(G,%d)\n", w);
  	    dfs(w, id+2);
      }else{
	      printf("\n");
      }
    }
  }
}

int main(void){
  scanf("%d", &n);
  for(int c = 1; c <= n; c++){
    printf("Caso %d:\n", c);
    scanf("%d %d", &v, &e);
    int a, b;
    for(int i = 0; i < e; i++){
      scanf("%d %d", &a, &b);
      adj[a][b] = 1;
      vis[a] = vis[b] = -1;
    }
    for(int i = 0; i < v; i++)
      if(vis[i] == -1){
      	dfs(i, 2);
      	printf("\n");
      }
    for(int i = 0; i < v; i++)
      memset(adj[i], 0, sizeof(adj[i]));
    memset(vis, 0, sizeof(vis));
  }
  return 0;
}
