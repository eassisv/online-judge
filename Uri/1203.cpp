#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112
#define MAX_M 5123

int R, K;
int bdg[MAX], memo[MAX][MAX_M];

int knapsack(int w){
	int i, j;
	for(i = 0; i <= R; i++) memo[i][0] = 0;
	for(i = 0; i <= K; i++) memo[0][i] = 0;
	for(i = 1; i <= R; i++)
		for(j = 1; j <= K; j++){
			if(bdg[i] > j) memo[i][j] = memo[i-1][j];
			else
				memo[i][j] =
					max(memo[i-1][j], bdg[i] + memo[i-1][j-bdg[i]]);
		}
	return memo[R][K];
}

int main(void){

	while(scanf("%d %d", &R, &K) != EOF){
		int a, b;
		memset(bdg, 0, sizeof(bdg));
		for(int i = 0; i < K; i++){
			scanf("%d %d", &a, &b);
			bdg[a]++; bdg[b]++;
		}
		int ans;
		ans = knapsack(K);
		printf("%s\n", (ans == K)? "S" : "N");
	}

	return 0;
}
