#include <bits/stdc++.h>
using namespace std;

#define MAX 11234
#define pb push_back

vector <int> adj[MAX];
int pai[MAX];

int dfs(int n){
	int u, w;
	stack <int> s;
	s.push(n);
	pai[n] = n;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(size_t i = 0; i < adj[u].size(); i++){
			w = adj[u][i];
			if(w == u) return 0;
			else{
				if(!pai[w]){
					pai[w] = u;
					s.push(w);
				}else{
					if(w != pai[u]) return 0;
				}
			}
		}
	}
	return 1;
}

int main(void){
	int n, m, a, b;
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int ans = 1;
		for(int i = 1; ans && i <= n; i++)
			if(pai[i]) continue;
			else{
				ans = dfs(i);
			}
		printf("%s\n", (ans)? "Seguro" : "Inseguro");
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			pai[i] = 0;
		}
	}
	return 0;
}
