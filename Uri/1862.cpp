#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1123

int N, cont, k;
int adj[MAX][MAX], dg[MAX], vis[MAX], conj[MAX];

void dfs(int i){
	k++; vis[i] = cont;
	for(int j = 1; j <= N; j++)
		if(adj[i][j] && !vis[j])
			dfs(j);
}

int cmp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int main(void){
	scanf("%d", &N);
	char c;
	int i, j;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			scanf(" %c", &c);
			if(c == 'S'){
				adj[i][j] = 1;
				dg[i]++;
			}}
	for(i = 1; i <= N; i++){
		if(vis[i]) continue;
		cont++; k = 0; dfs(i);
		for(j = 1; j < N; j++){
			if(vis[j] != cont) continue;
			if(dg[j] != k) {printf("-1\n"); return 0;}
		}
		conj[cont-1] = k;
	}
	qsort(conj, cont, sizeof(int), &cmp);
	printf("%d\n", cont);
	for(i = 0; i < cont-1; i++)
		printf("%d ", conj[i]);
	printf("%d\n", conj[cont-1]);
}
