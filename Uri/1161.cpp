#include <stdio.h>

#define MAX 21

long long unsigned memo[MAX];

long long unsigned fat(int n){
	if(n == 1 || n == 0) return 1;
	if(memo[n] != 0) return memo[n];
	if(memo[n+1] != 0) return memo[n] = memo[n+1] / n+1;
	return memo[n] = fat(n-1) * n;
}

int main(void){
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF){
		printf("%llu\n", fat(n) + fat(m));
	}
	return 0;
}