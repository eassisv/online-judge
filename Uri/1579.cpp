#include <stdio.h>

#define MAX 112

int N, np, nc, frete, p[MAX];

int qtdC(int pMax){
	int pAtual = 0, qtd = 1; 
	for(int i = 0; i < np; i++){
		if(p[i] + pAtual > pMax) { qtd++; pAtual = p[i]; }
		else pAtual += p[i];
	}
	return qtd;
}

int bbin(int i, int f){
	int meio;
	while(i < f){
		meio = i + (f - i)/2;
		if(nc >= qtdC(meio)) f = meio;
		else i = meio + 1;
	}
	return i;
}

int main(void){
	int i, min, max, ans;
	scanf("%d", &N);
	while(N--){
		min = max = 0;
		scanf("%d %d %d", &np, &nc, &frete);
		for(i = 0; i < np; i++){
			scanf("%d", &p[i]);
			if(p[i] > min) min = p[i];
			max += p[i];
		}
		ans = bbin(min, max);
		printf("%d $%d\n", ans, ans * nc * frete);
	}
	return 0;
}