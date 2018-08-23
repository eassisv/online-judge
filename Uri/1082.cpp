#include <stdio.h>
#include <vector>
#include <string.h>

#define MAX 1123
#define pb push_back

using namespace std;

bool foi[MAX], componentes[MAX];

void dfs (int s, vector<int> adj[]){
	foi[s] = true;
	componentes[s] = true;
	for (size_t i = 0; i < adj[s].size(); i++){
		if(!foi[adj[s][i]])
			dfs(adj[s][i],adj);
	}
}

int main(){
	int n, v, e;
	int c, d, i, ans, caso = 1;
	char a, b;

	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &v, &e);
		getchar();
		vector<int> adj[MAX];
		for (i = 0; i < e; i++){
			scanf(" %c %c\n", &a, &b);
			c = a; d = b;
			adj[c].pb(d);
			adj[d].pb(c);
		}
		for (i = 0; i < v; i++){
			foi['a' + i] = false;
			componentes['a'+ i] = false;
		}
		printf("Case #%d:\n", caso++);
		ans = 0;
		for (i = 0; i < v; i++)
			if (!foi['a' + i]){
				dfs('a' + i, adj);
				ans++;
				for (int j = 0; j < v; j++)
					if (componentes['a' + j]){
						printf("%c,", 'a'+ j);
						componentes['a' + j] = false;
					}
				printf("\n");
			}
		printf("%d connected components\n\n", ans);
	}
	return  0;
}
