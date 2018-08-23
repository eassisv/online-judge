#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1123456

int T, N, M;
int m[31], memo[31][MAX];

int DP(){
	for(int i = 0; i <= M; i++)
    memo[0][i] = i;
  for(int i = 0; i <= N; i++)
    memo[i][0] = 0;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++)
      if(j < m[i])
        memo[i][j] = memo[i-1][j];
      else
        memo[i][j] = min(memo[i-1][j], 1 + memo[i][j - m[i]]);
  return memo[N][M];
}

int main(void){
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d %d", &N, &M);
		for(int j = 1; j <= N; j++)
			scanf("%d", &m[j]);
		printf("%d\n", DP());
	}
	return 0;
}
