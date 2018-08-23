#include <stdio.h>

#define MAX 1123

char adj[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
	int i;
	adj[x][y] = 'o';
	for (i = 0; i < 4; i++)
		if (adj[x + dx[i]][y + dy[i]] == '.')
			dfs(x + dx[i], y + dy[i]);
	
}

int main(void){
	int n, m, i, j, ans = 0;

	scanf("%d %d ", &n, &m);
	for (i = 0; i < n; i++)
		fgets(adj[i], MAX, stdin);	
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (adj[i][j] == '.'){
				dfs(i, j); ans++;
			}
	printf("%d\n", ans);
	return 0;
}
