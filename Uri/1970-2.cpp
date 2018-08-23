#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112

int n, k;
int mus[MAX], memo[MAX][51][51][51];

int PD(int i, int c1, int c2, int c3){
	if(i >= n) return memo[i][c1][c2][c3] = 0;
	if(memo[i][c1][c2][c3] != -1) return memo[i][c1][c2][c3];
	int r1, r2, r3, r4;
	r1 = (mus[i] > c1) ? 0 : PD(i + 1, c1 - mus[i], c2, c3) + mus[i];
	r2 = (mus[i] > c2) ? 0 : PD(i + 1, c1, c2 - mus[i], c3) + mus[i];
	r3 = (mus[i] > c3) ? 0 : PD(i + 1, c1, c2, c3 - mus[i]) + mus[i];
	r4 = PD(i + 1, c1, c2, c3);
	return memo[i][c1][c2][c3] = max(r1, max(r2, max(r3, r4)));
}

int main(void){
	int c[3] = {0, 0, 0};
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &mus[i]);
	for(int i = 0; i < k; i++)
		scanf("%d", &c[i]);
	memset(memo, -1, sizeof(memo));
	printf("%d\n", PD(0, c[0], c[1], c[2]));
	return 0;
}
