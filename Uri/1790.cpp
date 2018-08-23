#include <stdio.h>
#include <string.h>

#define MAX 2123
#define push push_back
#define pop pop_back

using namespace std;

bool foi[MAX];
int adj[MAX][MAX], c;

void dfs(int s){
	foi[s] = true;
	for (int i = 1; i <= c; i++){
		if (adj[s][i] && !foi[i]){
			foi[i] = true;
			dfs(i);
		}
	}
}

int main(void){
	int p, b, a, ans, ciclo;
	
	while(scanf("%d %d", &c, &p) != EOF){
		for (int i = 1; i <= c; i++)
			for (int j = 1; j <= c; j++)
				adj[i][j] = 0;
		for (int i = 0; i < p; i++){
			scanf("%d %d", &b, &a);
			adj[b][a] = 1;
			adj[a][b] = 1;
		}
		ans = 0;
		for (int i = 1; i <= c; i++){
			for (int j = 1; j <= c; j++){
				if (adj[i][j]){
					ciclo = 1;
					adj[i][j] = 0;
					adj[j][i] = 0;
					memset(foi, false, sizeof(foi));
					dfs(i);
					for (int k = 1; k <= c; k++)
						if (!foi[k]){
							ciclo = 0;
							break;
						}
				if (!ciclo) {ans++;}
				adj[i][j] = 1;
				adj[j][i] = 1;
				}
			}
		}
		printf("%d\n", ans/2); 
	}
	return 0;
}
