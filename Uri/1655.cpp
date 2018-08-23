#include <stdio.h>
#include <string.h>

#define MAX 112

int n, m;
double adj[MAX][MAX];

double floyd(int ini, int fim){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++){
			if(i == k) continue;
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				if(adj[i][j] < adj[i][k] * adj[k][j] && adj[i][k] && adj[k][j])
					adj[i][j] = adj[i][k] * adj[k][j];
			}
		}
	return adj[ini][fim];
}

int main(void){
	int a, b, p;
	while(scanf("%d %d", &n, &m), n){
		memset(adj, 0.0, sizeof(adj));
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &p);
			adj[a][b] = adj[b][a] = p * 0.01;
		}
		printf("%.6lf percent\n", floyd(1, n) * 100);
	}
	return 0;
}
