#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>

#define MAX 512
#define INF 112345678

using namespace std;

typedef pair < int, int > par;

int N, E;
int adj[MAX][MAX], dist[MAX], vis[MAX];
int p[MAX][MAX], dG[MAX];

int dijkstra(int o, int d){
  	int i, v, u, j;
  	for (i = 0; i <= N; i++)
    	dist[i] = INF;
  	priority_queue < par, vector <par>, greater <par> > Q;
  	dist[o] = 0; Q.push(par(dist[o], o));
  	memset(vis, 0, sizeof(vis));
  	while(!Q.empty()){
    	u = Q.top().second;
    	Q.pop();
      if(u == d) break;
    	vis[u] = 1;
    	for(i = 0; i < dG[u]; i++){
      		v = adj[u][i];
      		for(j = 0; j < dG[v]; j++)
      			if(adj[v][j] == u){
      				dist[v] = dist[u];
      				Q.push(par(dist[v], v));
      				continue;
      			}
      		if(p[u][v] + dist[u] < dist[v]){
      			dist[v] = p[u][v] + dist[u];
      			Q.push(par(dist[v], v));
      		}
    	}
  	}
  	return dist[d];
}

int main(void){
  	int i, x, y, h, K, ans, o, d;

	while(scanf("%d %d", &N, &E), N){
		memset(adj, 0, sizeof(adj));
        memset(dG, 0, sizeof(dG));
		for(i = 0; i < E; i++){
			scanf("%d %d %d", &x, &y, &h);
			adj[x][dG[x]++] = y;
            p[x][y] = h;
		}
        scanf("%d", &K);
        for(i = 0; i < K; i++){
        	scanf("%d %d", &o, &d);
          	ans = dijkstra(o, d);
          	(ans == INF) ? printf("Nao e possivel entregar a carta\n"):
            printf("%d\n", ans);
        }
        printf("\n");
	}
	return 0;
}
