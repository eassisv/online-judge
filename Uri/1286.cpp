#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 21
#define MAX_P 31

int n, qtd[MAX], t[MAX], memo[MAX][MAX_P];

int pd(int i, int p){
	if(i >= n) return 0;
	if(memo[i][p] != -1) return memo[i][p];
	if(qtd[i] > p) return pd(i + 1, p);
	return memo[i][p] = 
		max(pd(i + 1, p - qtd[i]) + t[i], pd(i + 1, p));
}

int main(void){
	int p, i; 
	while(scanf("%d", &n), n){
		memset(memo, -1, sizeof(memo));
		scanf("%d", &p);
		for(i = 0; i < n; i++)
			scanf("%d %d", &t[i], &qtd[i]);
		printf("%d min.\n", pd(0, p));
	}
	return 0;
}