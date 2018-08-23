#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112

int N, K;
int v[MAX], memo[MAX][MAX];

int PD(int w){
	for(int j = 1; j <= N; j++){
		for(int k = 1; k <= w; k++)
			if(v[j] <= k) memo[j][k] = max(memo[j-1][k], memo[j-1][k-v[j]] + v[j]);
			else memo[j][k] = memo[j-1][k];
	}
	for(int i = N, j = w; i > 0; i--)
		if(memo[i][j] > memo[i-1][j]) { j -= v[i]; v[i] = 0; }
	return memo[N][w];
}

int main(void){
	int ans = 0, w[3], aux[MAX];
	w[0] = w[1] = w[2] = 0;
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &v[i]);
	for(int i = 0; i < K; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= N; i++) aux[i] = v[i]; 
	ans = max(PD(w[0]) + PD(w[1]) + PD(w[2]), PD(w[0]) + PD(w[2]) + PD(w[1]));
	for(int i = 1; i <= N; i++) v[i] = aux[i]; 
	ans = max(ans, max(PD(w[1]) + PD(w[0]) + PD(w[2]), PD(w[1]) + PD(w[2]) + PD(w[0])));
	for(int i = 1; i <= N; i++) v[i] = aux[i];
	ans = max(ans, max(PD(w[2]) + PD(w[0]) + PD(w[1]), PD(w[2]) + PD(w[1]) + PD(w[0])));
	printf("%d\n", ans);
	return 0;
}
