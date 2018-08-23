#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define GREY -1
#define BLACK 1
#define WHITE 0
#define MAX 11234
#define vi vector<int>

vector <vi> adj(3*MAX);
vi color(MAX);

bool dfs(int v){
	color[v] = GREY;
	for(int i = 0; i < (int)adj[v].size(); i++){
		int u = adj[v][i];
		if(color[u] == BLACK) continue;
		if(color[u] == GREY) { return true; }
		if(dfs(u)) return true;
	}
	color[v] = BLACK;
	return false;
}

int main(void){
	int T, N, M;
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 0; i < M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
		bool ans = false;
		for(int i = 1; !ans && i <= N; i++){
			if(color[i] == BLACK) continue;
			ans = dfs(i);
		}
		printf("%s\n", ans ? "SIM" : "NAO");
		for(int i = 1; i <= N; i++){
			adj[i].clear();
			color[i] = WHITE;
		}
	}
	return 0;
}
