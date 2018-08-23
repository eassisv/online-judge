#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 51

int rct[MAX], dias;

int maxSeq(int n, int cst){
	int j, maxAtual, maxTotal, i, f, itemp;
	maxAtual = itemp = i = f = 0; maxTotal = -1;
	for(j = 0; j < n; j++){
		maxAtual += (rct[j] - cst);
		if(maxAtual < 0){
			maxAtual = 0;
			itemp = j+1;
		}
		if(maxAtual > maxTotal){
			maxTotal = maxAtual;
			i = itemp;
			f = j;
		}
	}
	dias = f - i + 1;
	return maxTotal;
}

int main(void){
	int N, cstDia, ans, i;
	while(scanf("%d", &N) != EOF){
		scanf("%d", &cstDia);
		for(i = 0; i < N; i++)
			scanf("%d", &rct[i]);
		dias = 0;
		ans = maxSeq(N, cstDia);
		printf("%d\n", (ans <= 0) ? 0 : ans);	
	} 	
	return 0;
}