#include<stdio.h>

int main(void){
	int N, i, x[112345], moves, aux;
	
	while (scanf("%d", &N), N){
		for(i = 1; i <= N; i++)
			scanf("%d", &x[i]);
		moves = 0;
		for(i = 1; i <= N;){
			if(x[i] != i){
				aux = x[i];
				x[i] = x[aux];
				x[aux] = aux;
				moves += (2*(aux - i) - 1);
			}
			else i++;
		}
		(moves % 2 == 0)? printf("Carlos\n") : printf("Marcelo\n");
	}
	
	return 0;
}
