#include <bits/stdc++.h>
using namespace std;
#define MAX 11234
#define BRANCO 0
#define CINZA -1
#define PRETO 1

int adj[MAX][MAX], dg[MAX], cor[MAX];

bool bfs(int o){
	int u, v;
	queue <int> q;
	cor[o] = CINZA;
	q.push(o);
	while(!q.empty()){
		u = q.front();
		cout << "Visitando vertice " << u << endl;
		q.pop();
		if(cor[u] == PRETO) continue;
		for(int i = 0; i < dg[u]; i++){
			v = adj[u][i];
			if(cor[v] == BRANCO){
				cout << "Colocando " << v << endl;
				cor[v] = CINZA;
				q.push(v);
			}
			else
				if(cor[v] == CINZA) return false;
		}
		cor[u] = PRETO;
	}
	return true;
}

int main(void){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		int a, b;
		for(int i = 1; i <= n; i++){
			dg[i] = 0;
			cor[i] = BRANCO;
		}
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			adj[a][dg[a]++] = b;
			adj[b][dg[b]++] = a;
		}
		bool ans = true;
		for(int i = 1; ans && i <= n; i++)
			if(cor[i] == BRANCO)
				ans = bfs(i);
		printf("%s\n", ans ? "Seguro" : "Inseguro");
	}
	return 0;
}