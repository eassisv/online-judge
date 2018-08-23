#include <stdio.h>
#include <math.h>

#define MAX 112345

int primos[MAX];

void crivo(){
	int i, j;
	primos[0] = primos[1] = 1;
	for(i = 2; i < MAX; i++){
		if(primos[i]) continue;
		for(j = i + i; j < MAX; j += i)
			primos[j] = 1;
	}}

long long int fatora(long long int N){
	int cont;
	long long int i, ans;
	for(i = 0, ans = 1; i < MAX && N > 1; i++){
		if(primos[i]) continue;
		cont = 0;

		while(N % i == 0){
			N = N / i;
			cont++;
		}
		if(cont % 2 != 0) cont++;
		while(cont){
			ans *= i * i;
			cont-=2;
		}
	}
	if(N > 1) ans *= (N * N);
	return ans;
}

int main(void){
	crivo();
	int N, T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		scanf("%d", &N);
		printf("Caso #%d: %lld\n", i, fatora(N));
	}
	return 0;
}