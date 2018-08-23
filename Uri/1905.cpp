#include <stdio.h>
#include <string.h>

#define MAX 112

int matriz[MAX][MAX];
bool foi[MAX][MAX];

void dfs(int y, int x){
	foi[y][x] = true;
	if(x+1 < 5)
		if (!foi[y][x+1] && !matriz[y][x+1])
			dfs(y, x+1);
	if(x-1 >= 0)
		if (!foi[y][x-1] && !matriz[y][x-1])
			dfs(y, x-1);
	if(y+1 < 5)
		if (!foi[y+1][x] && !matriz[y+1][x])
			dfs(y+1, x);
	if(y-1 >= 0)
		if (!foi[y-1][x] && !matriz[y-1][x])
			dfs(y-1, x);
	
}

int main(void){
	int T;
	
	scanf("%d", &T);
	while (T--){
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				scanf("%d", &matriz[i][j]);
		memset(foi, false, sizeof(foi));
		dfs (0, 0);
		(foi[4][4]) ? printf("COPS\n") : printf("ROBBERS\n");
	}	
	return 0;
}
