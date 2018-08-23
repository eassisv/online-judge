#include <stdio.h>
#include <vector>
#include <string.h>

#define MAX 112
#define pb push_back

using namespace std;

int cont, n;
bool foi[MAX];
vector<int> adj[MAX];

void dfs(int s){
	if (s != n)
		cont++;
	foi[s] = true;
	for (size_t i = 0; i < adj[s].size(); i++){
		if (!foi[adj[s][i]]){
			dfs(adj[s][i]);
			cont++;
		}
	}
}

int main() {
	int t, v, a, b, c;
	
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		vector<int> adj[MAX];
		scanf("%d %d", &v, &a);
		for (int i = 0; i < a; i++){
			scanf("%d %d", &b, &c);
			adj[c].pb(b);
			adj[b].pb(c);
		}
		cont = 0;
		memset(foi, false, sizeof(foi));
		dfs(n, adj);
		printf("%d\n", cont);
	}
	
	return 0;
}
