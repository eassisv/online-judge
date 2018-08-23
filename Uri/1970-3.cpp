#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 112

int n, k;
int mus[MAX], memo[MAX][51][51][51];

int PD(int c1, int c2, int c3){
	int r1, r2, r3, r4;
	for(int i = 0; i < 51; i++) memo[0][i][i][i] = 0;
	for(int i = 0; i <= n; i++) memo[i][0][0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= c1; j++)
			for(int k = 0; k <= c2; k++)
				for(int l = 0; l <= c3; l++){
					r1 = mus[i] > j ? 0 : memo[i-1][j - mus[i]][k][l] + mus[i];
					r2 = mus[i] > k ? 0 : memo[i-1][j][k - mus[i]][l] + mus[i];
					r3 = mus[i] > l ? 0 : memo[i-1][j][k][l - mus[i]] + mus[i];
					r4 = memo[i-1][j][k][l];
					memo[i][j][k][l] = max(r1, max(r2, max(r3, r4)));
				}
	return memo[n][c1][c2][c3];
}

int main(void){
	int c[3] = {0, 0, 0};
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &mus[i]);
	for(int i = 0; i < k; i++)
		scanf("%d", &c[i]);
	printf("%d\n", PD(c[0], c[1], c[2]));
	return 0;
}
