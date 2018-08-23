#include <stdio.h>
#include <string.h>

#define MAX 112345

int N;
int bugs[MAX], pb[MAX];

void atualiza(int i, int qtd){
	for(; i < MAX; i += i & (-i)) pb[i] += qtd;
}

int calc(int i){
	int ans = 0;
	for(i--; i; i -= i & (-i)) ans += pb[i];
	return ans;
}

int main (void){
	int i;
	scanf("%d", &N);
	memset(pb, 0, sizeof(pb));
	for(i = 1; i <= N; i++){
		scanf("%d", &bugs[i]);
		atualiza(i, bugs[i]);
	}
	char c;
	while(scanf(" %c %d", &c, &i) != EOF){
		if(c == 'a') atualiza(i, -bugs[i]);
		else printf("%d\n", calc(i));
	}
	return 0;
}
