#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define MAX 11234
#define INF 112345678

typedef pair < int, int > par;

int C, V;
int adj[MAX][MAX], dG[MAX], p[MAX][MAX];
int distP[MAX], distN[MAX], vis[MAX];

int dijkstra(){
	int i, j, u, v;
	for(i = 0; i <= C; i++){
		distP[i] = distN[i] = INF;
	}
	priority_queue < par, vector<par>, greater<par> > Q;
	distN[1] = distP[1] = 0;
	Q.push(par(0, 1));
	while(!Q.empty()){
		u = Q.top(). second;
		Q.pop();
		if(vis[u]) continue;
		if(u == C) return distP[C];
		vis[u] = 1;
		for(i = 0; i < dG[u]; i++){
			v = adj[u][i];
			if(v == C){
				if((distN[u] + 1) % 2 == 0){
					distN[v] = distN[u] + 1;
					if(distP[u] + p[u][v] < distP[v]){
						distP[v] = distP[u] + p[u][v];
						Q.push(par(p[u][v], v));
					}
				}else{
					vis[u] = 0;
					for(j = 0; j < dG[v]; j++)
						if(!vis[adj[v][j]])
							distP[adj[v][j]] = INF;
					break;
				}
			}else{
				if(distP[u] + p[u][v] < distP[v]){
					distP[v] = distP[u] + p[u][v];
					distN[v] = distN[u] + 1;
					Q.push(par(p[u][v], v));
				}
			}
		}
	}
	return distP[C];
}

int main(void){
	int x, y, G, i, ans;

	scanf("%d %d", &C, &V);
	for(i = 0; i < V; i++){
		scanf("%d %d %d", &x, &y, &G);
		adj[x][dG[x]++] = y;
		adj[y][dG[y]++] = x;
		p[x][y] = p[y][x] = G;
	}
	ans = dijkstra();
	printf("%d\n", (ans != INF)? ans: -1);

	return 0;
}