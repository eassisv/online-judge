#include <bits/stdc++.h>
using namespace std;

#define it vector<ii>::iterator 
#define MAX 41234
#define mp make_pair
typedef pair <int, int> ii;

vector <ii> adj[MAX];

int prim(int m){
	int ans = 0, cont = 0;
	int *vis = (int *) malloc(m * sizeof(int));
	for(int i = 0; i < m; i++)
		vis[i] = 0;
	priority_queue < ii, vector<ii>, greater<ii> > pq;
	pq.push(mp(0, 0));
	ii u, v;
	while(!pq.empty()){
		u = pq.top();
		pq.pop();
		if(vis[u.second]) continue;
		vis[u.second] = 1;
		ans += u.first;
		cont++;
		if(cont == m) break;
		for(it i = adj[u.second].begin(); i != adj[u.second].end(); i++){
			v = *i;
			if(!vis[v.second])
				pq.push(v);
		}
	}
	free(vis);
	return ans;
}

int main(void){
	int n, m;
	while(scanf("%d %d", &m, &n), m && n){
		int a, b, x;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &a, &b, &x);
			adj[a].push_back(mp(x, b));
			adj[b].push_back(mp(x, a));
		}
		printf("%d\n", prim(m));
		for(int i = 0; i < m; i++) adj[i].clear();
	}
	return 0;
}